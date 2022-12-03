#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamearea.h"

#include <QPainter>

GameWindow::GameWindow(QString player_name, int lvl, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
    , player_name_{player_name}
    , curent_lvl_{lvl}
{
    ui->setupUi(this);
    ui->level_lbl->setText(QString::number(lvl));

//    QPixmap a("/Users/cresswec/Downloads/game/data/pngwing.com.png", "PNG");
//    QPainter painter(&a);
//    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
//    painter.fillRect(a.rect(), Qt::black);
//    painter.end();

    Gamearea *l1 = new Gamearea;
    l1->setWhatsThis("CROC");
    QPixmap a("/Users/cresswec/Downloads/game/data/bear.png", "PNG");
    l1->setPixmap(a);
    Gamearea *l2 = new Gamearea;
    l2->setWhatsThis("MON");
    QPixmap b("/Users/cresswec/Downloads/game/data/bird.png", "PNG");
    l2->setPixmap(b);

    ui->gridLayout_2->addWidget(l1, 0, 0);
    ui->gridLayout_2->addWidget(l2, 0, 1);

}

GameWindow::~GameWindow() {
    delete ui;
}


void GameWindow::on_help_btn_clicked() {

}

void GameWindow::on_save_btn_clicked() {
    emit saveGame(player_name_,curent_lvl_);
}
