#include "aspectratiowidget.h"

#include <QResizeEvent>

AspectRatio4x3Widget::AspectRatio4x3Widget(QWidget *parent)
    : QWidget(parent)
{
    layout = new QBoxLayout(QBoxLayout::LeftToRight, this);

    layout->addItem(new QSpacerItem(0, 0));
    layout->addWidget(view = new QGraphicsView(this));
    layout->addItem(new QSpacerItem(0, 0));

    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setLayout(layout);
}

QGraphicsView *AspectRatio4x3Widget::getView() const
{
    return view;
}

void AspectRatio4x3Widget::resizeEvent(QResizeEvent *event)
{
    float thisAspectRatio = static_cast<qreal>(event->size().width()) / event->size().height();

    int widgetStretch, outerStretch;

    if (thisAspectRatio > (ascpectRatio)) {
        layout->setDirection(QBoxLayout::LeftToRight);
        widgetStretch = height() * (ascpectRatio);
        outerStretch = (width() - widgetStretch) * 0.5 + 0.5;
    } else {
        layout->setDirection(QBoxLayout::TopToBottom);
        widgetStretch = width() * (backAscpectRatio);
        outerStretch = (height() - widgetStretch) * 0.5 + 0.5;
    }

    layout->setStretch(0, outerStretch);
    layout->setStretch(1, widgetStretch);
    layout->setStretch(2, outerStretch);

    view->fitInView(view->sceneRect(), Qt::KeepAspectRatio);
}

void AspectRatio4x3Widget::showEvent(QShowEvent *event)
{
    Q_UNUSED(event);

    view->fitInView(view->sceneRect(), Qt::KeepAspectRatio);
}
