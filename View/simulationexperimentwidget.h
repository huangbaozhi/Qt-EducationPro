#ifndef SIMULATIONEXPERIMENTWIDGET_H
#define SIMULATIONEXPERIMENTWIDGET_H

#include <QWidget>

class SimulationExperimentWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SimulationExperimentWidget(QWidget *parent = nullptr);
     ~SimulationExperimentWidget();

signals:

private:
    void initUi();

};

#endif // SIMULATIONEXPERIMENTWIDGET_H
