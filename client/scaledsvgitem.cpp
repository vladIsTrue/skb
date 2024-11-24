#include "scaledsvgitem.h"

#include <QSvgRenderer>

ScaledSvgItem::ScaledSvgItem(const QString &fileName, QGraphicsItem *parent)
    : QGraphicsSvgItem(fileName, parent)
    , realWidth(renderer()->defaultSize().width())
    , realHeight(renderer()->defaultSize().height())
    , scaledWidth(realWidth)
    , scaledHeight(realHeight)
{}

void ScaledSvgItem::upScale(qreal factor)
{
    scaledWidth = realWidth * factor;
    scaledHeight = realHeight * factor;
}

void ScaledSvgItem::downScale(qreal factor)
{
    upScale(1. / factor);
}

QRectF ScaledSvgItem::boundingRect() const
{
    return QRectF(x(), y(), scaledWidth, scaledHeight);
}

void ScaledSvgItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget)
{
    Q_UNUSED(options);
    Q_UNUSED(widget);

    renderer()->render(painter, boundingRect());
}
