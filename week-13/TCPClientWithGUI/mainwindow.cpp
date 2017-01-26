#include "mainwindow.h"
#include "clientsocket.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Client = new ClientSocket(this);
    ui->NameField->setText(Client->userName);
    ui->IpField->setText(Client->serverAddress);
    ui->PortField->setText(QString::number(Client->serverPort));
    ui->SendButton->setEnabled(false);
    ui->EditedText->setEnabled(false);
    connect(Client, SIGNAL(incomingMessage(QString)), this, SLOT(onIncomingMessage(QString)));
    connect(Client, SIGNAL(socketConnected()), this, SLOT(onSocketConnected()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete Client;
}


void MainWindow::on_ConnectButton_toggled(bool checked)
{
  if(checked)
  {
    Client->userName = ui->NameField->text();
    Client->serverAddress = ui->IpField->text();
    Client->serverPort = qstringToQuint16(ui->PortField->text());
    ui->ConnectButton->setText("Disconnect");
    ui->NameField->setReadOnly(true);
    ui->NameField->setEnabled(false);
    ui->IpField->setReadOnly(true);
    ui->IpField->setEnabled(false);
    ui->PortField->setReadOnly(true);
    ui->PortField->setEnabled(false);
    ui->SendButton->setEnabled(true);
    ui->EditedText->setEnabled(true);
    Client->StartTimer();
    Client->Disconnect();
  }
  else
  {
      ui->ConnectButton->setText("Connect");
      ui->NameField->setReadOnly(false);
      ui->NameField->setEnabled(true);
      ui->IpField->setReadOnly(false);
      ui->IpField->setEnabled(true);
      ui->PortField->setReadOnly(false);
      ui->PortField->setEnabled(true);
      ui->SendButton->setEnabled(false);
      ui->EditedText->setEnabled(false);
      Client->StopTimer();
  }
}


void MainWindow::on_SendButton_clicked()
{
    QString newText = ui->EditedText->toPlainText();
    ui->EditedText->clear();
    emit sendMessage(newText);
    newText = Client->userName + "> " + newText;
    setIncomingTextArea(newText);
}

quint16 MainWindow::qstringToQuint16(QString string)
{
    QTextStream ts(&string);
    quint16 result = 0;
    ts >> result;
    return result;

}

void MainWindow::onIncomingMessage(QString str)
{
    setIncomingTextArea(str);
}

void MainWindow::onSocketConnected()
{
    setIncomingTextArea("Connected to server");
}


void MainWindow::setIncomingTextArea(QString message)
{
//    QString text = ui->IncomingText->toPlainText();
//    ui->IncomingText->clear();
//    text += message + "\n";
//    ui->IncomingText->insertPlainText(text);
    ui->IncomingText->append(message);
}
