#include "controlviewwidget.h"//Подключение заголовочного файла

ControlViewWidget::ControlViewWidget(QObject *parent) : QObject(parent)
{
    this->lastWidget = nullptr;//Обнуление указателя на последний виджет(системная переменная)

    //Список обнуления указателей на виджеты
    this->secondWidget = nullptr;//Обнуление указателя на второй виджет
    this->thirdWidget = nullptr;//Обнуление указателя на третий виджет

    this->baseWidget = new GeneralWidget;//Инициализация базового виджета
    connect(this->baseWidget, SIGNAL(closeApplication()),
            this, SLOT(slotCloseApplication()));
    //соединение слота закрытия базового виджета со слотом закрытия данного класса
    this->baseWidget->show();//
    /*
     * Нужен чтобы при закрытии приложения его второстепенные виджета закрывались
     * автоматически вместе с главным окном
     */

    this->mainMenuWidget = new MainMenu(this->baseWidget);
    //Инициализируем и выделяем память под объект главного меню
    connect(this->mainMenuWidget, SIGNAL(clickButton1()),
            this, SLOT(entryToSecondWidget()));
    connect(this->mainMenuWidget, SIGNAL(clickButton2()),
            this, SLOT(entryToThirdWidget()));
    //Соединяем сигналы и слоты наших кнопок
    showWidget(this->mainMenuWidget);//Отображаем форму
}

ControlViewWidget::~ControlViewWidget()
{
    //Вызывается в самую последнюю очередь жизнидеятельности программы
}
//
void ControlViewWidget::backToHome()
{
    showWidget(this->mainMenuWidget);//Отображаем главное меню
}

void ControlViewWidget::entryToSecondWidget()
{
    if (this->secondWidget == nullptr)
    {
        this->secondWidget = new SecondWidget(this->baseWidget);
        connect(this->secondWidget, SIGNAL(clickBack()),
                this, SLOT(backToHome()));
    }
    this->showWidget(this->secondWidget);
}

void ControlViewWidget::entryToThirdWidget()
{
    if (this->thirdWidget == nullptr)
    {
        this->thirdWidget = new ThirdWidget(this->baseWidget);
        connect(this->thirdWidget, SIGNAL(clickBack()),
                this, SLOT(backToHome()));
    }
    this->showWidget(this->thirdWidget);
}
//

void ControlViewWidget::slotCloseApplication()
{
    //Слот срабатывает при закрытии главного окна, здесь можно что-то делать, например переносить потом в трей.
}

void ControlViewWidget::showWidget(QWidget *changeWidget)
{
    if (lastWidget != nullptr)
    {
        this->lastWidget->hide();//
    }
    this->baseWidget->setMinimumSize(changeWidget->minimumSize());//
    this->baseWidget->setMaximumSize(changeWidget->maximumSize());//
    QDesktopWidget *des = QApplication::desktop();//
    int x = (des->screen()->geometry().width() - changeWidget->width())/2;//
    int y = (des->screen()->geometry().height() - changeWidget->height())/2;//
    this->baseWidget->setGeometry(QRect(x, y, changeWidget->width(), changeWidget->height()));//
    if (this->lastWidget != nullptr) this->lastWidget->hide();//
    changeWidget->show();//
    this->lastWidget = changeWidget;//
}
