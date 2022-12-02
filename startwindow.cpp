#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow),
    profile_(new ProfileManager(this)){
    ui->setupUi(this);
}

StartWindow::~StartWindow() {
    delete ui;
}

void StartWindow::on_play_btn_clicked() {
    profile_->loadNewProfile();
    this->hide();
}

void StartWindow::on_load_btn_clicked() {
    profile_->loadProfile();
    this->hide();
}

void StartWindow::on_exit_btn_clicked() {
    this->close();
}
