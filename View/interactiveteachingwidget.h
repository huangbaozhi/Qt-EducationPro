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

private:
    void initUi();

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

};

#endif // INTERACTIVETEACHINGWIDGET_H
