#include "menubarwidget.h"

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
}

void MenuBarWidget::initUi()
{
    QHBoxLayout *pTopLyt = new QHBoxLayout(this);

    m_pLogoLbl = new QLabel(this);
    m_pLogoLbl->setText("logo");
    m_pSetBtn = new QPushButton(this);
    m_pSetBtn->setText("set");
    m_pMaxBtn = new QPushButton(this);
    m_pMinBtn = new QPushButton(this);
    m_pCloseBtn = new QPushButton(this);

    pTopLyt->addWidget(m_pLogoLbl);
    pTopLyt->addStretch();
    pTopLyt->addWidget(m_pSetBtn);
    pTopLyt->addWidget(m_pMaxBtn);
    pTopLyt->addWidget(m_pMinBtn);
    pTopLyt->addWidget(m_pCloseBtn);
}
