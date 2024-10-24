#include "pushbutton.h"

PushButton::PushButton(QWidget *parent) : QPushButton(parent)
{

}

PushButton::PushButton(const QString &color, const QString &text, QWidget *parent) : QPushButton(text, parent)
{
    QColor darkerColor = QColor(color).darker(150);
    QColor lighterColor = QColor(color).lighter(150);

    QString styleSheet = QString(R"(
        PushButton {
            background-color: %1;
            border: none;
            border-radius: %2px; /* 圆形 */
        }
        PushButton:pressed {
            background-color: %3; /* 按下时的颜色，稍微深一点 */
        }
        PushButton:hover {
            background-color: %4; /* 鼠标悬停时的颜色，稍微浅一点 */
        }
    )").arg(color).arg(50).arg(darkerColor.name()).arg(lighterColor.name());

    setStyleSheet(styleSheet);
}
