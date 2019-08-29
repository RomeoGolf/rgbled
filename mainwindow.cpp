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
    QCheckBox *checkBoxOnOffEnable = new QCheckBox("On/Off enable");
    checkBoxOnOffEnable->setCheckState(Qt::Checked);
    connect(checkBoxOnOffEnable, SIGNAL(stateChanged(int)),
            this, SLOT(onOnOffEnableChangeState(int)));
    QCheckBox *checkBoxOnOff = new QCheckBox("On/Off");
    connect(checkBoxOnOff, SIGNAL(stateChanged(int)),
            this, SLOT(onOnOffChangeState(int)));
    QPushButton *selectOnColorButton = new QPushButton("Select On color...");
    QPushButton *selectOffColorButton = new QPushButton("Select Off color...");
    QPushButton *selectDefaultColorButton = new QPushButton("Select default color...");
    QSlider *sizeSlider = new QSlider();
    sizeSlider->setMinimum(15);
    sizeSlider->setMaximum(300);
    sizeSlider->setValue(50);
    sizeSlider->setOrientation(Qt::Horizontal);
    connect(sizeSlider, SIGNAL(valueChanged(int)),
            this, SLOT(onSizeSliderValueChanged(int)));
    QBoxLayout *result = new QHBoxLayout();
    result->addWidget(checkBoxOnOffEnable);
    result->addWidget(checkBoxOnOff);
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
