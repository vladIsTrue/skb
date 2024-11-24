#include "svgcrosshair.h"

SvgCrosshair::SvgCrosshair(QGraphicsItem *parent)
    : QGraphicsItemGroup(parent)
{
    red = new QGraphicsSvgItem(QStringLiteral(":/crosshair_red.svg"));
    black = new QGraphicsSvgItem(QStringLiteral(":/crosshair_black.svg"));

    addToGroup(red);
    addToGroup(black);

    realWidth = QGraphicsItemGroup::boundingRect().width();
    realHeight = QGraphicsItemGroup::boundingRect().height();

    setScale(scaleFactor);
}

void SvgCrosshair::setColor(CrosshairColor color)
{
    black->setVisible(color == CrosshairColor::black);
    red->setVisible(color == CrosshairColor::red);
}

void SvgCrosshair::setScale(qreal scale)
{
    QSizeF oldSize = scaledRect().size();
    QPointF oldPos = scenePos();
    scaleFactor = scale;

    QGraphicsItemGroup::setScale(scale);

    QSizeF newSize = scaledRect().size();

    setPos(oldPos.x() + (oldSize.width() - newSize.width()) * 0.5,
           oldPos.y() + (oldSize.height() - newSize.height()) * 0.5);
}

QRectF SvgCrosshair::boundingRect() const
{
    return scaledRect();
}

QRectF SvgCrosshair::scaledRect() const
{
    return QRectF(0., 0., realWidth * scaleFactor, realHeight * scaleFactor);
}
