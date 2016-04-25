#ifndef CONTROLVIEWWIDGET_H
#define CONTROLVIEWWIDGET_H

#include <QObject>//Главный класс для Qt от которого наследуются многие другие, включая этот.
#include <QDebug>//Подключения класса для писания отладочной информации в консоль
#include <QDesktopWidget>//Подключения класса для управление экраном(мы будем получать размеры экрана)

#include "generalwidget.h"//Основа-виджет
#include "mainmenu.h"//Класс главного меню
#include "secondwidget.h"//Класс главного меню
#include "thirdwidget.h"//Класс главного меню

class ControlViewWidget : public QObject
{
    Q_OBJECT //Позволяет использовать Qt MOC в своём проекте
public://Начало объявления публичных полей/методов
    explicit ControlViewWidget(QObject *parent = 0);//конструктор главного класса с указанием родителя(по умолчанию 0 = нет родителя)
    ~ControlViewWidget();//деструктор главного класса
    //
 private slots://
    void backToHome();//Переход в главное меню
    void entryToSecondWidget();//Обработчик нажатия Кнопка1, из главного меню
    void entryToThirdWidget();//Обработчик нажатия Кнопка2, из главного меню
     //
    void slotCloseApplication();//метод вызываемый при закрытии приложении
     //
private://начало приватных поле/методов
    GeneralWidget *baseWidget; //главный виджет(окно)
    //
    //Дополнительные виджеты
    MainMenu *mainMenuWidget;//Виджет главного меню
    SecondWidget *secondWidget;//Виджет главного меню
    ThirdWidget *thirdWidget;//Виджет главного меню
    //
    QWidget *lastWidget;//Последний установленный виджет
    //
    void showWidget(QWidget *changeWidget);//Отображение нового виджета
    //
};

#endif // CONTROLVIEWWIDGET_H
