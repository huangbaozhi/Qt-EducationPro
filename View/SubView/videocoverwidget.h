#ifndef VIDEOCOVERWIDGET_H
#define VIDEOCOVERWIDGET_H

#include <QWidget>

class QLabel;

class VideoCoverWidget : public QWidget
{
    Q_OBJECT
public:
    explicit VideoCoverWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();
    
private:
    QLabel *m_pPlayBrowseLbl;
    QLabel *m_pBulletScreenLbl;
    QLabel *m_pDurationLbl;
    QLabel *m_pTitleLbl;

};

#endif // VIDEOCOVERWIDGET_H
