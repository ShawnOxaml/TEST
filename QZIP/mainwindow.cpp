#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    compreDecompreFileThread = new CompreDecompreFileThread;
    compreDecompreFileMainThread = new QThread;

    compreDecompreFileThread->moveToThread(compreDecompreFileMainThread);
    compreDecompreFileMainThread->start();

    connect(this,&MainWindow::compress_signal,compreDecompreFileThread,&CompreDecompreFileThread::compression_file_run);
    connect(this,&MainWindow::decompress_signal,compreDecompreFileThread,&CompreDecompreFileThread::decompression_file_run);

    connect(compreDecompreFileThread,&CompreDecompreFileThread::compression_res_signal,this,&MainWindow::compress_res_slot);
    connect(compreDecompreFileThread,&CompreDecompreFileThread::decompression_res_signal,this,&MainWindow::decompress_res_slot);
    qDebug()<<QThread::currentThreadId();
}

MainWindow::~MainWindow()
{
    delete ui;
}


//bool zipReader(QString zipPath="test.zip", QString zipDir="")
//{
//    QDir tempDir;
//    if(!tempDir.exists(zipDir)) tempDir.mkpath(zipDir);
//    QZipReader reader(zipPath);
//    return reader.extractAll(zipDir);
//}

void MainWindow::on_btnZip_clicked()
{
    QString filePath = "E:/unziptest.zip";     //原目标
    QString zipPath = "E:/迅雷下载";           //目标文件

    emit compress_signal(filePath,zipPath);

}


void MainWindow::on_btnUnZip_clicked()
{
    QString filePath = "E:/unziptest.zip";
    QString zipPath = "E:/迅雷下载";

    qDebug()<<"filePath:"<<filePath<<"zipPath:"<<zipPath;

    emit decompress_signal(filePath,zipPath);
}

void MainWindow::compress_res_slot(CompreDecompreFileThread::ResultE res, quint8 progress, QString remarks)
{
    qDebug()<<"Com:"<<"  res:"<<res<<"  progress:"<<progress<<"  remarks:"<<remarks;
}

void MainWindow::decompress_res_slot(CompreDecompreFileThread::ResultE res, quint8 progress, QString remarks)
{
    qDebug()<<"deCom:"<<"  res:"<<res<<"  progress:"<<progress<<"  remarks:"<<remarks;
}
