#pragma once

#include <QGraphicsSvgItem>

enum class CrosshairColor
{
    red,
    black
};

class SvgCrosshair : public QGraphicsItemGroup
{
public:
    explicit SvgCrosshair(QGraphicsItem *parent = nullptr);

    void setColor(CrosshairColor color);

    void setRed();
    void setBlack();

private:
    QGraphicsSvgItem *red;
    QGraphicsSvgItem *black;
};
