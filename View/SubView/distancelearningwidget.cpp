#include "distancelearningwidget.h"

#include <QGridLayout>

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

    QWidget *pRemoteInterfaceWgt = new QWidget(this);
    pRemoteInterfaceWgt->setFixedSize(300, 300);
    pRemoteInterfaceWgt->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");


}
