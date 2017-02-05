#ifndef CONSOLE_H
#define CONSOLE_H


#pragma once

#include <QObject>
#include <QSocketNotifier>
#include <iostream>

class Console : public QObject
{
    Q_OBJECT

public:
    Console();

public slots:
    void run();

signals:
    void quit();
    void cycle();

private:
    QSocketNotifier *m_notifier;

private slots:
    void readCommand();
};

#endif // CONSOLE_H
