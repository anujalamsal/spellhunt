#ifndef WINDESERT_H
#define WINDESERT_H

#include <QDialog>

namespace Ui {
class windesert;
}

class windesert : public QDialog
{
    Q_OBJECT

public:
    explicit windesert(QWidget *parent = nullptr);
    ~windesert();

private:
    Ui::windesert *ui;
};

#endif // WINDESERT_H
