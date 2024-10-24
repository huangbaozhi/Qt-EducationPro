#include "onlinetestwidget.h"
#include <QLabel>

/**
 * @brief OnlineTestWidget::OnlineTestWidget
 * @param parent
 * @details 在线测试界面（OnlineTestWidget）
 */

OnlineTestWidget::OnlineTestWidget(QWidget *parent) : QWidget(parent)
{
    resize(900, 500);
    initUi();
    loadQuestions();
    nextQuestion();
}

OnlineTestWidget::~OnlineTestWidget()
{

}

void OnlineTestWidget::initUi()
{
    //this->setFixedSize(900, 500);

    QLabel *pLabel = new QLabel(this);
    pLabel->setText("在线测试");

    questionList = new QListWidget(this);
    questionStack = new QStackedLayout(this);

}

void OnlineTestWidget::loadQuestions()
{
    // 这里将加载题目数据
    // 示例：questionList->addItem("你最喜欢的编程语言是什么？");
}

void OnlineTestWidget::nextQuestion()
{
    // 这里将显示下一个问题
}

void OnlineTestWidget::checkAnswer()
{
     // 这里将检查答案并给出评分
}
