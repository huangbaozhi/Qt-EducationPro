#ifndef ONLINETESTWIDGET_H
#define ONLINETESTWIDGET_H

#include <QWidget>
#include <QListWidget>
#include <QStackedLayout>

class OnlineTestWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OnlineTestWidget(QWidget *parent = nullptr);
    ~OnlineTestWidget();

signals:

private:
    void initUi();
    void loadQuestions();
    void nextQuestion();
    void checkAnswer();

private:
    QListWidget *questionList;
    QStackedLayout *questionStack;
    int currentQuestionIndex;

};

#endif // ONLINETESTWIDGET_H
