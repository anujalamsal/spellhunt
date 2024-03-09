#ifndef DESERT_H
#define DESERT_H
#include <QLabel>
#include <QLineEdit>

#include <QDialog>

namespace Ui {
class desert;
}

class desert : public QDialog
{
    Q_OBJECT

public:
    explicit desert(QWidget *parent = nullptr);
    ~desert();

private:
    Ui::desert *ui;

public:
    QChar letter;
    QLineEdit *line;
    QLabel *label;
    QLabel *l1, *l2,*l3,*l4, *l5;
    QLabel *r1, *r2, *r3, *r4, *r5;
    QLabel *hint;
    QLabel *e1;
    QLabel *e2;
    QLabel *e3;
    QLabel *e4;
    QLabel *e5;
    QLabel *e6;
    QLabel *e7,*e8,*e9,*e10;
    QLabel *wrong;
    static int h;

    QPixmap emptyheart_s;
    //QLineEdit *btnline;


public:
    QStringList words = {"CACTUS", "MIRAGES", "DROUGHT"};
    int key[10];
    //QString hints[10]={""};

public:    int play;


    QList <int> hint_number;
    //string correct;
    int chance;
    QString  hints[10]={"Succulent desert dweller","Optical Illusion in a distance","Prolonged absence of essential precipitation"};

public:
    void display2();

    void letter_n();
    void count_h();


public slots:
    void convert();
    void check();

};

#endif // DESERT_H
