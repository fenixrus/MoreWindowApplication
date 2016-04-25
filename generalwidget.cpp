#include "generalwidget.h"

GeneralWidget::GeneralWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneralWidget)
{
    ui->setupUi(this);
}

GeneralWidget::~GeneralWidget()
{
    delete ui;
}

void GeneralWidget::closeEvent(QCloseEvent *e)
{
    emit this->closeApplication();
    e->accept();
}
