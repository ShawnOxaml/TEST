#include "mainwindow.h"
#include "ui_mainwindow.h"

QTimer *timer=nullptr;
QByteArray buffer_Serial;
QByteArray str_buffer_Serial;
QSerialPort* serialbasic=nullptr;

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
    init();
}

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


}
void MainWindow::timer_serialsendandreceiveEvent()
{
    QByteArray bufferHex = str_buffer_Serial.toHex();//转换成hex
    bufferHex=bufferHex.toUpper();//转换成大写
    QString str_buffer1;

    if(ui->cb_rechex->isChecked())//16进制显示
    {
      str_buffer1 = QString(bufferHex);//转换成字符
      for(int i = str_buffer1.count(); i > 0; i = i-2)
      {
        str_buffer1.insert(i," ");
      }
    }
    else//字符形式显示
    {
       str_buffer1 = QString(str_buffer_Serial);
    }
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

void MainWindow::on_opencolse_clicked()
{
    if(ui->opencolse->text()=="打开串口")
    {
        serialbasic->setPortName(ui->cBox_SerialPortNum->currentText());//设置串口
        serialbasic->setBaudRate(ui->cBox_SerialPortBaud->currentText().toInt());

        switch(ui->CBox_SerialPortcheck->currentIndex())//设置数据校验形式
        {
            case 0:
                serialbasic->setParity(QSerialPort::NoParity);//无校验
                break;
            case 1:
                serialbasic->setParity(QSerialPort::OddParity);//奇校验
                break;
            case 2:
                serialbasic->setParity(QSerialPort::EvenParity);//偶校验
                break;
            default:
                serialbasic->setParity(QSerialPort::NoParity);
                break;
        }
        switch(ui->cBox_SerialPortDataNum->currentIndex())//设置数据位
        {
            case 0:
                serialbasic->setDataBits(QSerialPort::Data8);
                break;
            case 1:
                serialbasic->setDataBits(QSerialPort::Data7);
                break;
            case 2:
                serialbasic->setDataBits(QSerialPort::Data6);
                break;
            case 3:
                serialbasic->setDataBits(QSerialPort::Data5);
                break;
            default:
                serialbasic->setDataBits(QSerialPort::Data8);
                break;
        }
        switch(ui->cBox_SerialPortStopBit->currentIndex())//设置停止位
        {
            case 0:
                serialbasic->setStopBits(QSerialPort::OneStop);
                break;
            case 1:
                serialbasic->setStopBits(QSerialPort::OneAndHalfStop);
                break;
            case 2:
                serialbasic->setStopBits(QSerialPort::TwoStop);
                break;
            default:
                serialbasic->setStopBits(QSerialPort::OneStop);
                break;
        }
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

void MainWindow::serialPort_getdata()
{
    //qDebug("getdata");
    qint64 byteLen_now = serialbasic->bytesAvailable();
    if(byteLen_now < 0)
    {
        return;
    }
    //qDebug()<<"当前缓存长度"<<byteLen_now<<endl;

    buffer_Serial+=serialbasic->readAll();

    QByteArray bufferHex = buffer_Serial.toHex();//转换成hex
    bufferHex=bufferHex.toUpper();//转换成大写
    str_buffer_Serial+=buffer_Serial;

    //ui->SerialPortDataShow->append(str_buffer_Serial);
    //QString str_buffer = QString(buffer_Serial);

    QString str_buffer = QString(bufferHex);//转换成字符
    for(int i = str_buffer.count(); i > 0; i = i-2)
    {
      str_buffer.insert(i," ");
    }

    buffer_Serial.clear();
}

void MainWindow::on_bt_sendserialdata_clicked()
{
    QString command = ui->SerialPortDataSend->toPlainText();//从发送窗口取出文本
    if(ui->cb_sendhex->isChecked())
    {
        QStringList commadList = command.split(' ');//寻找空格把字符串分开成字符
        QByteArray byteArray;
        byteArray.resize(commadList.count());//初始化新数组
        bool ok = false;
        for(int i = 0; i < commadList.count(); i++)
        {
            byteArray[i]=(char)commadList.at(i).toInt(&ok,16);
        }
        serialbasic->write(byteArray);//以16进制形式发送
    }
    else
    {
        serialbasic->write(command.toUtf8().data());//以字符形式发送
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

