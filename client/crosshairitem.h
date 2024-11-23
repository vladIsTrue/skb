#pragma once

#include <QPainter>
#include <QGraphicsItem>

class GreenCrosshairItem : public QGraphicsItem
{
public:
    explicit GreenCrosshairItem(qreal size, qreal penWidth = 4);

protected:
    QRectF boundingRect() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    qreal size;
    qreal penWidth;
};
