#ifndef MOVEBLEWINDOW_H
#define MOVEBLEWINDOW_H

#include <QWidget>
#include <QObject>
#include <QPoint>
#include <QResizeEvent>
#include <QMouseEvent>

class MovebleWindow : public QObject
{
    Q_OBJECT
public:
    explicit MovebleWindow(QWidget *parent = nullptr);

signals:

public:
    bool    eventFilter(QObject *watched, QEvent *event);

protected:
    QWidget* m_pWatching;
    QPoint m_pos;				//鼠标按下时的位置
    bool   m_bDown;				//鼠标是否按下

};

class MovableWindow : public QWidget {
    Q_OBJECT

public:
    explicit MovableWindow(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private:
    QPoint dragPosition;
    bool isWindowActive;
};


#endif // MOVEBLEWINDOW_H
