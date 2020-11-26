#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"
#include "QFileDialog"
#include "encrypt.h"


using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    std::string url = QFileDialog::getOpenFileName().toStdString();
    char *temp;
    strcpy(temp, url.c_str());
    encrypt *win = new encrypt(this, temp);
    win -> show();
    this->hide();
}
