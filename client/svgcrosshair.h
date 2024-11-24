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

    void setScale(qreal scale);

    QRectF boundingRect() const override;

private:
    QRectF scaledRect() const;

private:
    QGraphicsSvgItem *red;
    QGraphicsSvgItem *black;

    qreal realWidth;
    qreal realHeight;

    qreal scaleFactor = 1.;
};
