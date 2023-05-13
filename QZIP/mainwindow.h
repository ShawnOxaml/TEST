#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtGui/private/qzipreader_p.h"
#include "QtGui/private/qzipwriter_p.h"

#include <QFileInfoList>
#include <QDir>
#include <QFile>

#include "compredecomprefilethread.h"

#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void compress_signal(QString srcPath,QString destPath);
    void decompress_signal(QString srcPath,QString destPath);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnZip_clicked();

    void on_btnUnZip_clicked();

    void compress_res_slot(CompreDecompreFileThread::ResultE res,quint8 progress,QString remarks = nullptr);
    void decompress_res_slot(CompreDecompreFileThread::ResultE res,quint8 progress,QString remarks = nullptr);

private:
    Ui::MainWindow *ui;
    CompreDecompreFileThread *compreDecompreFileThread;
    QThread *compreDecompreFileMainThread;

};
#endif // MAINWINDOW_H
