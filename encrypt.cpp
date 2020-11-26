#include "encrypt.h"
#include "ui_encrypt.h"
#include "string"
#include "steganography.h"

encrypt::encrypt(QWidget *parent, char* url) : img(url),
    QDialog(parent),
    ui(new Ui::encrypt)
{
    ui->setupUi(this);
}

encrypt::~encrypt()
{
    delete ui;
}



void encrypt::on_label_linkActivated(const QString &link)
{
    ui -> label -> setPixmap(QPixmap(img.url));
}
