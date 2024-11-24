#pragma once

#include "scaledsvgitem.h"

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

    QRectF boundingRect() const override;

private:
    ScaledSvgItem *red;
    ScaledSvgItem *black;
};
