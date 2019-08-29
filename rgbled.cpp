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

#include "rgbled.h"

RgbLed::RgbLed(QWidget *parent) : QWidget(parent),
    stateOn(false),
    stateIsUsed(true),
    ledColor(Qt::blue),
    onColor(Qt::green),
    offColor(Qt::darkGray),
    lightColor(QColor(0xE0, 0xE0, 0xE0)),
    shadowColor(QColor(0x70, 0x70, 0x70)),
    ringShadowDarkColor(QColor(0x50, 0x50, 0x50, 0xFF)),
    ringShadowMedColor(QColor(0x50, 0x50, 0x50, 0x20)),
    ringShadowLightColor(QColor(0xEE, 0xEE, 0xEE, 0x00)),
    topReflexUpColor(QColor(0xFF, 0xFF, 0xFF, 0xA0)),
    topReflexDownColor(QColor(0xFF, 0xFF, 0xFF, 0x00)),
    bottomReflexCenterColor(QColor(0xFF, 0xFF, 0xFF, 0x00)),
    bottomReflexSideColor(QColor(0xFF, 0xFF, 0xFF, 0x70))
{
    stateColors.insert(true, onColor);
    stateColors.insert(false, offColor);
    this->setMinimumHeight(20);
    this->setMinimumWidth(20);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //this->setFixedHeight(200);
    //this->setFixedWidth(200);
}

void RgbLed::setLedColor(const QColor &color)
{
    this->ledColor = color;
    this->repaint();
}

void RgbLed::setLedOnColor(const QColor &color)
{
    this->onColor = color;
    this->stateColors.insert(true, color);
    this->repaint();
}

void RgbLed::setLedOffColor(const QColor &color)
{
    this->offColor = color;
    this->stateColors.insert(false, color);
    this->repaint();
}

void RgbLed::setUseState(bool isUseState)
{
    this->stateIsUsed = isUseState;
    this->repaint();
}

void RgbLed::setStateOn(bool isStateOn)
{
    this->stateOn = isStateOn;
    this->repaint();
}

const QColor &RgbLed::getLedColor()
{
    return this->ledColor;
}

const QColor &RgbLed::getLedOnColor()
{
    return this->onColor;
}

const QColor &RgbLed::getLedOffColor()
{
    return this->offColor;
}

bool RgbLed::isStateOn()
{
    return this->stateOn;
}

bool RgbLed::isStateUsed()
{
    return this->stateIsUsed;
}

void RgbLed::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    if (stateIsUsed) {
        this->drawLed(this->stateColors.value(stateOn));
    } else {
        this->drawLed(this->ledColor);
    }
}

void RgbLed::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    this->height = this->size().height();
    this->width = this->size().width();
    this->minDim = (height > width) ? width : height;
    this->half = minDim / 2;
    this->centerX = width / 2;
    this->centerY = height / 2;

    this->outerBorderWidth = minDim / 10;
    this->innerBorderWidth = minDim / 14;
    this->outerBorderRadius = half - outerBorderWidth;
    this->innerBorderRadius = half - (outerBorderWidth + innerBorderWidth);

    this->topReflexY = centerY
            - (half - outerBorderWidth - innerBorderWidth) / 2;
    this->bottomReflexY = centerY
            + (half - outerBorderWidth - innerBorderWidth) / 2;
    this->topReflexHeight = half / 5;
    this->topReflexWidth = half / 3;
    this->bottomReflexHeight = half / 5;
    this->bottomReflexWidth = half / 3;

    drawingRect.setTop((height - minDim) / 2);
    drawingRect.setLeft((width - minDim) / 2);
    drawingRect.setHeight(minDim);
    drawingRect.setWidth(minDim);
}

/*
void RgbLed::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        this->stateOn = !stateOn;
        this->repaint();
    }
    QWidget::mousePressEvent(event);
}
*/

void RgbLed::drawLed(const QColor &color)
{
    QPainter p(this);

    QPen pen;
    pen.setStyle(Qt::NoPen);
    p.setPen(pen);

    QRadialGradient outerRingGradient(QPoint(centerX,
                          centerY - outerBorderRadius - (outerBorderWidth / 2)),
                          minDim - (outerBorderWidth / 2));
    outerRingGradient.setColorAt(0, lightColor);
    outerRingGradient.setColorAt(1, shadowColor);
    QBrush outerRingBrush(outerRingGradient);
    p.setBrush(outerRingBrush);
    p.drawEllipse(this->drawingRect);

    QRadialGradient innerRingGradient(QPoint(centerX,
                          centerY + innerBorderRadius + (innerBorderWidth / 2)),
                          minDim - (innerBorderWidth / 2));
    innerRingGradient.setColorAt(0, lightColor);
    innerRingGradient.setColorAt(1, shadowColor);
    QBrush innerRingBrush(innerRingGradient);
    p.setBrush(innerRingBrush);
    p.drawEllipse(QPoint(centerX, centerY),
                  outerBorderRadius, outerBorderRadius);

    QColor dark(color.darker(120));
    QRadialGradient glassGradient(QPoint(centerX, centerY),
                              innerBorderRadius);
    glassGradient.setColorAt(0, color);
    glassGradient.setColorAt(1, dark);
    QBrush glassBrush(glassGradient);
    p.setBrush(glassBrush);
    p.drawEllipse(QPoint(centerX, centerY),
                  innerBorderRadius,
                  innerBorderRadius);

    QRadialGradient shadowGradient(QPoint(centerX, centerY),
                              innerBorderRadius);
    shadowGradient.setColorAt(0, ringShadowLightColor);
    shadowGradient.setColorAt(0.85, ringShadowMedColor);
    shadowGradient.setColorAt(1, ringShadowDarkColor);
    QBrush shadowBrush(shadowGradient);
    p.setBrush(shadowBrush);
    p.drawEllipse(QPoint(centerX, centerY),
                  innerBorderRadius,
                  innerBorderRadius);

    QLinearGradient topTeflexGradient(QPoint(centerX,
                                     (innerBorderWidth + outerBorderWidth)),
                              QPoint(centerX, centerY));
    topTeflexGradient.setColorAt(0, topReflexUpColor);
    topTeflexGradient.setColorAt(1, topReflexDownColor);
    QBrush topReflexbrush(topTeflexGradient);
    p.setBrush(topReflexbrush);
    p.drawEllipse(QPoint(centerX, topReflexY), topReflexWidth, topReflexHeight);

    QRadialGradient bottomReflexGradient(QPoint(centerX,
                                     bottomReflexY + (bottomReflexHeight / 2)),
                              bottomReflexWidth);
    bottomReflexGradient.setColorAt(0, bottomReflexSideColor);
    bottomReflexGradient.setColorAt(1, bottomReflexCenterColor);
    QBrush bottomReflexBrush(bottomReflexGradient);
    p.setBrush(bottomReflexBrush);
    p.drawEllipse(QPoint(centerX, bottomReflexY),
                  bottomReflexWidth,
                  bottomReflexHeight);
}
