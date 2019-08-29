#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    rgbLed = new RgbLed();
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
    QCheckBox *checkBoxOnOff = new QCheckBox("On/Off");
    QPushButton *selectOnColorButton = new QPushButton("Select On color...");
    QPushButton *selectOffColorButton = new QPushButton("Select Off color...");
    QPushButton *selectDefaultColorButton = new QPushButton("Select Off color...");
    QBoxLayout *result = new QHBoxLayout();
    result->addWidget(checkBoxOnOffEnable);
    result->addWidget(checkBoxOnOff);
    result->addWidget(selectOnColorButton);
    result->addWidget(selectOffColorButton);
    result->addWidget(selectDefaultColorButton);
    return result;
}
