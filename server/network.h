#pragma once

#include <QUdpSocket>

#include <memory>

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
    void sendDatagram(const QStringList &data);

private:
    std::unique_ptr<QUdpSocket> socket;
    ConnectionSettings settings;
};
