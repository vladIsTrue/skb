#include "svgcrosshair.h"

SvgCrosshair::SvgCrosshair(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent)
{
    red = new QGraphicsSvgItem(QStringLiteral(":/crosshair_red.svg"));
    black = new QGraphicsSvgItem(QStringLiteral(":/crosshair_black.svg"));

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
