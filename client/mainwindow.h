#pragma once

#include "network.h"
#include "svgcrosshair.h"

#include <QWidget>
#include <QThread>
#include <QGraphicsView>

namespace Ui
{
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
    SvgCrosshair *crosshair;
    QGraphicsView *view;

    Network *network;
    QThread networkThread;

    Ui::MainWindow *ui;
};
