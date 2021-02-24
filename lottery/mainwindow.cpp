#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer_control = new QTimer(this);//声明两个定时器

    QFont font1("Microsoft YaHei", 30,25);
    QFont font2("Fantasy",20);
    ui->label_title->setFont(font1);
    ui->label_name->setFont(font2);
    ui->label_title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label_name->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label_title->setText(QString::fromLocal8Bit("ztb-简易抽奖系统"));
    ui->label_name->setText(QString::fromLocal8Bit("抽奖人员"));


    QFile file(":/txt/people.txt");
    if (file.open(QFile::ReadOnly))//以只读的方式打开student.txt文件
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        while(!stream.atEnd())
        {
            QString str=stream.readLine();
            strlist.append(str);//将文件内容放到strlist中
        }
        file.close();
    }else
    {
        QMessageBox::critical(this, tr("错误"), file.errorString());
        exit(0);
    }

    ui->pushButton_control->setText(QString::fromLocal8Bit("开始"));
    connect(ui->pushButton_control,SIGNAL(clicked()),this,SLOT(control()));
    connect(timer,SIGNAL(timeout()),this,SLOT(on_time()));

    connect(timer_control, SIGNAL(timeout()), timer, SLOT(stop()));//后续可加 随机循环时间

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::control()
{
    static bool status = true;
    if (status)
    {
        ui->pushButton_control->setText(QString::fromLocal8Bit("停止"));//如果status为true,设置按钮标题为“停止”
        timer->start(200);//启动计时器,定时执行一次on_timer函数
        status = false;
    }else
    {
        ui->pushButton_control->setText(QString::fromLocal8Bit("开始"));//如果status为false,设置按钮标题为“开始”
        timer->stop();//停止计时器
        status = true;
    }

}

void MainWindow::on_time()
{
    if (strlist.count() == 0)
    {
        return ;//如果strlist中没有内容，函数返回
    }

    int i= rand()%strlist.count();
    qDebug()<<i;
    ui->label_name->setText(strlist[i]);

}
