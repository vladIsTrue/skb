#pragma once

#include <QWidget>
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
    void configureComboBoxes();

    void addSvgCrosshair(QGraphicsScene *scene);
    void addGreenCrosshair(QGraphicsScene *scene, qreal size);

private:
    QGraphicsSvgItem *black;
    QGraphicsSvgItem *red;

    QGraphicsView *view;
    Ui::MainWindow *ui;
};
