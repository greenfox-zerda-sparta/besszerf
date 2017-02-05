﻿#include "udpsender.h"
#include <QDebug>

UdpSender::UdpSender(QObject* parent) : QObject(parent) {
  timer = new QTimer(this);
  udpSocket = new QUdpSocket(this);
  startBroadcasting();
  connect(timer, SIGNAL(timeout()), this, SLOT(broadcastDatagram()));
}

void UdpSender::startBroadcasting() {
  timer->start(1000);
}

void UdpSender::stopBroadcasting() {
	timer->stop();
}

void UdpSender::broadcastDatagram() {
  QByteArray datagram = "turquoise&emerald";
  udpSocket->writeDatagram(datagram.data(), datagram.size(),
	  QHostAddress::Broadcast, 45454);
  qDebug() << "Broadcasting message: " << QString::fromUtf8(datagram);
}
