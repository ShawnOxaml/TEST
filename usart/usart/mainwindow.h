#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QMessageBox>
#include <QtSerialPort/QSerialPort>         //提供访问串行端口的功能
#include <QtSerialPort/QSerialPortInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void init(void);

private slots:
    void serialPort_getdata();
    void timer_serialsendandreceiveEvent();

    void on_bt_clearshow_clicked();
    void on_bt_clearsend_clicked();
    void on_bt_sendserialdata_clicked();

    void on_opencolse_clicked();
    void on_bt_clearsend_2_clicked();
    void on_bt_clearsend_3_clicked();
};
#endif // MAINWINDOW_H
