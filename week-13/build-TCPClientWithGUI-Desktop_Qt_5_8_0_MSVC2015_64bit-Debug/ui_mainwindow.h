/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *IncomingText;
    QTextEdit *EditedText;
    QPushButton *SendButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *NameField;
    QLabel *label_2;
    QLineEdit *IpField;
    QLabel *label_3;
    QLineEdit *PortField;
    QPushButton *ConnectButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(550, 411);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMaximumSize(QSize(550, 16777215));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        IncomingText = new QTextEdit(centralWidget);
        IncomingText->setObjectName(QStringLiteral("IncomingText"));
        IncomingText->setEnabled(true);
        IncomingText->setGeometry(QRect(10, 40, 431, 221));
        IncomingText->setReadOnly(true);
        EditedText = new QTextEdit(centralWidget);
        EditedText->setObjectName(QStringLiteral("EditedText"));
        EditedText->setGeometry(QRect(10, 270, 431, 81));
        SendButton = new QPushButton(centralWidget);
        SendButton->setObjectName(QStringLiteral("SendButton"));
        SendButton->setGeometry(QRect(450, 270, 85, 27));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 530, 29));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        NameField = new QLineEdit(layoutWidget);
        NameField->setObjectName(QStringLiteral("NameField"));

        horizontalLayout->addWidget(NameField);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        IpField = new QLineEdit(layoutWidget);
        IpField->setObjectName(QStringLiteral("IpField"));
        sizePolicy.setHeightForWidth(IpField->sizePolicy().hasHeightForWidth());
        IpField->setSizePolicy(sizePolicy);
        IpField->setMinimumSize(QSize(72, 0));

        horizontalLayout->addWidget(IpField);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        PortField = new QLineEdit(layoutWidget);
        PortField->setObjectName(QStringLiteral("PortField"));

        horizontalLayout->addWidget(PortField);

        ConnectButton = new QPushButton(layoutWidget);
        ConnectButton->setObjectName(QStringLiteral("ConnectButton"));
        ConnectButton->setCheckable(true);

        horizontalLayout->addWidget(ConnectButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 550, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "QT TCP Chat Client", Q_NULLPTR));
        SendButton->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Your nickname:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Server Ip:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Server Port:", Q_NULLPTR));
        ConnectButton->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
