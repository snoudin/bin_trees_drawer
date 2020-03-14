#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "main.cpp"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    setrand();
    QString repl = "Глубина\t" + QString::number(fractal.depth) + "\n";
    repl += "Корень\t" + QString::number(fractal.root) + "\n";
    repl += "Первый потомок\t" + QString::number(fractal.len1) + "\n";
    repl += "Второй потомок\t" + QString::number(fractal.len2) + "\n";
    repl += "Угол отклонения\t" + QString::number(fractal.angle) + "\n";
    QMessageBox msg;
    msg.setText(repl);
    msg.setWindowTitle("Параметры генерации");
    msg.setStyleSheet("QMessageBox{ background-color: rgb(150, 99, 99);} QWidget{min-width: 150px; min-heigth: 100px;} QPushButton{background-color: rgb(255, 255, 255)}");
    msg.exec();

    Dialog dialog;
    dialog.setModal(true);
    build();
    dialog.exec();
}

void MainWindow::on_lineEdit_1_textChanged(const QString &arg1)
{
    if (arg1 == "") input.depth = -1;
    else input.depth = std :: min(20, arg1.toInt());
    fractal.depth = std :: min(20, arg1.toInt());
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    if (arg1 == "") input.root = -1;
    else input.root = std :: min(500, arg1.toInt());
    fractal.root = std :: min (500, arg1.toInt());
}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    if (arg1 == "") input.len1 = -1;
    else input.len1 = arg1.toInt();
    fractal.len1 = arg1.toInt();
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{
    if (arg1 == "") input.len2 = -1;
    else input.len2 = arg1.toInt();
    fractal.len2 = arg1.toInt();
}

void MainWindow::on_lineEdit_5_textChanged(const QString &arg1)
{
    if (arg1 == "") input.angle = -1;
    else input.angle = arg1.toFloat();
    fractal.angle = arg1.toFloat();
}
