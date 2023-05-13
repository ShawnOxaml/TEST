#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_serialport = new QSerialPort();
    serialport_init();
    connect(m_serialport,SIGNAL(readyRead()),this,SLOT(receive_data()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(send_data()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(open_serialport()));

    //计时器ui
    timer = new QTimer;
    TimeRecord = new QTime;
    ui->Timer->setDigitCount(8);
    initTime();     //令LCD显示00:00:00
    //连接槽函数，将timer的timeout行为，连接到updateTime函数中
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    //当点击(clicked)pbStart时，调用函数pbStart_clicked
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(pbStart_clicked()));




}

bool MainWindow::serialport_init()
{
    //获得所有可用端口列表
    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();
    if(serialPortInfoList.isEmpty()){
        return false;
    }
    QList<QSerialPortInfo>::iterator iter = serialPortInfoList.begin();
    //将所有端口添加到界面的下拉列表中
    while(iter!=serialPortInfoList.end()){
        ui->comboBox->addItem(iter->portName());
        iter++;
    }
    return true;
}

void MainWindow::open_serialport()
{
    //判断串口开启状态
    if(m_serialport->isOpen()){
        //若串口已经打开，则关闭它，设置指示灯为红色，设置按钮显示“打开串口”
        m_serialport->clear();
        m_serialport->close();
        ui->label->setStyleSheet("background-color:rgb(255,0,0);border-radius:12px;");
        ui->pushButton_2->setText("打开串口");
        return;
    }else{
         //若串口没有打开，则打开选择的串口，设置指示灯为绿色，设置按钮显示“关闭串口”
        m_serialport->setPortName(ui->comboBox->currentText());
        m_serialport->open(QIODevice::ReadWrite);
        m_serialport->setBaudRate(QSerialPort::Baud115200);
        m_serialport->setDataBits(QSerialPort::Data8);
        m_serialport->setParity(QSerialPort::NoParity);
        m_serialport->setStopBits(QSerialPort::OneStop);
        m_serialport->setFlowControl(QSerialPort::NoFlowControl);
        ui->label->setStyleSheet("background-color:rgb(0,255,0);border-radius:12px;");
        ui->pushButton_2->setText("关闭串口");
    }

}

void MainWindow::receive_data()
{
    QByteArray message;
    message.append(m_serialport->readAll());
    //使textEdit控件追加显示接收到的数据
    ui->textEdit->append(message);
}

void MainWindow::send_data()
{
    QString message = ui->lineEdit->text();
    QByteArray messageSend;
    messageSend.append(message);
    m_serialport->write(messageSend);
}


//==================================================================
//函 数 名：keyPressEvent
//功能描述：按键事件检测（回车）
//输入参数：QKeyEvent *
//返 回 值：无
//日    期：2023.4.17
//修改记录：2023.4.17
//==================================================================
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Return:
    case Qt::Key_Enter:
    {
        send_data();
    }
        break;
     default:
        break;
    }
}



MainWindow::~MainWindow()
{
    delete ui;
}

//==================================================================
//函 数 名：initTime
//功能描述：复位重设
//输入参数：NONE
//返 回 值：无
//修改记录：2023.4.17
//==================================================================

void MainWindow::initTime(){
    TimeRecord->setHMS(0, 0, 0); //时间复位为0
    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
}

//==================================================================
//函 数 名：updateTime
//功能描述：更新时间
//输入参数：NONE
//返 回 值：无
//修改记录：2023.4.17
//==================================================================

void MainWindow::updateTime(){
    //每次更新时间，TimeRecord增加1
    *TimeRecord = TimeRecord->addSecs(1);
    ui->Timer->display(TimeRecord->toString("hh:mm:ss"));
}

//==================================================================
//函 数 名：on_pushButton_3_clicked
//功能描述：按钮触发事件
//输入参数：NONE
//返 回 值：无
//修改记录：2023.4.17
//==================================================================

void MainWindow::on_pushButton_3_clicked()
{
    if (QString::compare(ui->pushButton_3->text(),"stop")){
        //当按钮内容不为'stop'时，说明开启计时
        timer->start(1000);
        ui->pushButton_3->setText("stop");//计时开始后，按钮变为'stop'
    }else{
        timer->stop();
        ui->pushButton_3->setText("start");
        initTime();

    }
}
