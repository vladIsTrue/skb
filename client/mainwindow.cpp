#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aspectratiowidget.h"

#include <QColor>
#include <QVariant>
#include <QGraphicsScene>
#include <QGraphicsLineItem>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    setupUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUI()
{
    ui->setupUi(this);
    setLayout(ui->mainLayout);

    view = ui->aspectRatioWidget->getView();
    {
        // read sizes or something
        view->setScene(new QGraphicsScene(0, 0, 2048, 2048));

        addGreenCrosshair(view->scene(), 240);
        addSvgCrosshair(view->scene());
    }

    configureComboBoxes();
}

void MainWindow::configureComboBoxes()
{
    ui->background->addItem(tr("Черный"), QColor{Qt::black});
    ui->background->addItem(tr("Белый"), QColor{Qt::white});
    ui->background->addItem(tr("Серый"), QColor{Qt::gray});

    connect(ui->aim, &QComboBox::currentIndexChanged, [=] (int index)
    {
        red->setVisible(!index);
        black->setVisible(index);
    });

    ui->aim->addItem(tr("Красный"));
    ui->aim->addItem(tr("Черный"));
}

void MainWindow::updateBackground(int index)
{
    QVariant color = ui->background->itemData(index);
    view->scene()->setBackgroundBrush(color.value<QColor>());
}

void MainWindow::addGreenCrosshair(QGraphicsScene *scene, qreal size)
{
    QGraphicsLineItem *line1 = new QGraphicsLineItem();
    QGraphicsLineItem *line2 = new QGraphicsLineItem();

    qreal lineWidth = 4;

    line1->setLine(0, -size, 0, size);
    line2->setLine(-size, 0, size, 0);
    line1->setPen(QPen{QColor{Qt::green}, lineWidth});
    line2->setPen(QPen{QColor{Qt::green}, lineWidth});
    line1->setPos(scene->width() * 0.5, scene->height() * 0.5);
    line2->setPos(scene->width() * 0.5, scene->height() * 0.5);

    scene->addItem(line1);
    scene->addItem(line2);
}

void MainWindow::addSvgCrosshair(QGraphicsScene *scene)
{
    red = new QGraphicsSvgItem(QStringLiteral(":/crosshair_red.svg"));
    black = new QGraphicsSvgItem(QStringLiteral(":/crosshair_black.svg"));

    QGraphicsItemGroup *group = new QGraphicsItemGroup();
    group->addToGroup(red);
    group->addToGroup(black);

    auto widht = scene->width() * 0.5 - group->boundingRect().width() * 0.5;
    auto height = scene->height() * 0.5 - group->boundingRect().height() * 0.5;

    group->setPos(widht, height);

    view->scene()->addItem(group);
}
