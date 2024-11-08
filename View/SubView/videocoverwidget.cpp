#include "videocoverwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>

/**
 * @brief VideoCoverWidget::VideoCoverWidget
 * @param parent
 * @details 视频封面
 */

VideoCoverWidget::VideoCoverWidget(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void VideoCoverWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setFixedSize(500, 400);
    QVBoxLayout *pMainLyt = new QVBoxLayout(pMainWgt);
    pMainLyt->setContentsMargins(0, 0, 0, 0);

    QWidget *pVideoWgt = new QWidget(this);
    pVideoWgt->setFixedSize(500, 300);
    QVBoxLayout *pVideoLyt = new QVBoxLayout(pVideoWgt);

    QHBoxLayout *pBottomLyt = new QHBoxLayout();
    pBottomLyt->setContentsMargins(10, 10, 10, 10);

    m_pPlayBrowseLbl = new QLabel(this);
    m_pBulletScreenLbl = new QLabel(this);
    m_pDurationLbl = new QLabel(this);
    pBottomLyt->addWidget(m_pPlayBrowseLbl);
    pBottomLyt->addWidget(m_pBulletScreenLbl);
    pBottomLyt->addStretch();
    pBottomLyt->addWidget(m_pDurationLbl);

    m_pTitleLbl = new QLabel(this);
    m_pTitleLbl->setText("标题");
    m_pTitleLbl->setFixedSize(500, 65);

    pVideoLyt->addStretch();
    pVideoLyt->addLayout(pBottomLyt);

    pMainLyt->addWidget(pVideoWgt);
    pMainLyt->addWidget(m_pTitleLbl);
    pMainLyt->addStretch();
}
