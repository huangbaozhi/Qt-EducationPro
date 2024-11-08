#include "coursecenterwidget.h"
#include "headerfile.h"

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
    initUi();
}

void CourseCenterWidget::initUi()
{
    QWidget *pMainWgt = new QWidget(this);
    pMainWgt->setMinimumSize(1000, 735);
    QGridLayout *pMainGridLyt = new QGridLayout(pMainWgt);
    pMainGridLyt->setContentsMargins(30, 30, 30, 30);


    QWidget *pVideo1 = new VideoCoverWidget(this);
    pVideo1->setFixedSize(500, 400);
    pVideo1->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;border: 1px solid rgba(187,187,187,1);}");

//    QWidget *pVideo2= new QWidget(this);
//    pVideo2->setFixedSize(300, 200);
//    pVideo2->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;border: 1px solid rgba(187,187,187,1);}");

//    QWidget *pVideo3 = new QWidget(this);
//    //pVideo3->hide();
//    pVideo3->setMinimumSize(300, 200);
//    pVideo3->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;border: 1px solid rgba(187,187,187,1);}");

//    QWidget *pVideo4 = new QWidget(this);
//    pVideo4->setMinimumSize(300, 200);
//    pVideo4->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;border: 1px solid rgba(187,187,187,1);}");

//    QWidget *pVideo5 = new QWidget(this);
//    pVideo5->setMinimumSize(300, 200);
//    pVideo5->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;border: 1px solid rgba(187,187,187,1);}");

//    QWidget *pVideo6 = new QWidget(this);
//    //pVideo6->hide();
//    pVideo6->setMinimumSize(300, 200);
//    pVideo6->setStyleSheet("QWidget{background-color:#ffffff;border-radius: 10px;border: 1px solid rgba(187,187,187,1);}");

    pMainGridLyt->addWidget(pVideo1, 1, 1);
//    pMainGridLyt->addWidget(pVideo2, 1, 2);
//    pMainGridLyt->addWidget(pVideo3, 1, 3);
//    pMainGridLyt->addWidget(pVideo4, 2, 1);
//    pMainGridLyt->addWidget(pVideo5, 2, 2);
//    pMainGridLyt->addWidget(pVideo6, 2, 3);

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
