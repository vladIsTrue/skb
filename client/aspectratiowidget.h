#pragma once

#include <QWidget>
#include <QBoxLayout>
#include <QGraphicsView>

class AspectRatio4x3Widget : public QWidget
{
public:
    explicit AspectRatio4x3Widget(QWidget *parent = nullptr);

    QGraphicsView *getView() const;

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QBoxLayout *layout;
    QGraphicsView *view;

    qreal arWidth = 4.;
    qreal arHeight = 3.;
};
