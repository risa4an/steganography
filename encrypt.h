#ifndef ENCRYPT_H
#define ENCRYPT_H

#include <QDialog>
#include "steganography.h"

namespace Ui {
class encrypt;
}

class encrypt : public QDialog
{
    Q_OBJECT

public:
    explicit encrypt(QWidget *parent = nullptr, char* url = nullptr);
    ~encrypt();
    steganography img;


private slots:


    void on_label_linkActivated(const QString &link);

private:
    Ui::encrypt *ui;
    std::string text;

};

#endif // ENCRYPT_H
