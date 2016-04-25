#include "thirdwidget.h"
#include "ui_thirdwidget.h"

ThirdWidget::ThirdWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ThirdWidget)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()),
            this, SIGNAL(clickBack()));
}

ThirdWidget::~ThirdWidget()
{
    delete ui;
}
