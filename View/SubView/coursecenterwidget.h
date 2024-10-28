#ifndef COURSECENTERWIDGET_H
#define COURSECENTERWIDGET_H

#include <QWidget>

class QStackedWidget;
class QMediaPlayer;
class QVideoWidget;
class QLabel;
class QPushButton;
class QSlider;


class CourseCenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CourseCenterWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    void connectFun();

private slots:
    void onVideoClicked();
    void onPlayPauseClicked();
    void onSliderMoved(int position);
    void onPositionChanged(qint64 position);
    void onDurationChanged(qint64 duration);
    void onExitClicked();

private:
    QStackedWidget *stackedWidget;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QLabel *videoLabel;
    QPushButton *playPauseButton;
    QSlider *videoSlider;
    QPushButton *exitButton;
    qint64 duration;
    bool isPlaying;


};

#endif // COURSECENTERWIDGET_H
