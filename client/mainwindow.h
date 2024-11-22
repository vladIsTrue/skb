#pragma once

#include "network.h"

#include <QWidget>
#include <QThread>
#include <QGraphicsView>
#include <QGraphicsSvgItem>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void updateBackground(int index);

private:
    void setupUI();
    void setupSignalsSlots();
    void configureComboBoxes();

    void addSvgCrosshair(QGraphicsScene *scene);
    void addGreenCrosshair(QGraphicsScene *scene, qreal size);

    void processPendingDatagram(QByteArray datagram);

private:
    QGraphicsSvgItem *black;
    QGraphicsSvgItem *red;
    QGraphicsView *view;

    Network *network;
    QThread networkThread;

    Ui::MainWindow *ui;
};
