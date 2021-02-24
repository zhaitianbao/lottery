#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QByteArray>
#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <QMessageBox>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void control();
    void on_time();
private:
    Ui::MainWindow *ui;
    QTimer * timer;
    QTimer * timer_control;
    QStringList strlist;
};
#endif // MAINWINDOW_H
