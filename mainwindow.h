#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBoxLayout>
#include <QCheckBox>
#include <QPushButton>
#include <QSlider>
#include <QColorDialog>
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

private slots:
    void onOnOffEnableChangeState(int state);
    void onOnOffChangeState(int state);
    void onSizeSliderValueChanged(int value);
    void onDefaultColorButtonClick();
    void onOnColorButtonClick();
    void onOffColorButtonClick();
};

#endif // MAINWINDOW_H
