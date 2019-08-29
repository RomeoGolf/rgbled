#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QCheckBox>
#include <QPushButton>

#include <rgbled.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    RgbLed *rgbLed;
    QBoxLayout *createControlPanel();
};

#endif // MAINWINDOW_H
