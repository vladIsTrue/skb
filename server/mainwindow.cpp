#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , network(new Network)
    , ui(new Ui::MainWindow)
{
    setupUI();
    setupSignalsSlots();

    network->moveToThread(&networkThread);
    networkThread.start();
}

MainWindow::~MainWindow()
{
    delete ui;

    networkThread.quit();
    networkThread.wait();
}

void MainWindow::sendDatagram()
{
    emit datagram({cameraAngle(),
                   horisontSpace(),
                   verticalSpace()});
}

void MainWindow::setupUI()
{
    ui->setupUi(this);
    setLayout(ui->mainLayout);
}

void MainWindow::setupSignalsSlots()
{
    connect(&networkThread, &QThread::started, network, &Network::lazyInit, Qt::QueuedConnection);
    connect(this, &MainWindow::datagram, network, &Network::sendDatagram, Qt::QueuedConnection);
    connect(&networkThread, &QThread::finished, network, &QObject::deleteLater);
}

qreal MainWindow::cameraAngle() const
{
    return ui->angleLabel->text().toDouble();
}

qreal MainWindow::horisontSpace() const
{
    return ui->horisontLabel->text().toDouble();
}

qreal MainWindow::verticalSpace() const
{
    return ui->verticalLabel->text().toDouble();
}
