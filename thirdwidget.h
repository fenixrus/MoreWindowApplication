#ifndef THIRDWIDGET_H
#define THIRDWIDGET_H

#include <QWidget>

namespace Ui {
class ThirdWidget;
}

class ThirdWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ThirdWidget(QWidget *parent = 0);
    ~ThirdWidget();
signals:
    void clickBack();

private:
    Ui::ThirdWidget *ui;
};

#endif // THIRDWIDGET_H
