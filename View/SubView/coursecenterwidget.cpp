#include "coursecenterwidget.h"

#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include <QPushButton>
#include <QSlider>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QVBoxLayout>

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

    //resize(900, 500);

}

void CourseCenterWidget::initUi()
{
    // 初始化视频播放起和视频显示组件
    player = new QMediaPlayer(this);
    videoWidget = new QVideoWidget(this);
    player->setVideoOutput(videoWidget);

    // 初始化视频封面和标题显示
    videoLabel = new QLabel(this);
    //videoLabel->setStyleSheet("QLabel{background-color:red;}");
    videoLabel->setAlignment(Qt::AlignCenter);
    videoLabel->setFixedSize(640, 360);

    // 初始化播放/暂停播放
    playPauseButton = new QPushButton("Play", this);

    // 初始化退出按钮
    exitButton = new QPushButton("Exit", this);

    // 初始化进度条
    videoSlider = new QSlider(Qt::Horizontal, this);
    videoSlider->setRange(0, 0);

    // 布局设置
    QWidget *pMainLyt = new QWidget(this);
    pMainLyt->setFixedSize(900, 500);
    QVBoxLayout *mainLayout = new QVBoxLayout(pMainLyt);
    mainLayout->addWidget(videoLabel);
    mainLayout->addWidget(playPauseButton);
    mainLayout->addWidget(videoSlider);
    mainLayout->addWidget(exitButton);
    setLayout(mainLayout);
}

void CourseCenterWidget::connectFun()
{
    connect(playPauseButton, &QPushButton::clicked, this, &CourseCenterWidget::onPlayPauseClicked);
    connect(exitButton, &QPushButton::clicked, this, &CourseCenterWidget::onExitClicked);
    connect(videoSlider, &QSlider::sliderMoved, this, &CourseCenterWidget::onSliderMoved);
    connect(player, &QMediaPlayer::positionChanged, this, &CourseCenterWidget::onPositionChanged);
    connect(player, &QMediaPlayer::durationChanged, this, &CourseCenterWidget::onDurationChanged);
}

void CourseCenterWidget::onVideoClicked()
{
    // 设置视频源并显示视频封面
    QString videoPath = "E:/download/chrome/12488852_3840_2160_30fps.mp4"; // 替换为视频文件路径
    player->setMedia(QUrl::fromLocalFile(videoPath));
    videoLabel->setPixmap(QPixmap("C:/Users/Admin/Pictures/Saved Pictures/11.jpg")); // 替换为视频封面路径
    stackedWidget->setCurrentIndex(1); // 显示视频播放界面
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
    player->setPosition(position);
}

void CourseCenterWidget::onPositionChanged(qint64 position)
{
    videoSlider->setValue(position);
}

void CourseCenterWidget::onDurationChanged(qint64 duration)
{
    this->duration = duration;
    videoSlider->setRange(0, duration);
}

void CourseCenterWidget::onExitClicked()
{
    player->stop();
    videoLabel->clear();
    stackedWidget->setCurrentIndex(0); // 返回到视频封面界面
}
