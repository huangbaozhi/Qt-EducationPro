#ifndef COURSECENTERWIDGET_H
#define COURSECENTERWIDGET_H

#include <QWidget>

class CourseCenterWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CourseCenterWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:


};

#endif // COURSECENTERWIDGET_H
