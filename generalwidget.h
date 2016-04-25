#ifndef GENERALWIDGET_H
#define GENERALWIDGET_H

#include <QWidget>
#include <QCloseEvent>
#include "ui_generalwidget.h"

namespace Ui {
class GeneralWidget;
}

class GeneralWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GeneralWidget(QWidget *parent = 0);
    ~GeneralWidget();

signals:
void closeApplication();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    Ui::GeneralWidget *ui;
};

#endif // GENERALWIDGET_H
