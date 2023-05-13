/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *CB_SerialCom;
    QComboBox *CB_BaudRate;
    QPushButton *pushButton;
    QPushButton *Button_OpenCom;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Button_Send;
    QCheckBox *checkBox_ReciveHEX;
    QCheckBox *checkBox__SendHEX;
    QTextEdit *textEdit_Send;
    QCheckBox *checkBox__SendAddEnter;
    QTextEdit *textEdit_Recive;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CB_SerialCom = new QComboBox(centralwidget);
        CB_SerialCom->setObjectName(QString::fromUtf8("CB_SerialCom"));
        CB_SerialCom->setGeometry(QRect(100, 380, 91, 32));
        CB_BaudRate = new QComboBox(centralwidget);
        CB_BaudRate->setObjectName(QString::fromUtf8("CB_BaudRate"));
        CB_BaudRate->setGeometry(QRect(100, 410, 91, 32));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(190, 380, 91, 32));
        Button_OpenCom = new QPushButton(centralwidget);
        Button_OpenCom->setObjectName(QString::fromUtf8("Button_OpenCom"));
        Button_OpenCom->setGeometry(QRect(190, 410, 91, 32));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 390, 59, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 410, 59, 16));
        Button_Send = new QPushButton(centralwidget);
        Button_Send->setObjectName(QString::fromUtf8("Button_Send"));
        Button_Send->setGeometry(QRect(30, 440, 251, 32));
        checkBox_ReciveHEX = new QCheckBox(centralwidget);
        checkBox_ReciveHEX->setObjectName(QString::fromUtf8("checkBox_ReciveHEX"));
        checkBox_ReciveHEX->setGeometry(QRect(290, 300, 86, 20));
        checkBox__SendHEX = new QCheckBox(centralwidget);
        checkBox__SendHEX->setObjectName(QString::fromUtf8("checkBox__SendHEX"));
        checkBox__SendHEX->setGeometry(QRect(390, 300, 86, 20));
        textEdit_Send = new QTextEdit(centralwidget);
        textEdit_Send->setObjectName(QString::fromUtf8("textEdit_Send"));
        textEdit_Send->setGeometry(QRect(290, 330, 311, 131));
        checkBox__SendAddEnter = new QCheckBox(centralwidget);
        checkBox__SendAddEnter->setObjectName(QString::fromUtf8("checkBox__SendAddEnter"));
        checkBox__SendAddEnter->setGeometry(QRect(490, 300, 121, 20));
        textEdit_Recive = new QTextEdit(centralwidget);
        textEdit_Recive->setObjectName(QString::fromUtf8("textEdit_Recive"));
        textEdit_Recive->setGeometry(QRect(50, 10, 551, 291));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(50, 310, 91, 32));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(190, 310, 91, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\210\267\346\226\260\344\270\262\345\217\243", nullptr));
        Button_OpenCom->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label->setText(QApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        Button_Send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        checkBox_ReciveHEX->setText(QApplication::translate("MainWindow", "HEX\346\230\276\347\244\272", nullptr));
        checkBox__SendHEX->setText(QApplication::translate("MainWindow", "HEX\345\217\221\351\200\201", nullptr));
        checkBox__SendAddEnter->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\233\236\350\275\246\346\215\242\350\241\214\347\254\246", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\224\266\351\233\206log", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\351\200\211\346\213\251\350\204\232\346\234\254", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
