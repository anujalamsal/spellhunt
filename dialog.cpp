#include "dialog.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QPixmap>
#include <QSize>
#include <QScreen>
#include <sec.h>
#include <QDialog>
#include <QFontDatabase>


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //ui->setupUi(this);
    setWindowTitle("Home Page");

    QLabel *label=new QLabel(this);




    QPixmap pixmap(":/img/firstpagereee.png");


    QScreen *screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();

    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();


    QPixmap scaledPixmap = pixmap.scaled(screenWidth, screenHeight, Qt::KeepAspectRatio);

    label->setPixmap(QPixmap(scaledPixmap));

    //int scaleFactor=screenSize/pixmap.size();

    //    double scaleWidth=screenWidth/screenSize.width();
    //    double scaleHeight=screenHeight/screenSize.height();


    QPushButton *btn1=new QPushButton(this);

    btn1->setText("Play Game");
    btn1->setGeometry(450,400,350,75);
    btn1->setStyleSheet("QPushButton {"
                        "    background-color: #E8E9B9; "
                        "    border-radius: 20px; "
                        "    font-family: Lilita One; "
                        "    font-size: 28px; "
                        "    font-weight: normal; "
                        "} "
                        "QPushButton:hover {"
                        "    background-color: #BFD36E ; "
                        "} "
                        "QPushButton:pressed {"
                        "    background-color: #D3C96E; "
                        "}");


    QPushButton *btn2 =new QPushButton(this);
    btn2->setText("Exit");
    btn2->setGeometry(450,500,350,75);
    btn2->setStyleSheet("QPushButton {"
                        "    background-color: #E8E9B9; "
                        "    border-radius: 20px; "
                        "    font-family: Lilita One; "
                        "    font-size: 28px; "
                        "    font-weight: normal; "

                        "} "
                        "QPushButton:hover {"
                        "    background-color: #D3C96E; "
                        "} "
                        "QPushButton:pressed {"
                        "    background-color: #BFD36E; "
                        "}");





    connect(btn1,SIGNAL(clicked(bool)),this,SLOT(enter()));
    connect(btn2,SIGNAL(clicked(bool)),this,SLOT(close()));

}

Dialog::~Dialog() {
}

void Dialog::enter()
{
    sec change;
    change.setModal(true);
    change.showFullScreen();
    change.exec();

}

void Dialog::exit()
{
    QCoreApplication::quit();
}
