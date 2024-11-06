#include "moveblewindow.h"

#include <QWidget>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QShowEvent>

MovebleWindow::MovebleWindow(QWidget *parent)
    : QObject(parent)
    , m_pWatching(parent)
    , m_bDown(false)
{
    parent->setWindowFlag(Qt::FramelessWindowHint);
    parent->installEventFilter(this);
}

bool MovebleWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == m_pWatching)
    {
        if(QEvent::MouseButtonPress     == event->type() ||
           QEvent::MouseMove            == event->type() ||
           QEvent::MouseButtonRelease   == event->type() )
        {
            QMouseEvent* pEvent = dynamic_cast<QMouseEvent*>(event);
            if(pEvent)
            {
                if(QEvent::MouseButtonPress == event->type())
                {
                    m_pos   = pEvent->globalPos();
                    m_bDown = true;
                }
                else if(QEvent::MouseMove == event->type())
                {
                    if(m_bDown && !m_pos.isNull() && pEvent->buttons().testFlag(Qt::LeftButton))
                    {
                        QPoint pt = pEvent->globalPos() -m_pos;
                        m_pWatching->move(m_pWatching->pos()+pt);
                        m_pos = pEvent->globalPos();
                    }
                    else
                    {
                        m_bDown = false;
                    }
                }
                else
                {
                    m_pos   = QPoint();
                    m_bDown = false;
                }

            }
        }
    }
    return false;
}

MovableWindow::MovableWindow(QWidget *parent)
    : QWidget(parent)
    , isWindowActive(false)
{

}

void MovableWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragPosition = event->globalPos() - frameGeometry().topLeft();
        isWindowActive = true;
    } else if (event->button() == Qt::RightButton) {
        // 可以在这里添加关闭窗口的逻辑
    }
}

void MovableWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isWindowActive && (event->buttons() && Qt::LeftButton)) {
        move(event->globalPos() - dragPosition);
    }
}
