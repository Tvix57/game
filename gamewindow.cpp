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
    l1->setFixedSize(130,130);
    Gamearea *l2 = new Gamearea;
    l2->setWhatsThis("MON");
    l2->setFixedSize(130, 130);
    QPixmap b("/Users/cresswec/Downloads/game/data/bird.png", "PNG");
    l2->setPixmap(b);

    ui->gridLayout_2->addWidget(l1, 0, 0);
    ui->gridLayout_2->addWidget(l2, 0, 1);

    AddToItemList("/Users/cresswec/Downloads/game/data/crocodile2.png");
    AddToItemList("/Users/cresswec/Downloads/game/data/bird.png");
}

void GameWindow::AddToMainList(QString path) {
    Gamearea *label  = new Gamearea;
    label->setPixmap(QPixmap(path, "PNG"));
    label->setFixedSize(130,130);
//    ui->gridLayout_2->addWidget(label, );
}

void GameWindow::AddToItemList(QString path) {
    QPixmap pixmap(path, "PNG");
    QColor avg = getAvgColor(pixmap);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), avg);
    painter.end();

    Gamearea *label = new Gamearea;
    label->setFixedSize(130,130);

    label->setPixmap(pixmap);
    label->setAvg(avg);

    ui->item_area_layout->addWidget(label, list_item_count_++);
}

QColor GameWindow::getAvgColor(QPixmap pixmap) {
    int count = 0;
    QImage image = pixmap.toImage();

    float r = 0, g = 0, b = 0;
    for (int i = 0; i < pixmap.width(); ++i) {
        for (int j = 0; j < pixmap.height(); ++j) {
            if (image.valid(i, j)) {
                QColor cur = image.pixel(i, j);
                if (cur != QColor(0,0,0)) {
                    count++;
                    r += qPow(cur.redF(), 2);
                    g += qPow(cur.greenF(), 2);
                    b += qPow(cur.blueF(), 2);
                }
            }
        }
    }

    QColor result;
    result.setRedF(qSqrt(r/count));
    result.setGreenF(qSqrt(g/count));
    result.setBlueF(qSqrt(b/count));

    return result;
}

GameWindow::~GameWindow() {
    delete ui;
}


void GameWindow::on_help_btn_clicked() {
    ui->item_area_layout->itemAt(0);
}

void GameWindow::on_save_btn_clicked() {
    emit saveGame(player_name_,curent_lvl_);
}
