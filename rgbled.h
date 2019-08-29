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
    explicit RgbLed(QWidget *parent = 0);
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
