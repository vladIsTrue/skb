#include "realslider.h"

RealSlider::RealSlider(QWidget *parent)
    : QSlider(parent)
{
    connect(this, &QSlider::valueChanged, [=](int value)
            { emit valueChanged(value / 100.0); } );
}
