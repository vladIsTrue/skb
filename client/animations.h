#pragma once

#include <QObject>
#include <QQueue>

#include <functional>

class Animations : public QObject
{
    Q_OBJECT

public:
    void pushBack(std::function<void()> &&animation);
    void show();

public slots:
    void next();

private:
    QQueue<std::function<void()>> animations;

    volatile bool runnig = false;
};
