#ifndef DISTANCELEARNINGWIDGET_H
#define DISTANCELEARNINGWIDGET_H

#include <QWidget>

class QTextEdit;
class QPushButton;

class DistanceLearningWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DistanceLearningWidget(QWidget *parent = nullptr);

signals:

private:
    void initUi();

private:
    QTextEdit *m_pEnterCommentEdit;
    QPushButton *m_pEnterCommentBtn;

};

#endif // DISTANCELEARNINGWIDGET_H
