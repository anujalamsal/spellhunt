#ifndef WINISLAND_H
#define WINISLAND_H

#include <QDialog>

namespace Ui {
class winisland;
}

class winisland : public QDialog
{
    Q_OBJECT

public:
    explicit winisland(QWidget *parent = nullptr);
    ~winisland();

private:
    Ui::winisland *ui;
};

#endif // WINISLAND_H
