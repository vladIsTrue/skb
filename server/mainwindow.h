#pragma once

#include <QWidget>

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

private:
    void setupUI();

private:
    Ui::MainWindow *ui;
};
