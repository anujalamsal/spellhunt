#ifndef WIN_H
#define WIN_H

#include <QDialog>

namespace Ui {
class win;
}

class win : public QDialog
{
    Q_OBJECT

public:
    explicit win(QWidget *parent = nullptr);
    ~win();

private:
    Ui::win *ui;

// public slots:
//     void enter();
//     void exit();
//     void againpress();
};

#endif // WIN_H
