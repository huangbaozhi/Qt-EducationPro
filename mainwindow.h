#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//QT_BEGIN_NAMESPACE
//namespace Ui { class MainWindow; }
//QT_END_NAMESPACE

class InteractiveTeachingWidget;
class SimulationExperimentWidget;
class OnlineTestWidget;
class LearningResourcesWidget;
class QStackedWidget;
class QPushButton;
class MenuBarWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initUi();
    void connectFun();

private slots:
    void slotSwitchPage();
    void slotReturnCurrentPage();

private:
    //Ui::MainWindow *ui;

    InteractiveTeachingWidget *m_pInteractiveTeachingWidget;    // 互动式教学
    SimulationExperimentWidget *m_pSimulationExperimentWidget;  // 模拟实验
    OnlineTestWidget *m_pOnlineTestWidget;                      // 在线学习
    LearningResourcesWidget *m_pLearningResourcesWidget;        // 学习资源管理

    MenuBarWidget *m_pMenuBarWidget;

    QStackedWidget *m_pStackedWidget;
    QPushButton *m_pInteractiveTeachingBtn;
    QPushButton *m_pSimulationExperimentBtn;
    QPushButton *m_pOnlineTestBtn;
    QPushButton *m_pLearningResourcesBtn;

    QWidget *m_pBtnWgt;

};
#endif // MAINWINDOW_H
