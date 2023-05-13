#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCodec>
#include <QMessageBox>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug()<<QSqlDatabase::drivers();

    setWindowTitle("MySql");
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());//设置显示中文

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("test");
    db.setUserName("root");
    db.setPassword("123456");

    if(!db.open()) //如果数据库打开失败，会弹出一个警告窗口
    {
        QMessageBox::warning(this, "警告", "数据库打开失败");
    }
    else
    {
        ui->textEdit->setText("数据库打开成功");
    }




}

MainWindow::~MainWindow()
{
    delete ui;
}

