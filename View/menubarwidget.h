#ifndef MENUBARWIDGET_H
#define MENUBARWIDGET_H

#include <QWidget>

class QPushButton;
class QLabel;

class MenuBarWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MenuBarWidget(QWidget *parent = nullptr);

signals:
    void signSeted();
    void signMaximizationed();
    void signMinimizationed();
    void signCloseed();

private:
    void initUi();
    void connectFun();

private:
    QPushButton *m_pCloseBtn;
    QPushButton *m_pMinBtn;
    QPushButton *m_pMaxBtn;
    QPushButton *m_pSetBtn;
    QLabel  *m_pLogoLbl;
};

#endif // MENUBARWIDGET_H
