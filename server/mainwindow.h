#pragma once

#include "network.h"

#include <QWidget>
#include <QThread>
#include <QStringList>

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
    void sendDatagram();

signals:
    void datagram(const QVector<qreal> &);

private:
    void setupUI();
    void setupSignalsSlots();

    qreal cameraAngle() const;
    qreal horisontSpace() const;
    qreal verticalSpace() const;

private:
    Network *network;
    QThread networkThread;

    Ui::MainWindow *ui;
};
