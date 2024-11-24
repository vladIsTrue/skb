#pragma once

#include <QGraphicsSvgItem>

class ScaledSvgItem : public QGraphicsSvgItem
{
public:
    ScaledSvgItem(const QString &fileName, QGraphicsItem *parent = nullptr);

    void upScale(qreal factor);
    void downScale(qreal factor);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *options, QWidget *widget) override;

private:
    qreal realWidth;
    qreal realHeight;

    qreal scaledWidth;
    qreal scaledHeight;
};
