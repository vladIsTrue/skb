#pragma once

#include "animations.h"
#include "network.h"
#include "svgcrosshair.h"

#include <QGraphicsView>
#include <QThread>
#include <QWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

    using Network = network::Network;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateCrosshairColor(int index);
    void updateBackground(int index);

private:
    void setupUI();
    void setupSignalsSlots();
    void configureComboBoxes();

    void addSvgCrosshair(QGraphicsScene *scene);
    void addGreenCrosshair(QGraphicsScene *scene, qreal size);

    void processPendingDatagram(QByteArray datagram);
    void crosshairMove(qreal horisontal, qreal vertical);
    void crosshairScaleForAngle(qreal angle);

private:
    // factor посчитанный с расчетом,
    // что цена деления прицела - 1 тысячная
    // для прицела, с 20 делениями на шкале
    const qreal factor = 6000. / 7200.;

    SvgCrosshair *crosshair;
    QGraphicsView *view;

    Network *network;
    QThread networkThread;

    Animations animations;

    Ui::MainWindow *ui;
};
