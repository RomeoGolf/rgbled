# RgbLed

Qt-виджет, изображающий RGB-LED (светодиод с настраиваемым цветом) для использования в качестве визуального индикатора.

## Краткое описание

Проект содержит визуальный элемент управления, стилизованный под светодиодный индикатор, а также окно с элементами управления, позволяющими изменить поведение и отображение RgbLed.

RgbLed прорисовывается с применением принципов векторной графики без использования файлов изображений, как описано в статье ["Qt: рисование по мотивам векторной графики"](https://habr.com/ru/post/425547/ "Хабр").

Внешний вид виджета:

![RgbLed][RgbLed]

[RgbLed]: http:// ""

Пример применения:

![RgbLed][RgbLedSample]

[RgbLedSample]: http:// ""


## Начало работы

### Зависимости

Для компиляции программы использовался Qt Creator 4.8.2 (Основан на Qt 5.12.2).

Зависимости отсутствуют.

### Получение

Для получения копии репозитория следует воспользоваться кнопкой "Clone or download" на [странице репозитория](https://github.com/RomeoGolf/rgbled).

При отсутствии git можно нажать кнопку "Download ZIP" и получить последнюю версию без истории коммитов.

При наличии git можно скопировать URL https://github.com/RomeoGolf/rgbled.git и использовать его в команде

~~~~
git clone https://github.com/RomeoGolf/rgbled.git
~~~~

в командной строке (git bash, например, в зависимости от ОС и настроек).

### Использование программы

Программа предназначена для демонстрации класса RgbLed.

В окне программы можно использовать следующие элементы управления:

* флажок "On/Off enable": переключает возможность использования состояний "Вкл" и "Выкл";
* флажок "On/Off": переключает состояние "Вкл" и "Выкл", если предыдущий флажок установлен;
* кнопка "Select On Color": позволяет выбрать цвет индикатора в состоянии "Вкл";
* кнопка "Select Off Color" позволяет выбрать цвет индикатора в состоянии "Выкл";
* кнопка "Select Default Color": позволяет выбрать цвет индикатора с выключенной возможностью использования сосотяний "Вкл" и "Выкл";
* ползунок, управляющий размером демонстрируемого элемента.

### Использование класса RgbLed

Для использования класса следует включить файлы исходного кода класса (rgbled.cpp и rgbled.h) в использующий проект.

RgbLed имеет следующие открытые методы:

````cpp
    explicit RgbLed(QWidget *parent = nullptr);
    void setLedColor(const QColor &color);
    void setLedOnColor(const QColor &color);
    void setLedOffColor(const QColor &color);
    void setUseState(bool isUseState);
    void setStateOn(bool isStateOn);
    const QColor &getLedColor();
    const QColor &getLedOnColor();
    const QColor &getLedOffColor();
    bool isStateOn();
    bool isStateUsed();
````

#### RgbLed(QWidget *parent = nullptr);

конструктор, принимает указатель на родительский QWidget.

#### setLedColor();

Устанавливает цвет индикатора при выключенной возможности использования состояний "Вкл" и "Выкл".

#### setLedOnColor();

Устанавливает цвет индикатора при включенной возможности использования состояний "Вкл" и "Выкл" в состоянии "Вкл"

#### setLedOffColor();

Устанавливает цвет индикатора при включенной возможности использования состояний "Вкл" и "Выкл" в состоянии "Выкл"

#### setUseState();

Переключает возможность использования состояний "Вкл" и "Выкл". При этом в состоянии "Вкл" индикатор имеет цвет, задаваемый методом setLedOnColor(), а в состоянии "Выкл" - методом setLedOffColor().

#### setStateOn();

Переключает состояние индикатора. Если возможность использования состояний включена методом setUseState(), индикатор принимает цвет, установленный методами setLedOnColor() и setLedOffColor().

#### getLedColor();

Возвращает цвет индикатора при выключенной возможности использования состояний "Вкл" и "Выкл".

#### getLedOnColor();

Возвращает цвет индикатора при включенной возможности использования состояний "Вкл" и "Выкл" для состояния "Вкл".

#### getLedOffColor();

Возвращает цвет индикатора при включенной возможности использования состояний "Вкл" и "Выкл" для состояния "Выкл".

#### isStateOn();

Возвращает "true", если индикатор находится в состоянии "Вкл", и "false" в противном случае.

#### isStateUsed();

Возвращает "true", если для индикатора включена возможность использования состояний "Вкл" и "Выкл", и "false" в противном случае.


## Развитие проекта

Дальнейшее развитие проекта не предполагается, но не исключается.

## Лицензия

This project is licensed under the MIT License - see the [License.txt](License.txt) file for details

