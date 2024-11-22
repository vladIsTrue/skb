#include "network.h"

#include <QByteArray>

Network::Network(const ConnectionSettings &settings)
    : settings(settings)
{
}

void Network::lazyInit()
{
    socket.reset(new QUdpSocket);
}

void Network::sendDatagram(const QVector<qreal> &data)
{
    QByteArray datagram;
    QDataStream out(&datagram, QIODevice::WriteOnly);

    for (auto item : data)
        out << item;

    socket->writeDatagram(datagram, settings.host, settings.port);
}
