#include "namewindow.h"
#include "ui_namewindow.h"

NameWindow::NameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NameWindow)
{
    ui->setupUi(this);
}

NameWindow::~NameWindow() {
    delete ui;
}

void NameWindow::on_save_btn_clicked() {
    emit newProfile(ui->name_ln->text());
    this->close();
}
