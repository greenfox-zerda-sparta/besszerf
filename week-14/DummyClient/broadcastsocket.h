#ifndef BROADCASTSOCKET_H
#define BROADCASTSOCKET_H
#include <QObject>
#include <QtNetwork>


class BroadcastSocket : public QObject
{
    Q_OBJECT
public:
    BroadcastSocket(QString datagramNeeded, QObject *parent = 0);

signals:
    void newDatagram(QString);

private slots:
     void processPendingDatagrams();
	 void close();
     void startUDP();

 private:
     QUdpSocket *udpSocket;
     bool gotFirstMessage;
     void parseDatagram(QString datagram);
     QString datagramNeeded;
};

#endif // BROADCASTSOCKET_H
