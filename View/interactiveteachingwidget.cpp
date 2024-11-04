#include "interactiveteachingwidget.h"
#include "headerfile.h"

#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStackedWidget>

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
    QWidget *pMainWgt = new QWidget(this);
    QHBoxLayout *pMainLyt = new QHBoxLayout(pMainWgt);


    QWidget *pLeftWgt = new QWidget(this);
    QVBoxLayout *pLeftLyt = new QVBoxLayout(pLeftWgt);
    pLeftLyt->setContentsMargins(0, 0, 0, 0);

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

    m_pAiLearningBtn = new QPushButton(this);
    m_pAiLearningBtn->setText("A I   教学");
    m_pAiLearningBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/aiLearningBtn.png) center;"
                                    "qproperty-iconSize: 24px 24px;"
                                    "border: 0px;"
                                    "font-family: Microsoft YaHei;"
                                    "font-weight: 400;"
                                    "font-size: 15px;"
                                    "color: #243627;"
                                    "line-height: 38px;"
                                    "}");

    m_pReturnBtn = new QPushButton(this);
    m_pReturnBtn->setText("返       回");
    m_pReturnBtn->setStyleSheet("QPushButton{qproperty-icon: url(:/images/button/returnBtn.png) center;"
                                "qproperty-iconSize: 24px 24px;"
                                "border: 0px;"
                                "font-family: Microsoft YaHei;"
                                "font-weight: 400;"
                                "font-size: 15px;"
                                "color: #243627;"
                                "line-height: 38px;"
                                "}");

    pLeftLyt->addWidget(m_pCourseCenterBtn);
    pLeftLyt->addWidget(m_pDistanceLearningBtn);
    pLeftLyt->addWidget(m_pAiLearningBtn);
    pLeftLyt->addWidget(m_pReturnBtn);
    pLeftLyt->addStretch();

    m_pCourseCenterWidget = new CourseCenterWidget(this);
    m_pDistanceLearningWidget = new DistanceLearningWidget(this);
    m_pAiLearningWidget = new AiLearningWidget(this);

    m_pStackedWidget = new QStackedWidget(this);
    m_pStackedWidget->addWidget(m_pDistanceLearningWidget);
    m_pStackedWidget->addWidget(m_pCourseCenterWidget);
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
    else if (pBtn == m_pReturnBtn && m_pAiLearningWidget)
    {
        m_pStackedWidget->setCurrentWidget(m_pAiLearningWidget);
    }
}

void InteractiveTeachingWidget::slotReturn()
{
    emit signReturn();
}
