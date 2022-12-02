#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
{
    ui->setupUi(this);
}

GameWindow::~GameWindow()
{
    delete ui;
}


void GameWindow::on_help_btn_clicked() {

}

void GameWindow::on_save_btn_clicked() {

}
