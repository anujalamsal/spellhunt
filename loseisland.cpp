#include "loseisland.h"
#include "ui_loseisland.h"
#include <QScreen>
#include <QLabel>
#include <QApplication>
#include <QPushButton>
#include "sec.h"
#include "island.h"


loseisland::loseisland(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::loseisland)
{
    ui->setupUi(this);
    setWindowTitle("You lose");


    QPixmap pixmap(":/img/islandlose.png");


    QScreen *screen = QGuiApplication::primaryScreen();
    QSize screenSize = screen->size();

    int screenWidth = screenSize.width();
    int screenHeight = screenSize.height();


    QPixmap scaledPixmap = pixmap.scaled(screenWidth, screenHeight, Qt::KeepAspectRatio);

    QLabel *label=new QLabel(this);
    label->setPixmap(QPixmap(scaledPixmap));

    QPushButton *quitt= new QPushButton(this);
    quitt->setText("Exit");
    quitt->setGeometry(450,585,100,50);
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






    QPushButton *neww=new QPushButton(this);

    neww->setText("New");
    neww->setGeometry(580,585,100,50);
    neww->setStyleSheet("QPushButton {"
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
    retry->setGeometry(710,585,100,50);
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

    connect(neww, &QPushButton::clicked, [&]() {
        sec change;
        change.setModal(true);
        change.showFullScreen();
        change.exec();
    });

    connect(retry, &QPushButton::clicked, [&]() {
        island change;
        change.setModal(true);
        change.showFullScreen();
        change.exec();
    });

    connect(quitt, &QPushButton::clicked, [&]() {
        QCoreApplication::quit();
    });
}

loseisland::~loseisland()
{
    delete ui;
}
