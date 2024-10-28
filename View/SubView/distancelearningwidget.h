#ifndef DISTANCELEARNINGWIDGET_H
#define DISTANCELEARNINGWIDGET_H

#include <QWidget>

class DistanceLearningWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DistanceLearningWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

};

#endif // DISTANCELEARNINGWIDGET_H
