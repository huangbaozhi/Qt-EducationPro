#include "learningresourceswidget.h"
#include <QLabel>

/**
 * @brief LearningResourcesWidget::LearningResourcesWidget
 * @param parent
 * @details 学习资源管理界面（LearningResourcesWidget）
 */

LearningResourcesWidget::LearningResourcesWidget(QWidget *parent) : QWidget(parent)
{
    resize(900, 500);
    initUi();
}

LearningResourcesWidget::~LearningResourcesWidget()
{

}

void LearningResourcesWidget::initUi()
{
    //this->setFixedSize(900, 500);

    QLabel *pLabel = new QLabel(this);
    pLabel->setText("学习资源管理");

    model = new QFileSystemModel(this);
    model->setRootPath("/");
    treeView = new QTreeView(this);
    treeView->setModel(model);
    treeView->setGeometry(0, 0, this->width(), this->height());
}
