#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <string>
#include <QProcess>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include <QString>
#include <QFile>
#include <QTextStream>

QString RaudRate[13]={"110","300","600","1200","2400","4800","9600","14400","19200",
                     "38400","56000","57600","115200"};
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *label = new QLabel(this);
    label->setAlignment(Qt::AlignHCenter);

    for(int i=0;i<13;i++)
    {
       ui->CB_BaudRate->addItem(RaudRate[i]);
    }
    label->setText("Hellw World");
}









void MainWindow::on_pushButton_clicked()
{
    QString tempstr;
    ui->CB_SerialCom->clear();
    //运行开始查找可用串口
    foreach(const QSerialPortInfo&info,QSerialPortInfo::availablePorts())
    {
//串口号下拉菜单，增加一个条目
       ui->CB_SerialCom->addItem(info.portName());
    }
}

//初始化并打开串口
void MainWindow::on_Button_OpenCom_clicked()
{
    QSerialPort serial;

    QTimer *timerSerial;
    timerSerial = new QTimer(this);
    if(this->ui->Button_OpenCom->text()=="打开串口")//初始状态，配置串口参数
           {
              serial.setPortName(ui->CB_SerialCom->currentText());//设置串口号、
              serial.setBaudRate(ui->CB_BaudRate->currentText().toInt());//设置波特率
              serial.setDataBits(QSerialPort::Data8);//设置串口数据位8
              serial.setParity(QSerialPort::NoParity);//无校验位
              serial.setStopBits(QSerialPort::OneStop);//1位停止位
              serial.setFlowControl(QSerialPort::NoFlowControl);
              if(!serial.open(QIODevice::ReadWrite))
              {
                 QMessageBox::critical(NULL,"提示","串口打开失败");
                 return;
              }
              ui->Button_Send->setEnabled(true);//串口打开成功，使能发送按钮
              ui->Button_OpenCom->setText("关闭串口");
              //创建定时器，定时接收串口数据
               //QTimer *timerSerial = new QTimer(this);
              connect(timerSerial,SIGNAL(timeout()),this,SLOT(TimerUpdate()));
              timerSerial->start(30); //若超过30毫秒没有数据更新，则认为一帧接收完成
           }
           else
           {
              serial.close();
              ui->Button_Send->setEnabled(0);//串口关闭，使能发送按钮
              timerSerial->stop();
              this->ui->Button_OpenCom->setText("打开串口");
           }
}





void MainWindow::on_Button_Send_clicked()
{

            QString SendString;
            QString SendStringHEX;
            QSerialPort serial;

            int len=0;

            QDateTime timeCurrent = QDateTime::currentDateTime();//获取系统时间
            QString time = timeCurrent.toString("[yy-MM-dd hh:mm:ss.zzz]");

            SendString=ui->textEdit_Send->toPlainText();//获取发送文本框字符
            //检查是否添加回车换行
            if(ui->checkBox__SendAddEnter->isChecked())
            {
                SendString+="\r\n";
            }
            //检查是否HEX格式发送
            if(ui->checkBox__SendHEX->isChecked())//发送格式为HEX
           {
               //HEX格式转化为ASCII字符串
              /* if(!HextoString(SendString,&SendStringHEX))
               {
                    QMessageBox::critical(NULL,"提示","非法字符");
                    return;
               }*/
               serial.write(SendStringHEX.toLatin1());//发送数据至串口
               //检查显示格式
               if(ui->checkBox_ReciveHEX->isChecked())//显示格式为HEX
               {
                  len = SendString.length();
                  for(int i=0;i<len/2;i++)
                  {
                      SendString.insert((i+1)*2+i," ");
                  }
                  ui->textEdit_Recive->append( time+"发->"+SendString);
               }
               else
               {
                   ui->textEdit_Recive->append( time+"发->"+SendStringHEX);
               }
           }
           else//发送格式为字符串
          {
               serial.write(SendString.toLatin1());//发送数据
             if(ui->checkBox_ReciveHEX->isChecked())//显示格式为HEX
             {
                 SendString=QString::fromLocal8Bit(SendString.toLatin1().toHex().toUpper());
                 len = SendString.length();
                 for(int i=0;i<len/2;i++)
                 {
                    SendString.insert((i+1)*2+i," ");
                 }
            }
            ui->textEdit_Recive->append( time+"发->"+SendString);
         }


}
void MainWindow::TimerUpdate()
{
     QSerialPort serial;
     QByteArray rx_buf = serial.readAll();//读取串口接收的数据;
     int len;
     static QByteArray sumData;
     QString DataString;
     if (!rx_buf.isEmpty())//串口接收字符不为空
     {
         sumData.append(rx_buf);//将收到字符拼接
     }
     else if(!sumData.isEmpty())//累计字符不为空
     {
         QDateTime timeCurrent = QDateTime::currentDateTime();//获取系统时间
         QString time = timeCurrent.toString("[yy-MM-dd hh:mm:ss.zzz]");
         rx_buf.clear();
         DataString=QString::fromLocal8Bit(sumData);
         //检查是否HEX格式显示
         if(ui->checkBox_ReciveHEX->isChecked())//HEX格式显示
         {
            DataString=QString::fromLocal8Bit(sumData.toHex().toUpper());
            len = DataString.length();
            for(int i=0;i<len/2;i++)
            {
                DataString.insert((i+1)*2+i," ");
            }
          }
          ui->textEdit_Recive->append(time+"收<-"+DataString);
          sumData.clear();
        }
}


void MainWindow::on_pushButton_2_clicked()
{

        //将文本框数据取出并按行排列
        QFile file("/Users/sw/qtoxaml/log.txt");//文件命名
        if (!file.open(QFile::WriteOnly | QFile::Text))     //检测文件是否打开
        {
            QMessageBox::information(this, "Error Message", "Please Select a Text File!");
            return;
        }
        QTextStream out(&file);                 //分行写入文件
        out << ui->textEdit_Recive->toPlainText();


}

MainWindow::~MainWindow()
{
    delete ui;
}



