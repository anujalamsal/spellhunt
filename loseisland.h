#ifndef LOSEISLAND_H
#define LOSEISLAND_H

#include <QDialog>

namespace Ui {
class loseisland;
}

class loseisland : public QDialog
{
    Q_OBJECT

public:
    explicit loseisland(QWidget *parent = nullptr);
    ~loseisland();

private:
    Ui::loseisland *ui;
};

#endif // LOSEISLAND_H
