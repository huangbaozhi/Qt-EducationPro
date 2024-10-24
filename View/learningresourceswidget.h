#ifndef LEARNINGRESOURCESWIDGET_H
#define LEARNINGRESOURCESWIDGET_H

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>

class LearningResourcesWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LearningResourcesWidget(QWidget *parent = nullptr);
    ~LearningResourcesWidget();

signals:

private:
    void initUi();

private:
    QFileSystemModel *model;
    QTreeView *treeView;


};

#endif // LEARNINGRESOURCESWIDGET_H
