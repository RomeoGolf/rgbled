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
    //rgbLed->setLedColor(Qt::red);
    const QColorDialog::ColorDialogOptions options = QFlag(0);
    const QColor color = QColorDialog::getColor(Qt::blue, this, "Select Default Color", options);

    if (color.isValid()) {
        rgbLed->setLedColor(color);
    }
}
