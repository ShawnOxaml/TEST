#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort> //提供访问串口的功能
#include <QtSerialPort/QSerialPortInfo> //提供系统中存在的串口信息

#include <QKeyEvent>        //键盘事件头文件
#include <QTimer>
#include <QTime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //窗口类中加入初始化串口函数声明
    bool serialport_init();
    void keyPressEvent(QKeyEvent *);    //覆写键盘函数


private:
    Ui::MainWindow *ui;
    //串口通信
    QSerialPort* m_serialport;
    //计时
    QTimer * timer;
    QTime * TimeRecord;


private slots:
    //窗口类中加入槽函数
    void send_data();   //发送串口数据
    void receive_data();    //接收串口数据
    void open_serialport();  //串口开启/关闭

    //计时器
    void initTime();
    void updateTime();
    void on_pushButton_3_clicked();
};
#endif // MAINWINDOW_H
