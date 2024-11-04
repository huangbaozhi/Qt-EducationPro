#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QColor>

class PushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit PushButton(QWidget *parent = nullptr);

    explicit PushButton(const QString &style, const QString &color, const QString &text, QWidget *parent = nullptr);

    explicit PushButton(const QString &style,  QWidget *parent = nullptr);

signals:

};

#endif // PUSHBUTTON_H
