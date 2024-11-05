#include "mainwindow.h"

#include "headerfile.h"

#include <QStackedWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(900, 600);
    setStyleSheet("background-color:#E0E6F6;");

    initUi();
    connectFun();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setFixedSize(900, 600);
    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pBtnWgt = new QWidget();
    m_pBtnWgt = pBtnWgt;
    pBtnWgt->setFixedSize(900, 567);
    QGridLayout *pGridLyt = new QGridLayout(pBtnWgt);
    pGridLyt->setContentsMargins(0, 0, 0, 0);

    m_pInteractiveTeachingBtn = new PushButton("", "#ffc0cb", "Pink", this);
    m_pInteractiveTeachingBtn->setText("互动式教学");

    m_pSimulationExperimentBtn = new PushButton("", "#ffff00", "Yellow", this);
    m_pSimulationExperimentBtn->setText("模拟实验");

    m_pOnlineTestBtn = new PushButton("", "#0000ff", "Blue", this);
    m_pOnlineTestBtn->setText("在线测试");

    m_pLearningResourcesBtn = new PushButton("", "#008000", "Green", this);
    m_pLearningResourcesBtn->setText("学习资源管理");

    m_pInteractiveTeachingBtn->setFixedSize(250, 250); // 设置固定尺寸
    m_pSimulationExperimentBtn->setFixedSize(200, 200);
    m_pOnlineTestBtn->setFixedSize(150, 150);
    m_pLearningResourcesBtn->setFixedSize(100, 100);

    pGridLyt->addWidget(m_pInteractiveTeachingBtn, 1, 0);
    pGridLyt->addWidget(m_pSimulationExperimentBtn, 1, 1);
    pGridLyt->addWidget(m_pOnlineTestBtn, 1, 2);
    pGridLyt->addWidget(m_pLearningResourcesBtn, 1, 3);

    m_pInteractiveTeachingWidget = new InteractiveTeachingWidget(this);
    m_pSimulationExperimentWidget = new SimulationExperimentWidget(this);
    m_pOnlineTestWidget = new OnlineTestWidget(this);
    m_pLearningResourcesWidget = new LearningResourcesWidget(this);

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->addWidget(pBtnWgt);
    m_pStackedWidget->addWidget(m_pInteractiveTeachingWidget);
    m_pStackedWidget->addWidget(m_pSimulationExperimentWidget);
    m_pStackedWidget->addWidget(m_pOnlineTestWidget);
    m_pStackedWidget->addWidget(m_pLearningResourcesWidget);

    // 标题栏
    m_pMenuBarWidget = new MenuBarWidget(this);

    pMainLyt->addWidget(m_pMenuBarWidget);
    pMainLyt->addWidget(m_pStackedWidget);
    pMainLyt->addStretch();
}

void MainWindow::connectFun()
{
    connect(m_pMenuBarWidget, &MenuBarWidget::signCloseed, this, &MainWindow::close);

    connect(m_pInteractiveTeachingBtn, &QPushButton::clicked, this, &MainWindow::slotSwitchPage);
    connect(m_pSimulationExperimentBtn, &QPushButton::clicked, this, &MainWindow::slotSwitchPage);
    connect(m_pOnlineTestBtn, &QPushButton::clicked, this, &MainWindow::slotSwitchPage);
    connect(m_pLearningResourcesBtn, &QPushButton::clicked, this, &MainWindow::slotSwitchPage);

    connect(m_pInteractiveTeachingWidget, &InteractiveTeachingWidget::signReturn, this, &MainWindow::slotReturnCurrentPage);
}

void MainWindow::slotSwitchPage()
{
    QPushButton *pBtn = qobject_cast<QPushButton*>(QObject::sender());

    if (!pBtn)
    {
        return;
    }

    if (pBtn == m_pInteractiveTeachingBtn && m_pInteractiveTeachingWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pInteractiveTeachingWidget);
    }
    else if (pBtn == m_pSimulationExperimentBtn && m_pSimulationExperimentWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pSimulationExperimentWidget);
    }
    else if (pBtn == m_pOnlineTestBtn && m_pOnlineTestWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pOnlineTestWidget);
    }
    else if (pBtn == m_pLearningResourcesBtn && m_pLearningResourcesWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pLearningResourcesWidget);
    }
}

void MainWindow::slotReturnCurrentPage()
{
    m_pStackedWidget->setCurrentWidget(m_pBtnWgt);
}

