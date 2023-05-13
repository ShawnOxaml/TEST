/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *cBox_SerialPortNum;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *CBox_SerialPortcheck;
    QPushButton *opencolse;
    QLabel *label;
    QLabel *label_5;
    QComboBox *cBox_SerialPortDataNum;
    QLabel *label_2;
    QComboBox *cBox_SerialPortStopBit;
    QPushButton *Con_DSable_PBT;
    QComboBox *cBox_SerialPortBaud;
    QLabel *label_6;
    QPlainTextEdit *SerialPortDataShow;
    QPlainTextEdit *SerialPortDataSend;
    QLabel *label_7;
    QLabel *label_8;
    QPushButton *bt_clearshow;
    QPushButton *bt_clearsend;
    QPushButton *bt_sendserialdata;
    QPushButton *sendddd;
    QPushButton *sendddd_2;
    QTextBrowser *textBrowser;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("#MainWindow{border-image:url(:/picture/sj2.jpg)}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cBox_SerialPortNum = new QComboBox(centralwidget);
        cBox_SerialPortNum->setObjectName(QString::fromUtf8("cBox_SerialPortNum"));
        cBox_SerialPortNum->setGeometry(QRect(560, 0, 100, 25));
        cBox_SerialPortNum->setEditable(false);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(520, 60, 85, 25));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223"));
        font.setPointSize(14);
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(520, 90, 85, 25));
        label_4->setFont(font);
        CBox_SerialPortcheck = new QComboBox(centralwidget);
        CBox_SerialPortcheck->addItem(QString());
        CBox_SerialPortcheck->addItem(QString());
        CBox_SerialPortcheck->addItem(QString());
        CBox_SerialPortcheck->setObjectName(QString::fromUtf8("CBox_SerialPortcheck"));
        CBox_SerialPortcheck->setGeometry(QRect(620, 90, 100, 25));
        opencolse = new QPushButton(centralwidget);
        opencolse->setObjectName(QString::fromUtf8("opencolse"));
        opencolse->setGeometry(QRect(560, 410, 100, 35));
        opencolse->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(500, 0, 80, 25));
        label->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(520, 120, 100, 25));
        label_5->setFont(font);
        cBox_SerialPortDataNum = new QComboBox(centralwidget);
        cBox_SerialPortDataNum->addItem(QString());
        cBox_SerialPortDataNum->addItem(QString());
        cBox_SerialPortDataNum->addItem(QString());
        cBox_SerialPortDataNum->addItem(QString());
        cBox_SerialPortDataNum->setObjectName(QString::fromUtf8("cBox_SerialPortDataNum"));
        cBox_SerialPortDataNum->setGeometry(QRect(620, 60, 100, 25));
        cBox_SerialPortDataNum->setEditable(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(520, 30, 85, 25));
        label_2->setFont(font);
        cBox_SerialPortStopBit = new QComboBox(centralwidget);
        cBox_SerialPortStopBit->addItem(QString());
        cBox_SerialPortStopBit->addItem(QString());
        cBox_SerialPortStopBit->setObjectName(QString::fromUtf8("cBox_SerialPortStopBit"));
        cBox_SerialPortStopBit->setGeometry(QRect(620, 120, 100, 25));
        Con_DSable_PBT = new QPushButton(centralwidget);
        Con_DSable_PBT->setObjectName(QString::fromUtf8("Con_DSable_PBT"));
        Con_DSable_PBT->setGeometry(QRect(680, 400, 100, 35));
        Con_DSable_PBT->setFont(font);
        cBox_SerialPortBaud = new QComboBox(centralwidget);
        cBox_SerialPortBaud->addItem(QString());
        cBox_SerialPortBaud->addItem(QString());
        cBox_SerialPortBaud->addItem(QString());
        cBox_SerialPortBaud->addItem(QString());
        cBox_SerialPortBaud->setObjectName(QString::fromUtf8("cBox_SerialPortBaud"));
        cBox_SerialPortBaud->setGeometry(QRect(620, 30, 100, 25));
        cBox_SerialPortBaud->setEditable(false);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(410, 0, 100, 20));
        label_6->setFont(font);
        SerialPortDataShow = new QPlainTextEdit(centralwidget);
        SerialPortDataShow->setObjectName(QString::fromUtf8("SerialPortDataShow"));
        SerialPortDataShow->setGeometry(QRect(30, 20, 461, 301));
        SerialPortDataSend = new QPlainTextEdit(centralwidget);
        SerialPortDataSend->setObjectName(QString::fromUtf8("SerialPortDataSend"));
        SerialPortDataSend->setGeometry(QRect(10, 350, 381, 191));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 0, 81, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(14);
        label_7->setFont(font1);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 330, 81, 21));
        label_8->setFont(font1);
        bt_clearshow = new QPushButton(centralwidget);
        bt_clearshow->setObjectName(QString::fromUtf8("bt_clearshow"));
        bt_clearshow->setGeometry(QRect(440, 370, 111, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        font2.setPointSize(12);
        bt_clearshow->setFont(font2);
        bt_clearsend = new QPushButton(centralwidget);
        bt_clearsend->setObjectName(QString::fromUtf8("bt_clearsend"));
        bt_clearsend->setGeometry(QRect(440, 410, 111, 31));
        bt_clearsend->setFont(font2);
        bt_sendserialdata = new QPushButton(centralwidget);
        bt_sendserialdata->setObjectName(QString::fromUtf8("bt_sendserialdata"));
        bt_sendserialdata->setGeometry(QRect(560, 510, 111, 28));
        bt_sendserialdata->setFont(font1);
        sendddd = new QPushButton(centralwidget);
        sendddd->setObjectName(QString::fromUtf8("sendddd"));
        sendddd->setGeometry(QRect(560, 470, 111, 28));
        sendddd->setFont(font1);
        sendddd_2 = new QPushButton(centralwidget);
        sendddd_2->setObjectName(QString::fromUtf8("sendddd_2"));
        sendddd_2->setGeometry(QRect(440, 470, 111, 28));
        sendddd_2->setFont(font1);
        textBrowser = new QTextBrowser(centralwidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 20, 741, 301));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\357\274\232", nullptr));
        CBox_SerialPortcheck->setItemText(0, QCoreApplication::translate("MainWindow", "\346\227\240", nullptr));
        CBox_SerialPortcheck->setItemText(1, QCoreApplication::translate("MainWindow", "\345\245\207\346\243\200\351\252\214", nullptr));
        CBox_SerialPortcheck->setItemText(2, QCoreApplication::translate("MainWindow", "\345\201\266\346\240\241\351\252\214", nullptr));

        opencolse->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        cBox_SerialPortDataNum->setItemText(0, QCoreApplication::translate("MainWindow", "8", nullptr));
        cBox_SerialPortDataNum->setItemText(1, QCoreApplication::translate("MainWindow", "7", nullptr));
        cBox_SerialPortDataNum->setItemText(2, QCoreApplication::translate("MainWindow", "6", nullptr));
        cBox_SerialPortDataNum->setItemText(3, QCoreApplication::translate("MainWindow", "5", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        cBox_SerialPortStopBit->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        cBox_SerialPortStopBit->setItemText(1, QCoreApplication::translate("MainWindow", "2", nullptr));

        Con_DSable_PBT->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        cBox_SerialPortBaud->setItemText(0, QCoreApplication::translate("MainWindow", "115200", nullptr));
        cBox_SerialPortBaud->setItemText(1, QCoreApplication::translate("MainWindow", "921600", nullptr));
        cBox_SerialPortBaud->setItemText(2, QCoreApplication::translate("MainWindow", "9600", nullptr));
        cBox_SerialPortBaud->setItemText(3, QCoreApplication::translate("MainWindow", "4800", nullptr));

        label_6->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\346\216\245\345\217\227\345\214\272", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        bt_clearshow->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\346\216\245\345\217\227\345\214\272", nullptr));
        bt_clearsend->setText(QCoreApplication::translate("MainWindow", "\346\270\205\351\231\244\345\217\221\351\200\201\345\214\272", nullptr));
        bt_sendserialdata->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\226\207\344\273\266", nullptr));
        sendddd->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\221\275\344\273\244\345\272\217\345\210\227", nullptr));
        sendddd_2->setText(QCoreApplication::translate("MainWindow", "iboot\350\277\233diags", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
