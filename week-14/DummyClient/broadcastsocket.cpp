#include "broadcastsocket.h"

BroadcastSocket::BroadcastSocket(QString datagramNeeded, QObject *parent) : QObject(parent)
{
    this->datagramNeeded = datagramNeeded;
    udpSocket = new QUdpSocket(this);
    connect(udpSocket, SIGNAL(readyRead()),
         this, SLOT(processPendingDatagrams()));
    startUDP();
}

void BroadcastSocket::startUDP()
{
    gotFirstMessage = false;
    bool connState = false;
    do {
        connState = udpSocket->bind(45454, QUdpSocket::ShareAddress);
    } while(!connState);
    QDebug qdebug = qDebug();
    qdebug.noquote() << "\n" << "  UDP Socket is set up.";
}

void BroadcastSocket::processPendingDatagrams()
 {
    if(udpSocket->state() == QUdpSocket::BoundState){
        while (udpSocket->hasPendingDatagrams()) {
            QByteArray datagram;
            datagram.resize(udpSocket->pendingDatagramSize());
            udpSocket->readDatagram(datagram.data(), datagram.size());
            if (!gotFirstMessage)
            {
                parseDatagram(QString::fromUtf8(datagram));
            }
        }
    }
 }

void BroadcastSocket::parseDatagram(QString datagram)
{
    if(datagramNeeded == datagram)
    {
        emit newDatagram(datagram);
        gotFirstMessage = true;
    }

}

void BroadcastSocket::close()
{
         udpSocket->close();
         QDebug qdebug = qDebug();
         qdebug.noquote() << "   UDP Socket is closed.\n";
}
