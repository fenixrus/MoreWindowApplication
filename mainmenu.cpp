#include "mainmenu.h"
#include "ui_mainmenu.h"

MainMenu::MainMenu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SIGNAL(clickButton1()));
    connect(ui->pushButton_2, SIGNAL(clicked()),
            this, SIGNAL(clickButton2()));
}

MainMenu::~MainMenu()
{
    delete ui;
}
