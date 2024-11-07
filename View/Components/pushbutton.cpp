#include "pushbutton.h"

PushButton::PushButton(QWidget *parent) : QPushButton(parent)
{

}

PushButton::PushButton(const QString &style, const QString &color, const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    QColor darkerColor = QColor(color).darker(150);
    QColor lighterColor = QColor(color).lighter(150);

    QString styleSheet = QString(R"(
        PushButton {
            background-image: url(%1);
            background-color: %2;
            border: none;
            border-radius: %3px; /* 圆形 */
            font-family: PingFangSC-regular;
            border: 1px solid rgba(187,187,187,1);
            line-height: 50px;
            color: rgba(255,255,255,0.94);
            font-size: 36px;
            text-align: center;
            font-family: SourceHanSansSC-regular;
        }
        PushButton:pressed {
            background-color: %4; /* 按下时的颜色，稍微深一点 */
        }
        PushButton:hover {
            background-color: %5; /* 鼠标悬停时的颜色，稍微浅一点 */
        }
    )").arg(style).arg(color).arg(10).arg(darkerColor.name()).arg(lighterColor.name());

    setStyleSheet(styleSheet);
}

PushButton::PushButton(const QString &style, QWidget *parent)
{
    QString styleSheet = QString(R"(
        PushButton {
            background-image: url(:/images/button/closeBtn.png);
            background-color: %2;
            border: none;
            border-radius: 5px;
        }
        PushButton:pressed {
            background-color: %4;
        }
        PushButton:hover {
            background-color: %5;
        }
    )").arg(style);

    setStyleSheet(styleSheet);
}
