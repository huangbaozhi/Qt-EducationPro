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
    //resize(900, 600);
    setMinimumSize(900, 600);
    setStyleSheet("background-color: #e4e4e4;");
    initUi();
    connectFun();
}

MainWindow::~MainWindow()
{

}

void MainWindow::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setMinimumSize(900, 600);
    pMainWgt->setWindowFlags(Qt::FramelessWindowHint); // 设置窗口无边框
    pMainWgt->setAttribute(Qt::WA_TranslucentBackground); // 设置窗口背景透明
    (void)new MovebleWindow(this);

    pMainWgt->setStyleSheet("QWidget { "
                        "border: 1px solid transparent;"
                        "background-color: transparent;"
                        "}");

    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pBtnWgt = new QWidget();
    m_pBtnWgt = pBtnWgt;
    pBtnWgt->setMinimumSize(900, 567);
    QGridLayout *pGridLyt = new QGridLayout(pBtnWgt);
    pGridLyt->setContentsMargins(0, 0, 0, 0);

    m_pInteractiveTeachingBtn = new PushButton("", "#8c66ac", "Pink", this);
    m_pInteractiveTeachingBtn->setText("互动式教学");

    m_pSimulationExperimentBtn = new PushButton("", "#9d7cb8", "Yellow", this);
    m_pSimulationExperimentBtn->setText("模拟实验");

    m_pOnlineTestBtn = new PushButton("", "#ad92c4", "Blue", this);
    m_pOnlineTestBtn->setText("在线测试");

    m_pLearningResourcesBtn = new PushButton("", "#bda7d0", "Green", this);
    m_pLearningResourcesBtn->setText("学习资源管理");

    m_pInteractiveTeachingBtn->setMinimumSize(250, 250);
    m_pInteractiveTeachingBtn->setMaximumSize(250, 250);
    m_pSimulationExperimentBtn->setMinimumSize(200, 200);
    m_pSimulationExperimentBtn->setMaximumSize(200, 200);
    m_pOnlineTestBtn->setMinimumSize(150, 150);
    m_pOnlineTestBtn->setMaximumSize(150, 150);
    m_pLearningResourcesBtn->setMinimumSize(100, 100);
    m_pLearningResourcesBtn->setMaximumSize(100, 100);

    pGridLyt->addWidget(m_pInteractiveTeachingBtn, 1, 0);
    pGridLyt->addWidget(m_pSimulationExperimentBtn, 1, 1);
    pGridLyt->addWidget(m_pOnlineTestBtn, 1, 2);
    pGridLyt->addWidget(m_pLearningResourcesBtn, 1, 3);

    m_pInteractiveTeachingWidget = new InteractiveTeachingWidget(this);
    m_pSimulationExperimentWidget = new SimulationExperimentWidget(this);
    m_pOnlineTestWidget = new OnlineTestWidget(this);
    m_pLearningResourcesWidget = new LearningResourcesWidget(this);

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->setStyleSheet("QStackedWidget{border: none;}");
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

