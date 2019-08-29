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

#ifndef RGBLED_H
#define RGBLED_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QColor>
#include <QGradient>
#include <QMap>
//#include <QMouseEvent>

class RgbLed : public QWidget
{
    Q_OBJECT
public:
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

protected:
    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);
    //void mousePressEvent(QMouseEvent *event);

private:
    bool stateOn;
    bool stateIsUsed;

    int height;
    int width;
    int minDim;
    int half;
    int centerX;
    int centerY;
    QRect drawingRect;

    int outerBorderWidth;
    int innerBorderWidth;
    int outerBorderRadius;
    int innerBorderRadius;
    int topReflexY;
    int bottomReflexY;
    int topReflexWidth;
    int topReflexHeight;
    int bottomReflexWidth;
    int bottomReflexHeight;

    QColor ledColor;
    QColor onColor;
    QColor offColor;
    QColor lightColor;
    QColor shadowColor;
    QColor ringShadowDarkColor;
    QColor ringShadowMedColor;
    QColor ringShadowLightColor;
    QColor topReflexUpColor;
    QColor topReflexDownColor;
    QColor bottomReflexCenterColor;
    QColor bottomReflexSideColor;
    QMap<bool, QColor> stateColors;

    void drawLed(const QColor &color);

signals:

public slots:

};

#endif // RGBLED_H
