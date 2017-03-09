#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString id = ui->textEdit->toPlainText();
    if(id == "") return;
    //算法加密
    if(pd != "") ui->textBrowser_2->clear();
    ui->textBrowser_2->append(pd);
}
