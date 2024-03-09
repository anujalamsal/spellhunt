#ifndef ISLAND_H
#define ISLAND_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class island;
}

class island : public QDialog
{
    Q_OBJECT

public:
    explicit island(QWidget *parent = nullptr);
    ~island();

private:
    Ui::island *ui;

public:
    void display2();

    void letter_n();
    void count_h();


private slots:
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
    //QLineEdit *btnline;


public:
    QStringList words = {"HARBOUR", "CAPTAIN", "MERMAID"};
    int key[10];
    QString hints[10]={"Sheltered water haven for vessels","Leader at ship's helm", "Enchanting Sea Creature"};

public:    int play;


    QList <int> hint_number;
    //string correct;
    int chance;

public:
    int element=words.size();

};

#endif // ISLAND_H
