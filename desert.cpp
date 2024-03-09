#include "desert.h"
#include "ui_desert.h"
#include <QScreen>
#include <QApplication>
#include <QLabel>
#include <QGraphicsDropShadowEffect>
#include <QLineEdit>
#include <QPushButton>
#include <QRandomGenerator>
#include "windesert.h"
#include "losedesert.h"

desert::desert(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::desert)
{
    ui->setupUi(this);
    setWindowTitle("Desert page");

    QPixmap pixmap(":/img/desertgame.png");


    QScreen *screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();

    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();


    QPixmap scaledPixmap = pixmap.scaled(screenWidth, screenHeight, Qt::KeepAspectRatio);

    QLabel *label=new QLabel(this);
    label->setPixmap(QPixmap(scaledPixmap));

    QSize scale(125,125);
    QPixmap leftheart(":/img/right half hear.png");
    QPixmap leftheart_s=leftheart.scaled(scale, Qt::KeepAspectRatio);

    l1=new QLabel(this);
    l1->setGeometry(170,40,87,75);
    l1->setStyleSheet("QLabel{ background-color: transparent;}");

    QPixmap fullheart(":/img/fullheart.png");
    QPixmap fullheart_s=fullheart.scaled(scale,Qt::KeepAspectRatio);
    l1->setPixmap(QPixmap(fullheart_s));

    QPixmap emptyheart(":/img/empty heart.png");
    QPixmap emptyheart_s=emptyheart.scaled(scale,Qt::KeepAspectRatio);

    l2=new QLabel(this);
    l2->setGeometry(257,40,87,75);
    l2->setPixmap(QPixmap(fullheart_s));

    l3=new QLabel(this);
    l3->setGeometry(344,40,87,75);
    l3->setPixmap(QPixmap(fullheart_s));

    l4=new QLabel(this);
    l4->setGeometry(431,40,87,75);
    l4->setPixmap(QPixmap(fullheart_s));

    l5=new QLabel(this);
    l5->setGeometry(518,40,87,75);
    l5->setPixmap(QPixmap(fullheart_s));

    r1=new QLabel(this);
    r1->setGeometry(685,40,87,75);
    r1->setPixmap(QPixmap(fullheart_s));

    r2=new QLabel(this);
    r2->setGeometry(772,40,87,75);
    r2->setPixmap(QPixmap(fullheart_s));

    r3=new QLabel(this);
    r3->setGeometry(859,40,87,75);
    r3->setPixmap(QPixmap(fullheart_s));

    r4=new QLabel(this);
    r4->setGeometry(946,40,87,75);
    r4->setPixmap(QPixmap(fullheart_s));

    r5=new QLabel(this);
    r5->setGeometry(1033,40,87,75);
    r5->setPixmap(QPixmap(fullheart_s));

    QLabel *guess =new QLabel(this);
    guess->setText("Enter your guess:");
    guess->setFont(QFont("Lilita One",25));
    guess->setGeometry(465,400,400,40);
    guess->setStyleSheet("QLabel{color:#FFFFFF}");

    QGraphicsDropShadowEffect *shadowEffect = new QGraphicsDropShadowEffect;
    shadowEffect->setBlurRadius(20);
    shadowEffect->setOffset(0);
    shadowEffect->setColor(QColor("#000000"));
    guess->setGraphicsEffect(shadowEffect);

    line=new QLineEdit(this);
    line->setMaxLength(1);
    line->setGeometry(400,460,350,50);
    line->setStyleSheet("QLineEdit {"
                        "    background-color: #E8E9B9; "
                        "    border: 5px solid #483B30; "
                        "}");
    line->setPlaceholderText("Type one letter");
    line->setFont(QFont("Lilita One",20));

    QPushButton *btnline=new QPushButton(this);

    btnline->setText("Ok");
    btnline->setStyleSheet("QPushButton {"
                           "    background-color: #83EC7A; "
                           "    font-family: Lilita One; "
                           "    font-size: 20px; "
                           "    font-weight: normal; "
                           "border: 5px solid #483B30;"
                           "} "
                           "QPushButton:hover {"
                           "    background-color: #49B821; "
                           "} "
                           "QPushButton:pressed {"
                           "    background-color: #D3C96E; "
                           "}");
    btnline->setGeometry(750,460,87.5,50);

    hint=new QLabel(this);
    hint->setText("Hint: ");
    hint->setGeometry(400,510,350,30);
    hint->setFont(QFont("Lilita One",15));
    hint->setStyleSheet("QLabel{color:white}");

    wrong=new QLabel(this);
    wrong->setGeometry(370,620,375,50);
    wrong->setText("Wrong Guesses: ");
    wrong->setFont(QFont("Lilita One",20));
    wrong->setStyleSheet("QLabel{color:white}");

    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect;
    shadow->setBlurRadius(10);
    shadow->setOffset(0);
    shadow->setColor(QColor("#483B30"));
    wrong->setGraphicsEffect(shadow);

    e1=new QLabel(this);
    e1->setGeometry(370,260,70,70);setStyleSheet("QLabel{background-color:transparent}");
    e1->setFont(QFont("Lilita One",20));
    e1->setAlignment(Qt::AlignCenter);

    e2=new QLabel(this);
    e2->setGeometry(450,260,70,70);
    e2->setStyleSheet("QLabel{background-color:transparent}");
    e2->setFont(QFont("Lilita One",20));
    e2->setAlignment(Qt::AlignCenter);

    e3=new QLabel(this);
    e3->setGeometry(530,260,70,70);
    e3->setStyleSheet("QLabel{background-color:transparent}");
    e3->setFont(QFont("Lilita One",20));
    e3->setAlignment(Qt::AlignCenter);

    e4=new QLabel(this);
    e4->setGeometry(610,260,70,70);
    e4->setStyleSheet("QLabel{background-color:transparent}");
    e4->setFont(QFont("Lilita One",20));
    e4->setAlignment(Qt::AlignCenter);

    e5=new QLabel(this);
    e5->setGeometry(690,260,70,70);
    e5->setStyleSheet("QLabel{background-color:transparent}");
    e5->setFont(QFont("Lilita One",20));
    e5->setAlignment(Qt::AlignCenter);

    e6=new QLabel(this);
    e6->setGeometry(770,260,70,70);
    e6->setStyleSheet("QLabel{background-color:transparent}");
    e6->setFont(QFont("Lilita One",20));
    e6->setAlignment(Qt::AlignCenter);

    e7=new QLabel(this);
    e7->setGeometry(850,260,70,70);
    e7->setStyleSheet("QLabel{background-color:transparent}");
    e7->setFont(QFont("Lilita One",20));
    e7->setAlignment(Qt::AlignCenter);

    e8=new QLabel(this);
    e8->setGeometry(930,260,70,70);
    e8->setStyleSheet("QLabel{background-color:transparent}");
    e8->setFont(QFont("Lilita One",20));
    e8->setAlignment(Qt::AlignCenter);

    e9=new QLabel(this);
    e9->setGeometry(1010,260,70,70);
    e9->setStyleSheet("QLabel{background-color:transparent}");
    e9->setFont(QFont("Lilita One",20));
    e9->setAlignment(Qt::AlignCenter);

    e10=new QLabel(this);
    e10->setGeometry(1090,260,70,70);
    e10->setStyleSheet("QLabel{background-color:transparent}");
    e10->setFont(QFont("Lilita One",20));
    e10->setAlignment(Qt::AlignCenter);


    letter_n();
    display2();
    count_h();

    connect(btnline,SIGNAL(clicked(bool)),this,SLOT(convert()));
    connect(btnline,SIGNAL(clicked(bool)),this,SLOT(check()));



}

desert::~desert()
{
    delete ui;
}

void desert::display2()
{
    int down=0, up=3;
    QRandomGenerator random;
    play=QRandomGenerator::global()->bounded(down,up);
    qDebug()<<play;
    hint->setText("Hint: "+hints[play]);
    QStringList passes=words;
    int count=0;

    for(QString crazy:passes)
    {
        if(count==play)
        {

            for(int i=0;i<key[count];i++)
            {
                if(i%3==0)
                {
                    hint_number.push_back(i);


                    switch(i)
                    {
                    case 0:
                        e1->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e1->setText(crazy[i]);
                        e1->setAlignment(Qt::AlignCenter);
                        e1->setFont(QFont("Lilita One",20));
                        break;



                    case 1:
                        e2->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e2->setText(crazy[i]);
                        e2->setFont(QFont("Lilita One",20));
                        e2->setAlignment(Qt::AlignCenter);
                        break;

                    case 2:
                        e3->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e3->setText(crazy[i]);
                        e3->setFont(QFont("Lilita One",20));
                        e3->setAlignment(Qt::AlignCenter);
                        break;

                    case 3:
                        e4->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e4->setText(crazy[i]);
                        e4->setFont(QFont("Lilita One",20));
                        e4->setAlignment(Qt::AlignCenter);
                        break;

                    case 4:
                        e5->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e5->setText(crazy[i]);
                        e5->setFont(QFont("Lilita One",20));
                        e5->setAlignment(Qt::AlignCenter);
                        break;

                    case 5:
                        e6->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e6->setText(crazy[i]);
                        e6->setFont(QFont("Lilita One",20));
                        e6->setAlignment(Qt::AlignCenter);
                        break;

                    case 6:
                        e7->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e7->setText(crazy[i]);
                        e7->setFont(QFont("Lilita One",20));
                        e7->setAlignment(Qt::AlignCenter);
                        break;

                    case 7:
                        e8->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e8->setText(crazy[i]);
                        e8->setAlignment(Qt::AlignCenter);
                        break;

                    case 8:
                        e9->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");
                        e9->setText(crazy[i]);
                        e9->setFont(QFont("Lilita One",20));
                        e9->setAlignment(Qt::AlignCenter);
                        break;

                    case 9:
                        e10->setStyleSheet("QLabel {"
                                           "    background-color: #E8E9B9; "
                                           "    border: 5px solid #483B30; "
                                           "}");
                        e10->setText(crazy[i]);
                        e10->setFont(QFont("Lilita One",20));
                        e10->setAlignment(Qt::AlignCenter);
                        break;


                    }
                }

                else
                {
                    switch(i)
                    {case 0:
                        e1->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 1:
                        e2->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 2:
                        e3->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 3:
                        e4->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 4:
                        e5->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 5:
                        e6->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 6:
                        e7->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 7:
                        e8->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 8:
                        e9->setStyleSheet("QLabel {"
                                          "    background-color: #E8E9B9; "
                                          "    border: 5px solid #483B30; "
                                          "}");

                        break;

                    case 9:
                        e10->setStyleSheet("QLabel {"
                                           "    background-color: #E8E9B9; "
                                           "    border: 5px solid #483B30; "
                                           "}");

                        break;

                    }
                }

            }
            count++;
        }

        else
        {count++;}



    }
}

void desert::letter_n()
{
    // if(words.isEmpty())
    // {

    //     hint->setText("Error Encountered.");
    // }

    /*else*/{
        int count=0;

        for(QString k:words)
        {
            key[count]=k.length();
            count++;
        }
    }
}

void desert::count_h()
{
    QList <int> h=hint_number;

    int c=play;
    int m=h.size();
    int n=key[c];
    chance=n-m;
}

void desert::convert()
{

    // if(words.isEmpty())
    // {hint->setText("Error Encountered.");}

    // else
    {
        // if(line->text().isEmpty())
        // {hint->setText("Error: You have not entered any text.");}



        //else
        //qDebug()<<element;
        {
            //static int d=1;
            QString str;
            str =line->text();
            //char *b;
            QChar b=str.at(0);


            int a=b.toLatin1();
            // Conversion from string into ASCII value.

            if(a>=97 && a<=122){
                a=a-32;
                letter=char(a);
            }

            else if(a>=65 &&  a<=90  )
            {
                letter=b;

            }

            else
            {
                hint->setText("Error: You have entered invalid character.");
                line->clear();

            }

        }
    }
}

void desert::check()
{

    {
        hint->setText("Hint: "+ hints[play]);

        static  int f=0;// for heart change
        static int t=0;
        int c=play;// Index of the List of word elements i.e. 1=laptop, 2=computer, ...
        static QList <int> num=hint_number;// Index of the Hint in the hangman.
        QList <int> x;// Further to be understood.

        //static int h=chance;
        QStringList w=words; // List of string to be displayed.

        static int m=0;
        int j=0;// For checking the words.
        //static int count=0;
        int e; // Size of the hints. L--T-- -> 2
        e=num.size();
        static int g=0;

        static int r;

        for(QString sacho:w)// sacho = ['Laptop','Computer','XYZ']
        {
            if(j==c) // j=>Laptop,
            {
                int q=m;
                m=m-q;

                r=sacho.length();


                for(int p=0;p<key[c];p++) // Key -> Letter count in the word for the texts.
                {
                    // p ==> L, A, P, T, O, P
                    // m++;

                    if(num.front()==p)
                    {

                        switch(p)
                        {case 0:
                            e1->setText(sacho[p]);
                            break;

                        case 1:
                            e2->setText(sacho[p]);
                            break;

                        case 2:
                            e3->setText(sacho[p]);
                            break;

                        case 3:
                            e4->setText(sacho[p]);
                            break;

                        case 4:
                            e5->setText(sacho[p]);
                            break;

                        case 5:
                            e6->setText(sacho[p]);
                            break;

                        case 6:
                            e7->setText(sacho[p]);
                            break;

                        case 7:
                            e8->setText(sacho[p]);
                            break;

                        case 8:
                            e9->setText(sacho[p]);
                            break;

                        case 9:
                            e10->setText(sacho[p]);
                            break;

                        }
                        int bro=num.size()-1;
                        num.move(0,bro);
                    }



                    else if(letter==sacho[p]){
                          switch(t)
                        {

                        case 0:
                            r1->setPixmap(QPixmap(emptyheart_s));
                            break;

                        case 1:
                            r2->setPixmap(QPixmap(emptyheart_s));
                            break;

                        case 2:
                            r3->setPixmap(QPixmap(emptyheart_s));
                            break;

                        case 3:
                            r4->setPixmap(QPixmap(emptyheart_s));
                            break;

                        case 4:
                            r5->setPixmap(QPixmap(emptyheart_s));
                            break;

                        }

                        switch(p)
                        {

                        case 0:
                            e1->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e1->setText(sacho[p]);
                            break;

                        case 1:
                            e2->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e2->setText(sacho[p]);
                            break;

                        case 2:
                            e3->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e3->setText(sacho[p]);
                            break;

                        case 3:
                            e4->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e4->setText(sacho[p]);
                            break;

                        case 4:
                            e5->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e5->setText(sacho[p]);
                            break;

                        case 5:
                            e6->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e6->setText(sacho[p]);
                            break;

                        case 6:
                            e7->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e7->setText(sacho[p]);
                            break;

                        case 7:
                            e8->setStyleSheet("QLabel{background-color:white}");
                            e8->setText(sacho[p]);
                            break;

                        case 8:
                            e9->setStyleSheet("QLabel {"
                                              "    background-color: #E8E9B9; "
                                              "    border: 5px solid #483B30; "
                                              "}");
                            e9->setText(sacho[p]);
                            break;

                        case 9:
                            e10->setStyleSheet("QLabel {"
                                               "    background-color: #E8E9B9; "
                                               "    border: 5px solid #483B30; "
                                               "}");
                            e10->setText(sacho[p]);
                            break;

                        }

                        x.push_back(p);

                        t++;

                        if(t==chance)
                        {
                            int clear;

                            clear=f;
                            f=f-clear;
                            clear=t;
                            t=t-clear;
                            clear=m;
                            m=m-clear;
                            clear=r;
                            r=r-clear;
                            num=hint_number;
                            x.clear();
                            windesert change;
                            hide();
                            change.setModal(true);
                            change.showFullScreen();
                            change.exec();
                        }
                    }

                    else
                    {

                        m++;
                        if(m==(r-e))
                        {

                            wrong->setText(wrong->text()+" "+letter);
                            switch(f)
                            {
                            case 0:
                                l5->setPixmap(QPixmap(emptyheart_s));
                                break;

                            case 1:
                                l4->setPixmap(QPixmap(emptyheart_s));
                                break;

                            case 2:
                                l3->setPixmap(QPixmap(emptyheart_s));
                                break;

                            case 3:
                                l2->setPixmap(QPixmap(emptyheart_s));
                                break;

                            case 4:
                                l1->setPixmap(QPixmap(emptyheart_s));
                                int clear;

                                clear=f;
                                f=f-clear;
                                clear=t;
                                t=t-clear;
                                clear=m;
                                m=m-clear;
                                clear=r;
                                r=r-clear;
                                num=hint_number;
                                x.clear();
                                losedesert change;
                                hide();
                                change.setModal(true);
                                change.showFullScreen();
                                change.exec();
                                break;

                            }

                            f++;

                        }

                    }

                }
                j++;}

            else
            {j++;}
        }

        num+=(x);
        //bubble sort
        {
            for(int i=0;i<num.size()-1;i++)
            {
                for(int j=0;j<(num.size()-i-1);j++)
                {
                    if(num[j]>num[j+1])
                    {
                        int temp;
                        temp=num[j];
                        num[j]=num[j+1];
                        num[j+1]=temp;
                    }

                }

            }



        }

        line->clear();

    }
}
