#include "crosshairitem.h"

GreenCrosshairItem::GreenCrosshairItem(qreal size, qreal penWidth)
    : size(size)
    , penWidth(penWidth)
{}

void GreenCrosshairItem::paint(
    QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setPen(QPen(Qt::green, penWidth));
    painter->drawLine(-size, 0, size, 0);
    painter->drawLine(0, -size, 0, size);
}

QRectF GreenCrosshairItem::boundingRect() const
{
    return QRectF(-size - penWidth * 0.5, -size - penWidth * 0.5, size + penWidth, size + penWidth);
}
