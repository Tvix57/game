#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QString player_name, int lvl, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
    , player_name_{player_name}
    , curent_lvl_{lvl}
{
    ui->setupUi(this);
    ui->level_lbl->setText(QString::number(lvl));
}

GameWindow::~GameWindow() {
    delete ui;
}


void GameWindow::on_help_btn_clicked() {

}

void GameWindow::on_save_btn_clicked() {
    emit saveGame(player_name_,curent_lvl_);
}
