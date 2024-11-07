#include "interactiveteachingwidget.h"
#include "headerfile.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>
#include <QSplitter>

/**
 * @brief InteractiveTeachingWidget::InteractiveTeachingWidget
 * @param parent
 * @details 互动式教学界面（InteractiveTeachingWidget）
 */

InteractiveTeachingWidget::InteractiveTeachingWidget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(1260, 775);

    initUi();
    connectFun();
}

InteractiveTeachingWidget::~InteractiveTeachingWidget()
{
}

void InteractiveTeachingWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    QHBoxLayout *pMainLyt = new QHBoxLayout(pMainWgt);


    QWidget *pLeftWgt = new QWidget(this);
    pLeftWgt->setMinimumSize(200, 735);
    pLeftWgt->setStyleSheet("QWidget{background-color: #ffffff; border: none; border-radius: 10px;}");

    QVBoxLayout *pLeftLyt = new QVBoxLayout(pLeftWgt);
    pLeftLyt->setContentsMargins(12, 14, 0, 0);

    QHBoxLayout *pCourseCenterLyt = new QHBoxLayout();
    pCourseCenterLyt->setContentsMargins(0, 0, 0, 0);
    m_pCourseCenterBtn = new QPushButton(this);
    m_pCourseCenterBtn->setText("课程中心");
    m_pCourseCenterBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/courseCenterBtn.png) center;"
                                      "qproperty-iconSize: 20px 20px;"
                                      "border: 0px;"
                                      "font-family: Microsoft YaHei;"
                                      "font-weight: 400;"
                                      "font-size: 15px;"
                                      "color: #243627;"
                                      "line-height: 38px;"
                                      "}");
    pCourseCenterLyt->addWidget(m_pCourseCenterBtn);
    pCourseCenterLyt->addStretch();

    QHBoxLayout *pDistanceLearningLyt = new QHBoxLayout();
    pDistanceLearningLyt->setContentsMargins(0, 0, 0, 0);
    m_pDistanceLearningBtn = new QPushButton(this);
    m_pDistanceLearningBtn->setText("远程教学");
    m_pDistanceLearningBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/remoteCenterBtn.png) center; "
                                          "qproperty-iconSize: 24px 24px; "
                                          "border: 0px;"
                                          "font-family: Microsoft YaHei;"
                                          "font-weight: 400;"
                                          "font-size: 15px;"
                                          "color: #243627;"
                                          "line-height: 38px;"
                                          "}");
    pDistanceLearningLyt->addWidget(m_pDistanceLearningBtn);
    pDistanceLearningLyt->addStretch();

    QHBoxLayout *pAiLearningLyt = new QHBoxLayout();
    pAiLearningLyt->setContentsMargins(0, 0, 0, 0);
    m_pAiLearningBtn = new QPushButton(this);
    m_pAiLearningBtn->setText("AI    教学");
    m_pAiLearningBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/aiLearningBtn.png) center;"
                                    "qproperty-iconSize: 24px 24px;"
                                    "border: 0px;"
                                    "font-family: Microsoft YaHei;"
                                    "font-weight: 400;"
                                    "font-size: 15px;"
                                    "color: #243627;"
                                    "line-height: 38px;"
                                    "}");
    pAiLearningLyt->addWidget(m_pAiLearningBtn);
    pAiLearningLyt->addStretch();

    QHBoxLayout *pReturnLyt = new QHBoxLayout();
    pReturnLyt->setContentsMargins(0, 0, 0, 0);
    m_pReturnBtn = new QPushButton(this);
    m_pReturnBtn->setText("返        回");
    m_pReturnBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/returnBtn.png) center;"
                                "qproperty-iconSize: 24px 24px;"
                                "border: 0px;"
                                "font-family: Microsoft YaHei;"
                                "font-weight: 400;"
                                "font-size: 15px;"
                                "color: #243627;"
                                "line-height: 38px;"
                                "}");
    pReturnLyt->addWidget(m_pReturnBtn);
    pReturnLyt->addStretch();

//    pLeftLyt->addWidget(m_pCourseCenterBtn);
//    pLeftLyt->addWidget(m_pDistanceLearningBtn);
    pLeftLyt->addLayout(pCourseCenterLyt);
    pLeftLyt->addLayout(pDistanceLearningLyt);
    pLeftLyt->addLayout(pAiLearningLyt);
    pLeftLyt->addLayout(pReturnLyt);
    pLeftLyt->addStretch();

    m_pCourseCenterWidget = new CourseCenterWidget(this);
    m_pDistanceLearningWidget = new DistanceLearningWidget(this);
    m_pAiLearningWidget = new AiLearningWidget(this);

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->addWidget(m_pCourseCenterWidget);
    m_pStackedWidget->addWidget(m_pDistanceLearningWidget);
    m_pStackedWidget->addWidget(m_pAiLearningWidget);

    pMainLyt->addWidget(pLeftWgt);
    pMainLyt->addWidget(m_pStackedWidget);
}

void InteractiveTeachingWidget::connectFun()
{
    connect(m_pReturnBtn, &QPushButton::clicked, this, &InteractiveTeachingWidget::slotReturn);

    connect(m_pCourseCenterBtn, &QPushButton::clicked, this, &InteractiveTeachingWidget::slotSwitchPage);
    connect(m_pDistanceLearningBtn, &QPushButton::clicked, this, &InteractiveTeachingWidget::slotSwitchPage);
    connect(m_pAiLearningBtn, &QPushButton::clicked, this, &InteractiveTeachingWidget::slotSwitchPage);
}

void InteractiveTeachingWidget::slotSwitchPage()
{
    QPushButton *pBtn = qobject_cast<QPushButton*>(QObject::sender());

    if (!pBtn)
    {
        return;
    }

    if (pBtn == m_pCourseCenterBtn && m_pCourseCenterWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pCourseCenterWidget);
    }
    else if (pBtn == m_pDistanceLearningBtn && m_pDistanceLearningWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pDistanceLearningWidget);
    }
    else if (pBtn == m_pAiLearningBtn && m_pAiLearningWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pAiLearningWidget);
    }
}

void InteractiveTeachingWidget::slotReturn()
{
    emit signReturn();
}
