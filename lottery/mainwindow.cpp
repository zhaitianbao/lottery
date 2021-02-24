#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer_control = new QTimer(this);//����������ʱ��

    QFont font1("Microsoft YaHei", 30,25);
    QFont font2("Fantasy",20);
    ui->label_title->setFont(font1);
    ui->label_name->setFont(font2);
    ui->label_title->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label_name->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->label_title->setText(QString::fromLocal8Bit("ztb-���׳齱ϵͳ"));
    ui->label_name->setText(QString::fromLocal8Bit("�齱��Ա"));


    QFile file(":/txt/people.txt");
    if (file.open(QFile::ReadOnly))//��ֻ���ķ�ʽ��student.txt�ļ�
    {
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        while(!stream.atEnd())
        {
            QString str=stream.readLine();
            strlist.append(str);//���ļ����ݷŵ�strlist��
        }
        file.close();
    }else
    {
        QMessageBox::critical(this, tr("����"), file.errorString());
        exit(0);
    }

    ui->pushButton_control->setText(QString::fromLocal8Bit("��ʼ"));
    connect(ui->pushButton_control,SIGNAL(clicked()),this,SLOT(control()));
    connect(timer,SIGNAL(timeout()),this,SLOT(on_time()));

    connect(timer_control, SIGNAL(timeout()), timer, SLOT(stop()));//�����ɼ� ���ѭ��ʱ��

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
        ui->pushButton_control->setText(QString::fromLocal8Bit("ֹͣ"));//���statusΪtrue,���ð�ť����Ϊ��ֹͣ��
        timer->start(200);//������ʱ��,��ʱִ��һ��on_timer����
        status = false;
    }else
    {
        ui->pushButton_control->setText(QString::fromLocal8Bit("��ʼ"));//���statusΪfalse,���ð�ť����Ϊ����ʼ��
        timer->stop();//ֹͣ��ʱ��
        status = true;
    }

}

void MainWindow::on_time()
{
    if (strlist.count() == 0)
    {
        return ;//���strlist��û�����ݣ���������
    }

    int i= rand()%strlist.count();
    qDebug()<<i;
    ui->label_name->setText(strlist[i]);

}
