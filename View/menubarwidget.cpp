#include "menubarwidget.h"
#include "headerfile.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QImage>

/**
 * @brief MenuBarWidget::MenuBarWidget
 * @param parent
 * @details 菜单栏
 */

MenuBarWidget::MenuBarWidget(QWidget *parent) : QWidget(parent)
{
    initUi();
    connectFun();
}

void MenuBarWidget::initUi()
{
    QWidget *pTopWgt = new QWidget(this);
    pTopWgt->setMinimumSize(900, 45);
    pTopWgt->setStyleSheet("background-color:#bea7cf;border: none;");
    QHBoxLayout *pTopLyt = new QHBoxLayout(pTopWgt);
    pTopLyt->setContentsMargins(0, 0, 0, 0);

    QImage *imgLogo = new QImage(":/images/LOGO.png");
    //imgLogo->load(":/images/LOGO.jpg");

    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setFixedSize(42, 42);
    m_pLogoLbl->setStyleSheet("QLabel{background-color:#bea7cf; border: 0px;}");
    imgLogo->scaled(m_pLogoLbl->size(), Qt::KeepAspectRatio);
    m_pLogoLbl->setScaledContents(true);
    m_pLogoLbl->setPixmap(QPixmap::fromImage(*imgLogo));

    m_pSetBtn = new QPushButton(this);
    m_pSetBtn->setMinimumSize(32, 32);
    m_pSetBtn->setStyleSheet("QPushButton{background-color:#bea7cf;qproperty-icon: url(:/images/button/setBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pSetBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/setBtn.png); border: 0px;}");

    m_pMaxBtn = new QPushButton(this);
    m_pMaxBtn->setMinimumSize(32, 32);
    m_pMaxBtn->setStyleSheet("QPushButton{background-color:#bea7cf;qproperty-icon: url(:/images/button/maximizationBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pMaxBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/maximizationBtn.png); border: 0px;}");

    m_pMinBtn = new QPushButton(this);
    m_pMinBtn->setMinimumSize(32, 32);
    m_pMinBtn->setStyleSheet("QPushButton{background-color:#bea7cf;qproperty-icon: url(:/images/button/minimizationBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pMinBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/minimizationBtn.png); border: 0px;}");

    m_pCloseBtn = new QPushButton(this);
    m_pCloseBtn->setMinimumSize(32, 32);
    m_pCloseBtn->setStyleSheet("QPushButton{background-color:#bea7cf;qproperty-icon: url(:/images/button/closeBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pCloseBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/closeBtn.png); border: 0px;}");

    pTopLyt->addWidget(m_pLogoLbl);
    pTopLyt->addStretch();
    pTopLyt->addWidget(m_pSetBtn);
    pTopLyt->addWidget(m_pMaxBtn);
    pTopLyt->addWidget(m_pMinBtn);
    pTopLyt->addWidget(m_pCloseBtn);

    setLayout(pTopLyt);
}

void MenuBarWidget::connectFun()
{
    connect(m_pSetBtn, &QPushButton::clicked, this, &MenuBarWidget::signSeted);
    connect(m_pMaxBtn, &QPushButton::clicked, this, &MenuBarWidget::signMaximizationed);
    connect(m_pMinBtn, &QPushButton::clicked, this, &MenuBarWidget::signMinimizationed);
    connect(m_pCloseBtn, &QPushButton::clicked, this, &MenuBarWidget::signCloseed);
}
