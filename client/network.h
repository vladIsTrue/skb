#pragma once

#include <QUdpSocket>
#include <QByteArray>

#include <memory>

namespace network
{

struct ConnectionSettings
{
    QHostAddress host;
    quint16 port;
};

class Network : public QObject
{
    Q_OBJECT

public:
    explicit Network(const ConnectionSettings &settings = {QHostAddress::LocalHost, 3333});

    void lazyInit();

signals:
    void pendingDatagram(QByteArray);

private:
    void readPendingDatagrams();

private:
    std::unique_ptr<QUdpSocket> socket;
    ConnectionSettings settings;
};

}
