#include "win.h"
#include "ui_win.h"
#include <QScreen>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include "desert.h"
#include "sec.h"

win::win(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::win)
{
    ui->setupUi(this);
    setWindowTitle("You win");


    QPixmap pixmap(":/img/cutewin.png");


    QScreen *screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();

    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();


    QPixmap scaledPixmap = pixmap.scaled(screenWidth, screenHeight, Qt::KeepAspectRatio);

    QLabel *label=new QLabel(this);
    label->setPixmap(QPixmap(scaledPixmap));

    QPushButton *quitt= new QPushButton(this);
    quitt->setText("Exit");
    quitt->setGeometry(450,550,100,50);
    quitt->setStyleSheet("QPushButton {"
                         "    background-color: #FF8D8D; "
                         "    color: #FFFFFF; "
                         "    border: 5px solid #923030;"

                         "    font-family: Lilita One; "
                         "    font-size: 20px; "
                         "    font-weight: normal; "

                         "} "
                         "QPushButton:hover {"
                         "    background-color: #F35151; "
                         "} "
                         "QPushButton:pressed {"
                         "    background-color: #BFD36E; "
                         "}");






    QPushButton *next=new QPushButton(this);

    next->setText("Next");
    next->setGeometry(580,550,100,50);
    next->setStyleSheet("QPushButton {"
                        "    background-color: #FFB865; "
                        "    color: #FFFFFF; "
                        "    font-family: Lilita One; "
                        "    border: 5px solid #7D5D38;"
                        "    font-size: 20px; "
                        "    font-weight: normal; "
                        "} "
                        "QPushButton:hover {"
                        "    background-color: #F58A5C ; "
                        "} "
                        "QPushButton:pressed {"
                        "    background-color: #D3C96E; "
                        "}");


    QPushButton *retry =new QPushButton(this);
    retry->setText("Again");
    retry->setGeometry(710,550,100,50);
    retry->setStyleSheet("QPushButton {"
                         "    background-color: #FF8D8D; "
                         "    color: #FFFFFF; "
                         "    border: 5px solid #923030;"
                         "    font-family: Lilita One; "
                         "    font-size: 20px; "
                         "    font-weight: normal; "
                         "} "
                         "QPushButton:hover {"
                         "    background-color: #F35151; "
                         "} "
                         "QPushButton:pressed {"
                         "    background-color: #BFD36E; "
                         "}");

    connect(next, &QPushButton::clicked, [&]() {
        desert change;
        change.setModal(true);
        change.showFullScreen();
        change.exec();
    });

    connect(retry, &QPushButton::clicked, [&]() {
        sec change;
        change.setModal(true);
        change.showFullScreen();
        change.exec();
    });

    connect(quitt, &QPushButton::clicked, [&]() {
        QCoreApplication::quit();
    });




}

win::~win()
{
    delete ui;
}
