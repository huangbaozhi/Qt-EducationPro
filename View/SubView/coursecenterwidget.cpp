#include "coursecenterwidget.h"

#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>
#include <QGridLayout>

/**
 * @brief CourseCenterWidget::CourseCenterWidget
 * @param parent
 * @details 课程中心
 */

CourseCenterWidget::CourseCenterWidget(QWidget *parent)
    : QWidget(parent)
    , duration(0)
    , isPlaying(false)
{

    resize(900, 500);
    initUi();

}

void CourseCenterWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setFixedSize(900, 500);
    QGridLayout *pMainGridLyt = new QGridLayout(pMainWgt);

    QWidget *pVideo1 = new QWidget(this);
    pVideo1->setFixedSize(220, 120);
    pVideo1->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");

    QWidget *pVideo2= new QWidget(this);
    pVideo2->setFixedSize(220, 120);
    pVideo2->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");

    QWidget *pVideo3 = new QWidget(this);
    pVideo3->setFixedSize(220, 120);
    pVideo3->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");

    QWidget *pVideo4 = new QWidget(this);
    pVideo4->setFixedSize(220, 120);
    pVideo4->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");

    QWidget *pVideo5 = new QWidget(this);
    pVideo5->setFixedSize(220, 120);
    pVideo5->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");

    QWidget *pVideo6 = new QWidget(this);
    pVideo6->setFixedSize(220, 120);
    pVideo6->setStyleSheet("QWidget{background-color:red;border-radius: 10px;}");

    pMainGridLyt->addWidget(pVideo1, 1, 1);
    pMainGridLyt->addWidget(pVideo2, 1, 2);
    pMainGridLyt->addWidget(pVideo3, 1, 3);
    pMainGridLyt->addWidget(pVideo4, 2, 1);
    pMainGridLyt->addWidget(pVideo5, 2, 2);
    pMainGridLyt->addWidget(pVideo6, 2, 3);

    setLayout(pMainGridLyt);
}

void CourseCenterWidget::connectFun()
{
}

void CourseCenterWidget::onVideoClicked()
{
}

void CourseCenterWidget::onPlayPauseClicked()
{
    if (isPlaying) {
        player->pause();
        playPauseButton->setText("Play");
    } else {
        player->play();
        playPauseButton->setText("Pause");
    }
    isPlaying = !isPlaying;
}

void CourseCenterWidget::onSliderMoved(int position)
{

}

void CourseCenterWidget::onPositionChanged(qint64 position)
{

}

void CourseCenterWidget::onDurationChanged(qint64 duration)
{

}

void CourseCenterWidget::onExitClicked()
{

}
