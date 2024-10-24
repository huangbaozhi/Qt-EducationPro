#include "interactiveteachingwidget.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

/**
 * @brief InteractiveTeachingWidget::InteractiveTeachingWidget
 * @param parent
 * @details 互动式教学界面（InteractiveTeachingWidget）
 */

InteractiveTeachingWidget::InteractiveTeachingWidget(QWidget *parent)
    : QWidget(parent)
{
    resize(900, 500);

    initUi();
    connectFun();
}

InteractiveTeachingWidget::~InteractiveTeachingWidget()
{
}

void InteractiveTeachingWidget::initUi()
{
    QWidget *pLeftWgt = new QWidget(this);
    QVBoxLayout *pLeftLyt = new QVBoxLayout(pLeftWgt);
    pLeftLyt->setContentsMargins(0, 0, 0, 0);

    m_pCourseCenterBtn = new QPushButton(this);
    m_pCourseCenterBtn->setText("课程中心");
    m_pDistanceLearningBtn = new QPushButton(this);
    m_pDistanceLearningBtn->setText("远程教学");
    m_pAiLearningBtn = new QPushButton(this);
    m_pAiLearningBtn->setText("Ai教学");
    m_pReturnBtn = new QPushButton(this);
    m_pReturnBtn->setText("返   回");

    pLeftLyt->addWidget(m_pCourseCenterBtn);
    pLeftLyt->addWidget(m_pDistanceLearningBtn);
    pLeftLyt->addWidget(m_pAiLearningBtn);
    pLeftLyt->addWidget(m_pReturnBtn);
}

void InteractiveTeachingWidget::connectFun()
{
    connect(m_pReturnBtn, &QPushButton::clicked, this, &InteractiveTeachingWidget::slotReturn);
}

void InteractiveTeachingWidget::slotReturn()
{
    emit signReturn();
}
