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

private:
    void initUi();

private:
    QPushButton *m_pCloseBtn;
    QPushButton *m_pMinBtn;
    QPushButton *m_pMaxBtn;
    QPushButton *m_pSetBtn;
    QLabel  *m_pLogoLbl;
};

#endif // MENUBARWIDGET_H
