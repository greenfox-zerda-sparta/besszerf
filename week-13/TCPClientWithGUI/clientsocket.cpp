#include "clientsocket.h"

#include <QTcpSocket>
#include <QTimer>

ClientSocket::ClientSocket(QObject *parent)
{
    socket = new QTcpSocket(this);
    serverPort = 1234;
    serverAddress = "localhost";
    userName = "Feri";
    timerId = -1;
    connect(socket, SIGNAL(readyRead()), this, SLOT(newDataAvailable()));
    connect(socket, SIGNAL(connected()), this, SIGNAL(socketConnected()));
    connect(socket, SIGNAL(connected()), this, SLOT(sendFirstMessage()));
    connect(parent, SIGNAL(sendMessage(QString)), this, SLOT(onSend(QString)));
}

void ClientSocket::StartTimer()
{
    timerId = startTimer(200);

}

void ClientSocket::StopTimer()
{
    if(!(timerId = -1))
    {
        killTimer(timerId);
        timerId = -1;
    }
}

ClientSocket::~ClientSocket()
{
    disconnect(socket, NULL, this, NULL);
}

void ClientSocket::connectToServer()
{
    socket->connectToHost(serverAddress, serverPort);
}

void ClientSocket::newDataAvailable()
{
    incomingData = (socket->readAll()).trimmed();
    QString str(QString::fromUtf8(incomingData));
    emit incomingMessage(str);
}

void ClientSocket::onSend(QString message)
{
    if (socket->state() != QTcpSocket::ConnectedState) {
        return;
    }
   qint64 error = socket->write(message.toUtf8());
}

void ClientSocket::timerEvent(QTimerEvent *)
{
    if (socket->state() == QTcpSocket::UnconnectedState) {
        connectToServer();
    }
}

void ClientSocket::sendFirstMessage()
{
    onSend(userName);
}

void ClientSocket::Disconnect()
{
    socket->close();
}
