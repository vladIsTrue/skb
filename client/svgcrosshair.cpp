#include "svgcrosshair.h"

SvgCrosshair::SvgCrosshair(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent)
{
    red = new ScaledSvgItem(QStringLiteral(":/crosshair_red.svg"));
    black = new ScaledSvgItem(QStringLiteral(":/crosshair_black.svg"));

    addToGroup(red);
    addToGroup(black);
}

void SvgCrosshair::setColor(CrosshairColor color)
{
    black->setVisible(color == CrosshairColor::black);
    red->setVisible(color == CrosshairColor::red);
}

void SvgCrosshair::setRed()
{
    black->setVisible(false);
    red->setVisible(true);
}

void SvgCrosshair::setBlack()
{
    red->setVisible(false);
    black->setVisible(true);
}

QRectF SvgCrosshair::boundingRect() const
{
    // assume that boundingRect for red and black is the same
    return red->boundingRect();
}
