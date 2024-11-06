#include "distancelearningwidget.h"

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>

/**
 * @brief DistanceLearningWidget::DistanceLearningWidget
 * @param parent
 * @details 远程教学
 */

DistanceLearningWidget::DistanceLearningWidget(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void DistanceLearningWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    QGridLayout *pMainGridLyt = new QGridLayout(pMainWgt);
    pMainGridLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pRemoteInterfaceWgt = new QWidget(this);
    pRemoteInterfaceWgt->setMinimumSize(450, 440);
    pRemoteInterfaceWgt->setMaximumSize(450, 440);
    pRemoteInterfaceWgt->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;}");

    QWidget *pCommentsPreviewWgt = new QWidget(this);
    pCommentsPreviewWgt->setMinimumSize(200, 440);
    pCommentsPreviewWgt->setMaximumSize(200, 440);
    pCommentsPreviewWgt->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;}");

    m_pEnterCommentEdit = new QTextEdit(this);
    m_pEnterCommentEdit->setMinimumSize(450, 50);
    m_pEnterCommentEdit->setMaximumSize(450, 50);
    m_pEnterCommentEdit->setStyleSheet("QTextEdit{background-color:#ffffff;border-radius: 10px;}");

    m_pEnterCommentBtn = new QPushButton(this);
    m_pEnterCommentBtn->setMinimumSize(200, 50);
    m_pEnterCommentBtn->setMaximumSize(200, 50);
    m_pEnterCommentBtn->setStyleSheet("QPushButton{background-color:#ffffff;border-radius: 10px;}");

    pMainGridLyt->addWidget(pRemoteInterfaceWgt, 1, 1);
    pMainGridLyt->addWidget(pCommentsPreviewWgt, 1, 2);
    pMainGridLyt->addWidget(m_pEnterCommentEdit, 2, 1);
    pMainGridLyt->addWidget(m_pEnterCommentBtn, 2, 2);

}
