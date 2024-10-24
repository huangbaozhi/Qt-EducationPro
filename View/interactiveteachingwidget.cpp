#include "interactiveteachingwidget.h"

#include <QLabel>

/**
 * @brief InteractiveTeachingWidget::InteractiveTeachingWidget
 * @param parent
 * @details 互动式教学界面（InteractiveTeachingWidget）
 */

InteractiveTeachingWidget::InteractiveTeachingWidget(QWidget *parent)
    : QWidget(parent)
//    , player(new QMediaPlayer)
//    , videoWidget(new QVideoWidget)
{
    resize(900, 500);
    initUi();
}

InteractiveTeachingWidget::~InteractiveTeachingWidget()
{
    delete player;
    delete videoWidget;
}

void InteractiveTeachingWidget::initUi()
{
    //this->setFixedSize(900, 500);

    QLabel *pLabel = new QLabel(this);
    pLabel->setText("互动式教学");

//    player = new QMediaPlayer(this);
//    videoWidget = new QVideoWidget(this);

//    player->setVideoOutput(videoWidget);
//    videoWidget->setGeometry(0, 0, this->width(), this->height() * 3 / 4);
//    player->setMedia(QUrl::fromLocalFile("E:\\download\\chrome\\12488852_3840_2160_30fps.mp4"));
//    //player->setMedia(QUrl::fromLocalFile("E:/download/chrome/1.mp4"));
//    player->play();
}
