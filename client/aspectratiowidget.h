#pragma once

#include <QBoxLayout>
#include <QGraphicsView>
#include <QWidget>

class AspectRatio4x3Widget : public QWidget
{
public:
    explicit AspectRatio4x3Widget(QWidget *parent = nullptr);

    QGraphicsView *getView() const;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:
    QBoxLayout *layout;
    QGraphicsView *view;

    qreal ascpectRatio = 4. / 3.;
    qreal backAscpectRatio = 1. / ascpectRatio;
};
