#include "network.h"

#include <QNetworkDatagram>

Network::Network(const ConnectionSettings &settings)
    : settings(settings)
{
}

void Network::lazyInit()
{
    socket.reset(new QUdpSocket);

    socket->bind(settings.host, settings.port);
    connect(socket.get(), &QUdpSocket::readyRead, this, &Network::readPendingDatagrams);
}

void Network::readPendingDatagrams()
{
    while (socket->hasPendingDatagrams()) {
        QNetworkDatagram datagram = socket->receiveDatagram();

        emit pendingDatagram(datagram.data());
    }
}
