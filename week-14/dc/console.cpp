#include "console.h"

#include <iostream>
#include "console.h"


Console::Console()
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    connect(this, SIGNAL(cycle()), this, SLOT(run()));
    std::cout << "Echoing message" << std::endl;
}

void Console::run()
{
    std::cout << "> " << std::flush;
//    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    readCommand();
}

void Console::readCommand()
{
    std::string line;
    std::getline(std::cin, line);
    if (std::cin.eof() || line == "quit") {
        std::cout << "Good bye!" << std::endl;
        emit quit();
    } else {
        std::cout << "Echo: " << line << std::endl;
        emit cycle();
    }
}
