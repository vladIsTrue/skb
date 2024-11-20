#pragma once

#include <QSlider>

class RealSlider : public QSlider
{
    Q_OBJECT

public:
    explicit RealSlider(QWidget *parent = nullptr);

signals:
    void valueChanged(double value);
};

