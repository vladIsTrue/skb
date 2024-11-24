#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "crosshairitem.h"
#include "aspectratiowidget.h"

#include <QColor>
#include <QVariant>
#include <QDataStream>
#include <QGraphicsScene>

using network::Network;

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
    networkThread.quit();
    networkThread.wait();

    delete ui;
}

void MainWindow::setupUI()
{
    ui->setupUi(this);
    setLayout(ui->mainLayout);

    view = ui->aspectRatioWidget->getView();
    {
        // read sizes or something
        view->setScene(new QGraphicsScene(0, 0, 4000, 3000));

        addGreenCrosshair(view->scene(), 240);
        addSvgCrosshair(view->scene());
    }

    configureComboBoxes();
}

void MainWindow::setupSignalsSlots()
{
    connect(&networkThread, &QThread::started,
            network, &Network::lazyInit, Qt::QueuedConnection);
    connect(network, &Network::pendingDatagram,
            this, &MainWindow::processPendingDatagram, Qt::QueuedConnection);
    connect(&networkThread, &QThread::finished, network, &QObject::deleteLater);
}

void MainWindow::processPendingDatagram(QByteArray datagram)
{
    double angle, horizontSpace, verticalSpace;

    QDataStream in(&datagram, QIODevice::ReadOnly);

    in >> angle >> horizontSpace >> verticalSpace;

    ui->angleLabel->setText(tr("Угол камеры: %1").arg(angle));
    ui->horizontalLabel->setText(tr("Отступ по горизонтали: %1").arg(horizontSpace));
    ui->verticalLabel->setText(tr("Отступ по вертикали: %1").arg(verticalSpace));

    crosshairMove(horizontSpace, verticalSpace);
}

void MainWindow::crosshairMove(qreal horisontal, qreal vertical)
{
    qreal widht = view->sceneRect().width();
    qreal height = view->sceneRect().height();

    qreal crWidht = crosshair->boundingRect().width();
    qreal crHeight = crosshair->boundingRect().height();

    auto centeterWidht = widht * 0.5 - crWidht * 0.5;
    auto centeterHeight = height * 0.5 - crHeight * 0.5;

    crosshair->setPos(centeterWidht + (widht * 0.5 * horisontal), centeterHeight + (height * 0.5 *vertical));
}

void MainWindow::configureComboBoxes()
{
    ui->background->addItem(tr("Белый"), QColor{Qt::white});
    ui->background->addItem(tr("Черный"), QColor{Qt::black});
    ui->background->addItem(tr("Серый"), QColor{Qt::gray});

    ui->aim->addItem(tr("Красный"));
    ui->aim->addItem(tr("Черный"));
}

void MainWindow::updateCrosshairColor(int index)
{
    crosshair->setColor(index == 0 ? CrosshairColor::red : CrosshairColor::black);
}

void MainWindow::updateBackground(int index)
{
    QVariant color = ui->background->itemData(index);
    view->scene()->setBackgroundBrush(color.value<QColor>());
}

void MainWindow::addGreenCrosshair(QGraphicsScene *scene, qreal size)
{
    GreenCrosshairItem *green = new GreenCrosshairItem(size);
    green->setPos(scene->width() * 0.5, scene->height() * 0.5);
    scene->addItem(green);
}

void MainWindow::addSvgCrosshair(QGraphicsScene *scene)
{
    crosshair = new SvgCrosshair;

    auto widht = scene->width() * 0.5 - crosshair->boundingRect().width() * 0.5;
    auto height = scene->height() * 0.5 - crosshair->boundingRect().height() * 0.5;

    crosshair->setPos(widht, height);
    view->scene()->addItem(crosshair);
}
