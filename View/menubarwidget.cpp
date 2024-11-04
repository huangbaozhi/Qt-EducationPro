#include "menubarwidget.h"
#include "headerfile.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

/**
 * @brief MenuBarWidget::MenuBarWidget
 * @param parent
 * @details 菜单栏
 */

MenuBarWidget::MenuBarWidget(QWidget *parent) : QWidget(parent)
{
    resize(900, 32);
    initUi();

    connectFun();
}

void MenuBarWidget::initUi()
{
    QHBoxLayout *pTopLyt = new QHBoxLayout(this);

    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setFixedSize(32, 32);
    m_pLogoLbl->setStyleSheet("QLabel{background-image: url(:/images/button/logo.png); border: 0px;}");

    m_pSetBtn = new QPushButton(this);
    m_pSetBtn->setFixedSize(32, 32);
    m_pSetBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/setBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pSetBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/setBtn.png); border: 0px;}");

    m_pMaxBtn = new QPushButton(this);
    m_pMaxBtn->setFixedSize(32, 32);
    m_pMaxBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/maximizationBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pMaxBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/maximizationBtn.png); border: 0px;}");

    m_pMinBtn = new QPushButton(this);
    m_pMinBtn->setFixedSize(32, 32);
    m_pMinBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/minimizationBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pMinBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/minimizationBtn.png); border: 0px;}");

    m_pCloseBtn = new QPushButton(this);
    m_pCloseBtn->setFixedSize(32, 32);
    m_pCloseBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/closeBtn.png) center; qproperty-iconSize: 32px 32px; border: 0px;}");
    //m_pCloseBtn->setStyleSheet("QPushButton{background-image: url(:/images/button/closeBtn.png); border: 0px;}");

    pTopLyt->addWidget(m_pLogoLbl);
    pTopLyt->addStretch();
    pTopLyt->addWidget(m_pSetBtn);
    pTopLyt->addWidget(m_pMaxBtn);
    pTopLyt->addWidget(m_pMinBtn);
    pTopLyt->addWidget(m_pCloseBtn);
}

void MenuBarWidget::connectFun()
{
    connect(m_pSetBtn, &QPushButton::clicked, this, &MenuBarWidget::signSeted);
    connect(m_pMaxBtn, &QPushButton::clicked, this, &MenuBarWidget::signMaximizationed);
    connect(m_pMinBtn, &QPushButton::clicked, this, &MenuBarWidget::signMinimizationed);
    connect(m_pCloseBtn, &QPushButton::clicked, this, &MenuBarWidget::signCloseed);
}
