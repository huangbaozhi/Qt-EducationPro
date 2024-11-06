#include "ailearningwidget.h"

#include <QGridLayout>

/**
 * @brief AiLearningWidget::AiLearningWidget
 * @param parent
 * @details Ai教学
 */

AiLearningWidget::AiLearningWidget(QWidget *parent) : QWidget(parent)
{
    initUi();
}

void AiLearningWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setMinimumSize(680, 500);
    pMainWgt->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;}");

    QGridLayout *pMainGridLyt = new QGridLayout(pMainWgt);

    setLayout(pMainGridLyt);
}
