#include "consolereader.h"
#include <QDebug>
#include <QEventLoop>
#include <QCoreApplication>

ConsoleReader::ConsoleReader(QObject *parent) : QObject(parent)
{
    connect(this, SIGNAL(run()), this, SLOT(onRun()));
    qDebug() << "Enter a command(/command) or a message(message)";
    qDebug() << "   Commands:   connect             - start tcp connection";
    qDebug() << "               disconnect          - close tcp connection";
    qDebug() << "               udpauto             - start udp auto up- & reconnection";
    qDebug() << "               udpstop             - stop udp autoconnection";
    qDebug() << "               noecho              - stop echoing back to server";
    qDebug() << "               echo                - echoing messages back to server";
    qDebug() << "               setip=10.28.2.150   - set ip";
    qDebug() << "               setport=4321        - set tcp port";
    qDebug() << "               setid=12121212      - set device id";
    qDebug() << "               quit                - quit program";
}

void ConsoleReader::onRun()
{
    QCoreApplication::processEvents();
    readCommand();
}

void ConsoleReader::readCommand()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof() || line == "quit") {
        emit finished();
    } else {
        emit inputFromCommandLine(QString::fromStdString(line));
        emit run();
    }
}

void ConsoleReader::writeToConsole(QString message)
{
    QDebug qdebug = qDebug();
    qdebug.noquote() << message;
}
