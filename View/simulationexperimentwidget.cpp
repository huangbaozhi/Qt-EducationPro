#include "simulationexperimentwidget.h"

#include <QLabel>

/**
 * @brief SimulationExperimentWidget::SimulationExperimentWidget
 * @param parent
 * @details 模拟实验界面（SimulationExperimentWidget）
 */

SimulationExperimentWidget::SimulationExperimentWidget(QWidget *parent) : QWidget(parent)
{
    resize(900, 500);
    // 这里将集成物理引擎或仿真软件的代码

    initUi();
}

SimulationExperimentWidget::~SimulationExperimentWidget()
{

}

void SimulationExperimentWidget::initUi()
{
    //this->setFixedSize(900, 500);

    QLabel *pLabel = new QLabel(this);
    pLabel->setText("模拟实现");
}
