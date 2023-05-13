#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <QFileDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QBrush>

#include <QStringList>



QTimer *timer=nullptr;
QByteArray buffer_Serial;
QByteArray str_buffer_Serial;
QSerialPort* serialbasic=nullptr;       //全局的串口通信对象


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    //静止最大化按钮
    setFixedSize(this->width(),this->height());                     //固定窗口大小

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_serialsendandreceiveEvent()));
    timer->start(10);

    serialbasic = new QSerialPort();
    //添加蛇姐背景图
    QWidget w;
    w.setAutoFillBackground(true);
    QPalette palette;
    QPixmap pixmap("qrc:/a/27.jpg");
    palette.setBrush(QPalette::Window,QBrush(pixmap));
    w.setPalette(palette);
    w.show();

    init();
}

//初始化界面 端口号设置tty.usbmode 115200波特率 8数据位 无校验位 1停止位

/*void MainWindow::init(void)
{
    QList<QSerialPortInfo> comList = QSerialPortInfo::availablePorts();//获取可用串口列表

    ui->cBox_SerialPortNum->clear();//清空item，避免搜索后重复添加
    ui->cBox_SerialPortBaud->clear();
    ui->CBox_SerialPortcheck->clear();
    ui->cBox_SerialPortStopBit->clear();
    ui->cBox_SerialPortDataNum->clear();

    if(comList.isEmpty())//若没有可用串口，则发送警告
    {
        QMessageBox::warning(this,"Waring!","There's no avalible COM to use, plese check your serialport!");
    }
    else//将可用串口显示到comboBox上以供选择
    {
        for(int i = 0; i < comList.size(); i ++)
        {
            ui->cBox_SerialPortNum->addItem(comList[i].portName());
            //ui->cBox_SerialPortNum->addItem(comList[i].description());//设备描述
        }
    }

    QStringList baudRateList = QStringList() << "1200" << "2400" << "4800"
                                             << "9600" << "14400" << "19200" << "38400" << "43000" << "57600"
                                             << "76800" << "115200" << "128000" << "230400" << "256000" <<"460800"
                                             << "921600" << "1382400";
    QStringList parityList = QStringList() << "无" << "奇校验" << "偶校验";
    QStringList stopBitsList = QStringList() << "1" << "1.5" << "2";
    QStringList dataBitsList = QStringList() << "8" << "7" << "6" << "5";

    ui->cBox_SerialPortBaud->addItems(baudRateList);
    ui->CBox_SerialPortcheck->addItems(parityList);
    ui->cBox_SerialPortStopBit->addItems(stopBitsList);
    ui->cBox_SerialPortDataNum->addItems(dataBitsList);
    ui->cBox_SerialPortBaud->setCurrentIndex(10);//设置115200为默认选项


}*/
//设置串口数据
void MainWindow::on_opencolse_clicked()
{
    if(ui->opencolse->text()=="打开串口")
    {
        serialbasic->setPortName(ui->cBox_SerialPortNum->currentText());//设置串口
        serialbasic->setBaudRate(ui->cBox_SerialPortBaud->currentText().toInt());
        serialbasic->setParity(QSerialPort::NoParity);//无校验
        serialbasic->setDataBits(QSerialPort::Data8);//8数据位
        serialbasic->setStopBits(QSerialPort::OneStop);//1停止位

        serialbasic->setFlowControl(QSerialPort::NoFlowControl); //无流控
        serialbasic->setReadBufferSize(8192);                    //数据缓冲区长度
        bool bOK = serialbasic->open(QIODevice::ReadWrite);
        if(!bOK)
        {
            //qDebug("test is ok");
            QMessageBox::critical(this,"提示","无法打开串口，请检查是否被占用。",QMessageBox::Yes,QMessageBox::Yes);
            return;
        }
        connect(serialbasic,SIGNAL(readyRead()),this,SLOT(serialPort_getdata()),Qt::DirectConnection);//连接串口接收信号与槽函数

        ui->cBox_SerialPortNum->setEnabled(false);
        ui->cBox_SerialPortBaud->setEnabled(false);
        ui->CBox_SerialPortcheck->setEnabled(false);
        ui->cBox_SerialPortDataNum->setEnabled(false);
        ui->cBox_SerialPortStopBit->setEnabled(false);

        ui->opencolse->setText("关闭串口");
    }
    else
    {
        ui->opencolse->setText("打开串口");
        serialbasic->close();
        delete serialbasic;

        ui->cBox_SerialPortNum->setEnabled(true);
        ui->cBox_SerialPortBaud->setEnabled(true);
        ui->CBox_SerialPortcheck->setEnabled(true);
        ui->cBox_SerialPortDataNum->setEnabled(true);
        ui->cBox_SerialPortStopBit->setEnabled(true);
    }
}

//初始化界面 端口号设置tty.usbmode 115200波特率 8数据位 无校验位 1停止位
void MainWindow::init(void)
{
    QList<QSerialPortInfo> comList = QSerialPortInfo::availablePorts();//获取可用串口列表

    ui->cBox_SerialPortNum->clear();//清空item，避免搜索后重复添加
    ui->cBox_SerialPortBaud->clear();
    ui->CBox_SerialPortcheck->clear();
    ui->cBox_SerialPortStopBit->clear();
    ui->cBox_SerialPortDataNum->clear();

    if(comList.isEmpty())//若没有可用串口，则发送警告
    {
        QMessageBox::warning(this,"Waring!","There's no avalible COM to use, plese check your serialport!");
    }
    else//将可用串口显示到comboBox上以供选择
    {
        for(int i = 0; i < comList.size(); i ++)
        {
            ui->cBox_SerialPortNum->addItem(comList[i].portName());
            //ui->cBox_SerialPortNum->addItem(comList[i].description());//设备描述
        }
    }


    QStringList baudRateList = QStringList() << "115200";
    QStringList parityList = QStringList() << "无";
    QStringList stopBitsList = QStringList() << "1";
    QStringList dataBitsList = QStringList() << "8";

    ui->cBox_SerialPortBaud->addItems(baudRateList);
    ui->CBox_SerialPortcheck->addItems(parityList);
    ui->cBox_SerialPortStopBit->addItems(stopBitsList);
    ui->cBox_SerialPortDataNum->addItems(dataBitsList);

}

void MainWindow::timer_serialsendandreceiveEvent()
{
    QByteArray bufferHex = str_buffer_Serial.toHex();//转换成hex
    bufferHex=bufferHex.toUpper();//转换成大写
    QString str_buffer1;
       str_buffer1 = QString(str_buffer_Serial);
    if(ui->opencolse->text()=="关闭串口")
    {
       ui->SerialPortDataShow->insertPlainText(str_buffer1);
       ui->SerialPortDataShow->moveCursor(QTextCursor::End);
    }
    str_buffer1=ui->SerialPortDataShow->toPlainText();
    if(str_buffer1.size()>10000) ui->SerialPortDataShow->clear();

    str_buffer_Serial.clear();
}
void MainWindow::on_bt_clearshow_clicked()
{
    ui->SerialPortDataShow->clear();
}

void MainWindow::on_bt_clearsend_clicked()
{
    ui->SerialPortDataSend->clear();
}


//获取接收
void MainWindow::serialPort_getdata()
{


    qint64 byteLen_now = serialbasic->bytesAvailable();
    if(byteLen_now <= 0)
    {
        return;
    }

    buffer_Serial+=serialbasic->readAll();
    str_buffer_Serial+=buffer_Serial;

    //ui->SerialPortDataShow->appendPlainText(str_buffer_Serial);
    ui->textBrowser->append(str_buffer_Serial);
    //写入文件观察结果  记录log
    QString str = str_buffer_Serial;
    QString fileName111 = "/Users/sw/Desktop/欧明记/12345.txt";
    QFile file(fileName111);
    if(!file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append))
    {
        QMessageBox::warning(this,"sdf","can't open",QMessageBox::Yes);
    }
    QTextStream stream(&file);
    stream<<str;
    file.close();
    buffer_Serial.clear();



    /*char BUF[512] = {0};                                       // 存储转换类型后的数据
        QByteArray data = serialbasic->readAll();                      // 读取数据

        if(!data.isEmpty())                                 // 接收到数据
        {
            QString str = ui->SerialPortDataShow->toPlainText();  // 返回纯文本
            str += tr(data);                                // 数据是一行一行传送的，要保存所有数据
            ui->SerialPortDataShow->clear();                      // 清空之前的数据
            ui->SerialPortDataShow->appendPlainText(str);                  // 将数据放入控件中
            qDebug() << "str info: " << ui->SerialPortDataShow->toPlainText();

             // 清除之前的数据，防止追加，因为每次获取的数据不一样
            int index = str.indexOf("\r\n");               // 找到，返回索引值，找不到，返回-1
            if(index != -1)
            {
                snprintf(BUF,500,"%s", str.left(index + 2).toUtf8().data()); // QString转为char * 类型
                qDebug() << "BUF info: " << BUF;
                str.remove(0,index + 2);
                // 处理获取到的数据，将其放入对应的控件中
            }

            if(str.contains(":-)"))
            {
                data =NULL;
            }
        }*/
}
//发送窗口的文本数据
/*void MainWindow::on_bt_sendserialdata_clicked()
{

   //①从本地文件逐行取出命令：
    QString path =QFileDialog::getOpenFileName(this,"open","../","*.txt");
    if(path.isEmpty() == false)
    {
        //文件对象
        QFile file(path);
        //打开文件只读方式
        bool bRet  =file.open(QIODevice::ReadOnly);
                if(bRet == true)
                {
                    //方法1
        //            //读文件
        //            QByteArray array = file.readAll();
        //            //显示到编辑器
        //            ui->textEdit->setText(QString(array));

                    //方法2：一行一行度

                    QByteArray array ;
                    while(file.atEnd() == false)//判断是否到文件末尾
                    {
                        //读一行
                        array += file.readLine();
                    }
                    //array=array+"/n";
                    ui->SerialPortDataSend->setPlainText(array);
                }
                file.close();
    }

}
*/


//发送选中的命令序列
void MainWindow::on_sendddd_clicked()
{
    QString command = ui->SerialPortDataSend->toPlainText();//从发送窗口取出文本
    command=command+"\n";

    serialbasic->write(command.toUtf8().data());//以字符形式发送

    /*if(ui->cb_sendhex->isChecked())
    {
        QStringList commadList = command.split(' ');//寻找空格把字符串分开成字符
        QByteArray byteArray;
        byteArray.resize(commadList.count());//初始化新数组
        bool ok = false;
        for(int i = 0; i < commadList.count(); i++)
        {
            byteArray[i]=(char)commadList.at(i).toInt(&ok,16);
        }
        //加一个判断 获取接收框的文本信息，有diags的标志信息才可以继续发送下一条命令发送的时候循环判断发送
        QString sign = ui->SerialPortDataShow->toPlainText();
        if(sign.contains(":-)",Qt::CaseSensitive))
        {
        qDebug()<<byteArray;
        serialbasic->write(byteArray);//以16进制形式发送
        }
    }
    else
    {
        //加一个判断 获取接收框的文本信息，有diags的标志信息才可以继续发送下一条命令发送的时候循环判断发送
        QString sign = ui->SerialPortDataShow->toPlainText();
        if(sign.contains(":-)",Qt::CaseSensitive))
        {
        qDebug()<<command.toUtf8().data();
        serialbasic->write(command.toUtf8().data());//以字符形式发送
        }
     }*/
}

//初始化进diags
void MainWindow::on_sendddd_2_clicked()
{


}




void MainWindow::on_bt_sendserialdata_clicked()
{

    //打开文件
    QString fileName = QFileDialog::getOpenFileName(this,QStringLiteral("文件对话框！"),"F:",QStringLiteral("本本文件(*txt)"));
    QString line;
    QString line2;
     QString line3;
    //要读取的文本
    QFile file(fileName); //文件路径

    //要写入 的文本
    QFile filewrite("D:/Users/hi/Desktop/命令提取.txt");
    QTextStream txtOutput(&filewrite);
    //正则表达式匹配

    if(!filewrite.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << ("打开文件失败");
    }

    qDebug()<<fileName;
    bool isok=file.open(QIODevice::ReadOnly | QIODevice::Text);
     if(isok==true)
    {
     qDebug()<<"文件打开成功";
    QTextStream in(&file);  //用文件构造流



    line = in.readLine();//读取一行放到字符串里


    while(!line.isNull())//字符串有内容
    {

            line2=line;						//每次读一行line2都回归 和line同一行的位置再往下读一行

            if(line.contains("Item"))			//此行含有测试项
            {
                  line = in.readLine();//读取一行放到字符串里


                if(line.contains("(TX ==> Dut)"))		//此行含有该发送命令
                //txtOutput<<line<<endl;
                {
                txtOutput<<line2<<endl;						//写入line的内容，也就是测试项的名字
                }
            }
            if(line.contains("(TX ==> Dut)"))				//line没有受到影响	继续循环寻找到发送的命令打印发送
            {
            qDebug()<<qPrintable(line.mid(40,-1));
            txtOutput<<line.mid(40,-1)<<endl;
            txtOutput<<line<<endl;

            }
            line=in.readLine();								//循环读取文件内容下一行
    }


    }




     file.close();					//读取命令行关闭
     filewrite.close();				//写入文件关闭




}

MainWindow::~MainWindow()
{
    delete ui;
}
