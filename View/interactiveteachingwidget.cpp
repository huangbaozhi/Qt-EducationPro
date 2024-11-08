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
    m_pCourseCenterBtn->setFixedSize(172, 42);
    m_pCourseCenterBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/read.png);"
                                      "qproperty-iconSize: 32px 32px;"
                                      "padding-left: 9px;"
                                      "line-height: 20px;"
                                      "border-radius: 10px;"
                                      "background-color: rgba(255,255,255,0.94);"
                                      "color: rgba(16,16,16,1);"
                                      "font-size: 14px;"
                                      "text-align: center;"
                                      "font-family: PingFangSC-regular;"
                                      "border: 1px solid rgba(187,187,187,1);"
                                      "}");
    pCourseCenterLyt->addWidget(m_pCourseCenterBtn);
    pCourseCenterLyt->addStretch();

    QHBoxLayout *pDistanceLearningLyt = new QHBoxLayout();
    pDistanceLearningLyt->setContentsMargins(0, 0, 0, 0);
    m_pDistanceLearningBtn = new QPushButton(this);
    m_pDistanceLearningBtn->setText("远程教学");
    m_pDistanceLearningBtn->setFixedSize(172, 42);
    m_pDistanceLearningBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/remoteCenterBtn.png) left; "
                                          "qproperty-iconSize: 32px 32px; "
                                          "border: 0px;"
                                          "padding-left: 0px;"
                                          "line-height: 20px;"
                                          "border-radius: 10px;"
                                          "background-color: rgba(255,255,255,0.94);"
                                          "color: rgba(16,16,16,1);"
                                          "font-size: 14px;"
                                          "text-align: center;"
                                          "font-family: PingFangSC-regular;"
                                          "border: 1px solid rgba(187,187,187,1);"
                                          "}");
    pDistanceLearningLyt->addWidget(m_pDistanceLearningBtn);
    pDistanceLearningLyt->addStretch();

    QHBoxLayout *pAiLearningLyt = new QHBoxLayout();
    pAiLearningLyt->setContentsMargins(0, 0, 0, 0);
    m_pAiLearningBtn = new QPushButton(this);
    m_pAiLearningBtn->setText("AI  搜索");
    m_pAiLearningBtn->setFixedSize(172, 42);
    m_pAiLearningBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/aiLearningBtn.png);"
                                    "qproperty-iconSize: 32px 32px;"
                                    "border: 0px;"
                                    "padding-left: 0px;"
                                    "line-height: 20px;"
                                    "border-radius: 10px;"
                                    "background-color: rgba(255,255,255,0.94);"
                                    "color: rgba(16,16,16,1);"
                                    "font-size: 14px;"
                                    "text-align: center;"
                                    "font-family: PingFangSC-regular;"
                                    "border: 1px solid rgba(187,187,187,1);"
                                    "}"
                                    "QPushButton:checked{"
                                    "padding-left: 9px;"
                                    "line-height: 20px;"
                                    "border-radius: 10px;"
                                    "background-color: rgba(206,189,219,1);"
                                    "color: rgba(16,16,16,1);"
                                    "font-size: 14px;"
                                    "text-align: center;"
                                    "font-family: PingFangSC-regular;"
                                    "border: 1px solid rgba(187,187,187,1);"
                                    "}");

    pAiLearningLyt->addWidget(m_pAiLearningBtn);
    pAiLearningLyt->addStretch();

    QHBoxLayout *pReturnLyt = new QHBoxLayout();
    pReturnLyt->setContentsMargins(0, 0, 0, 0);
    m_pReturnBtn = new QPushButton(this);
    m_pReturnBtn->setText("回到首页");
    m_pReturnBtn->setFixedSize(172, 42);
    m_pReturnBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/returnBtn.png);"
                                "qproperty-iconSize: 32px 32px;"
                                "border: 0px;"
                                "padding-left: 9px;"
                                "line-height: 20px;"
                                "border-radius: 10px;"
                                "background-color: rgba(255,255,255,0.94);"
                                "color: rgba(16,16,16,1);"
                                "font-size: 14px;"
                                "text-align: center;"
                                "font-family: PingFangSC-regular;"
                                "border: 1px solid rgba(187,187,187,1);"
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

    QWidget *pRightWgt = new QWidget(this);
    m_pStackedWidget = new QStackedWidget(pRightWgt);
    pRightWgt->setFixedSize(1000, 735);
    pRightWgt->setStyleSheet("QWidget { "
                                    "border-radius: 10px;"
                                    "background-color: rgba(255,255,255,1);"
                                    "border: 0px solid rgba(187,187,187,1);"
                                    "}");
    m_pStackedWidget->addWidget(m_pCourseCenterWidget);
    m_pStackedWidget->addWidget(m_pDistanceLearningWidget);
    m_pStackedWidget->addWidget(m_pAiLearningWidget);

    pMainLyt->addWidget(pLeftWgt);
    //pMainLyt->addWidget(m_pStackedWidget);
    pMainLyt->addWidget(pRightWgt);
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
