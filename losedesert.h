#ifndef LOSEDESERT_H
#define LOSEDESERT_H

#include <QDialog>

namespace Ui {
class losedesert;
}

class losedesert : public QDialog
{
    Q_OBJECT

public:
    explicit losedesert(QWidget *parent = nullptr);
    ~losedesert();

private:
    Ui::losedesert *ui;
};

#endif // LOSEDESERT_H
