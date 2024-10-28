#ifndef INTERACTIVETEACHINGWIDGET_H
#define INTERACTIVETEACHINGWIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>

class QLabel;
class QPushButton;
class QStackedWidget;
class DistanceLearningWidget;
class CourseCenterWidget;
class AiLearningWidget;

class InteractiveTeachingWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InteractiveTeachingWidget(QWidget *parent = nullptr);
     ~InteractiveTeachingWidget();

signals:
    void signReturn();

private:
    void initUi();
    void connectFun();

public slots:
    void slotSwitchPage();

private slots:
    void slotReturn();

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;

    QLabel *m_pTitleLbl;
    QLabel *m_pTitleSubtitleLbl;

    QPushButton *m_pCourseCenterBtn;
    QPushButton *m_pDistanceLearningBtn;
    QPushButton *m_pAiLearningBtn;
    QPushButton *m_pReturnBtn;

    DistanceLearningWidget *m_pDistanceLearningWidget;
    CourseCenterWidget *m_pCourseCenterWidget;
    AiLearningWidget *m_pAiLearningWidget;

    QStackedWidget *m_pStackedWidget;

};

#endif // INTERACTIVETEACHINGWIDGET_H
