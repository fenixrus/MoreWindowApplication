#include "secondwidget.h"
#include "ui_secondwidget.h"

SecondWidget::SecondWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SecondWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SIGNAL(clickBack()));
}

SecondWidget::~SecondWidget()
{
    delete ui;
}
