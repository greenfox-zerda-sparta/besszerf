#include <QCoreApplication>
#include "dummyclient.h"
#include <QDebug>

int main(int argc, char* argv[]) {
  QCoreApplication a(argc, argv);
  DummyClient d;
  d.run();
  QObject::connect(&d, SIGNAL(quit()), &a, SLOT(quit()));
  return a.exec();
}
