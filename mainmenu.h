#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = 0);
    ~MainMenu();
signals:
    void clickButton1();
    void clickButton2();
private:
    Ui::MainMenu *ui;
};

#endif // MAINMENU_H
