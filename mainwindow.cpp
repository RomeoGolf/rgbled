/*
  Copyright 2016 - 2018 RomeoGolf

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
of the Software, and to permit persons to whom the Software is furnished to do
so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rgbLed = new RgbLed();
    rgbLed->setFixedWidth(50);
    QBoxLayout *rgbLedLayout = new QHBoxLayout();
    rgbLedLayout->addWidget(rgbLed);
    QWidget *backWidget = new QWidget();
    backWidget->setFixedHeight(300);
    backWidget->setLayout(rgbLedLayout);
    QBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(createControlPanel());
    mainLayout->addWidget(backWidget);
    this->setCentralWidget(new QWidget());
    this->centralWidget()->setLayout(mainLayout);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

MainWindow::~MainWindow()
{
}

QBoxLayout * MainWindow::createControlPanel()
{
    QCheckBox *onOffEnableCheckBox = new QCheckBox("On/Off enable");
    onOffEnableCheckBox->setCheckState(Qt::Checked);
    connect(onOffEnableCheckBox, SIGNAL(stateChanged(int)),
            this, SLOT(onOnOffEnableChangeState(int)));
    QCheckBox *onOffCheckBox = new QCheckBox("On/Off");
    connect(onOffCheckBox, SIGNAL(stateChanged(int)),
            this, SLOT(onOnOffChangeState(int)));
    QPushButton *selectOnColorButton = new QPushButton("Select On color...");
    QPushButton *selectOffColorButton = new QPushButton("Select Off color...");
    QPushButton *selectDefaultColorButton = new QPushButton("Select default color...");
    connect(selectDefaultColorButton, SIGNAL(clicked()),
            this, SLOT(onDefaultColorButtonClick()));
    connect(selectOnColorButton, SIGNAL(clicked()),
            this, SLOT(onOnColorButtonClick()));
    connect(selectOffColorButton, SIGNAL(clicked()),
            this, SLOT(onOffColorButtonClick()));
    QSlider *sizeSlider = new QSlider();
    sizeSlider->setMinimum(15);
    sizeSlider->setMaximum(300);
    sizeSlider->setValue(50);
    sizeSlider->setOrientation(Qt::Horizontal);
    connect(sizeSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onSizeSliderValueChanged(int)));
    QBoxLayout *result = new QHBoxLayout();
    result->addWidget(onOffEnableCheckBox);
    result->addWidget(onOffCheckBox);
    result->addWidget(selectOnColorButton);
    result->addWidget(selectOffColorButton);
    result->addWidget(selectDefaultColorButton);
    result->addWidget(sizeSlider);
    return result;
}

void MainWindow::onOnOffEnableChangeState(int state)
{
    rgbLed->setUseState(state == Qt::Checked);
}

void MainWindow::onOnOffChangeState(int state)
{
    rgbLed->setStateOn(state == Qt::Checked);
}

void MainWindow::onSizeSliderValueChanged(int value)
{
    rgbLed->setFixedWidth(value);
}

void MainWindow::onDefaultColorButtonClick()
{
    const QColorDialog::ColorDialogOptions options = QFlag(0);
    const QColor color =
        QColorDialog::getColor(Qt::blue, this, "Select Default Color", options);
    if (color.isValid()) {
        rgbLed->setLedColor(color);
    }
}

void MainWindow::onOnColorButtonClick()
{
    const QColorDialog::ColorDialogOptions options = QFlag(0);
    const QColor color =
            QColorDialog::getColor(Qt::blue, this, "Select On Color", options);
    if (color.isValid()) {
        rgbLed->setLedOnColor(color);
    }
}

void MainWindow::onOffColorButtonClick()
{
    const QColorDialog::ColorDialogOptions options = QFlag(0);
    const QColor color =
            QColorDialog::getColor(Qt::blue, this, "Select Off Color", options);
    if (color.isValid()) {
        rgbLed->setLedOffColor(color);
    }
}
