#ifndef SEC_H
#define SEC_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class sec;
}

class sec : public QDialog
{
    Q_OBJECT

public:
    explicit sec(QWidget *parent = nullptr);
    ~sec();

private:
    Ui::sec *ui;

public:
    void display2();

    void letter_n();
    void count_h();


public slots:
    void convert();
    void check();

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



public:
    QStringList words = {"NATURE", "SUNBEAM", "BAMBOO"};
    int key[10];

public:    int play;
    QLabel *answer;
    // QString ujyalo;

public:
    QString hints[10]={"The living canvas","Radiant streak of light","Light and fast growing plant"};
    void display_hint();


    QList <int> hint_number;
    int chance;


};

#endif // SEC_H
