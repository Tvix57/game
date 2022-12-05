#include "gamewindow.h"
#include "ui_gamewindow.h"
#include "gamearea.h"

#include <QtMath>
#include <QPainter>
#include <random>

GameWindow::GameWindow(QString player_name, int lvl, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GameWindow)
    , player_name_{player_name}
    , current_lvl_{lvl}
{
    ui->setupUi(this);
    LoadNewLVL();
}

void GameWindow::AddToMainList(QString path) {
    Gamearea *label  = new Gamearea;
    label->setWhatsThis(QStringList(path.split("/")).last());
    label->setPixmap(QPixmap(path, "PNG"));
    label->setFixedSize(130,130);
    connect(label, SIGNAL(ItemName(QString)), this, SLOT(RemoveImg(QString)));

    bool check = 0;
    if (ui->gridLayout_2->count() < ui->gridLayout_2->rowCount()*ui->gridLayout_2->columnCount()) {
        for (int i = 0; i < ui->gridLayout_2->rowCount(); ++i) {
            for (int j = 0; j < ui->gridLayout_2->columnCount(); ++j) {
                if (ui->gridLayout_2->itemAtPosition(i, j) == nullptr) {
                    ui->gridLayout_2->addWidget(label, i, j);
                    check = 1;
                    break;
                }
             if (check) {
                 break;
             }
            }
        }
    } else {
        ui->gridLayout_2->addWidget(label, ui->gridLayout_2->rowCount(), ui->gridLayout_2->columnCount());
    }
}

void GameWindow::AddToItemList(QString path) {
    QPixmap pixmap(path, "PNG");
    QColor avg = getAvgColor(pixmap);
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), Qt::black );
    painter.end();

    Gamearea *label = new Gamearea;
    label->setWhatsThis(QStringList(path.split("/")).last());
    label->setFixedSize(130,130);

    label->setPixmap(pixmap);
    label->setAvg(avg);

    ui->item_area_layout->addWidget(label, ui->item_area_layout->count());
}

void GameWindow::LoadNewLVL() {
    ui->level_lbl->setText(QString::number(current_lvl_));
    auto images = db_manager_.GetImageWay(0.1 * current_lvl_ * db_manager_.GetMaxImage());
    for (auto &it: images) {
        AddToMainList(it);
    }
    QList<int> list;
    while (list.size() < images.size() * 0.3) {
        static std::random_device rd;
        static std::default_random_engine generator(rd());
        static std::uniform_int_distribution<int> dist(0, images.size() - 1);
        int random = dist(generator);
        if (list.contains(random)) {
            continue;
        } else {
            list.append(random);
        }
    }

    for (auto &it: list) {
        AddToItemList(images.values().at(it));
    }
    ui->progressBar->setValue(0);
    ui->progressBar->setMaximum(list.size());
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
    Gamearea *item = static_cast<Gamearea *>(ui->item_area_layout->itemAt(curent_item_)->widget());
    QPixmap pixmap(*item->pixmap());
    QPainter painter(&pixmap);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn);
    painter.fillRect(pixmap.rect(), item->getAvg());
    painter.end();

    item->setPixmap(pixmap);
}

void GameWindow::on_save_btn_clicked() {
    emit saveGame(player_name_,current_lvl_);
}

bool GameWindow::RemoveImg(QString item_name) {
    auto * cur_find = static_cast<Gamearea *>(ui->item_area_layout->itemAt(curent_item_)->widget());
    if (cur_find && item_name == cur_find->whatsThis()) {
        for (int i = 0; i < ui->gridLayout_2->rowCount(); ++i) {
            for (int j = 0; j < ui->gridLayout_2->columnCount(); ++j) {
                auto * cur_widget_grid = ui->gridLayout_2->itemAtPosition(i,j);
                if (cur_widget_grid) {
                    Gamearea * cur_widget = static_cast<Gamearea *> (cur_widget_grid->widget());
                    if (cur_widget->whatsThis() == item_name) {
                        ui->progressBar->setValue(ui->progressBar->value()+1);
                        cur_find->hide();
                        cur_widget->hide();
                        ++curent_item_;
                        this->repaint();
                        return true;
                    }
                }

            }
        }
    }
    return false;
}

void GameWindow::on_progressBar_valueChanged(int value) {
    if (value == ui->progressBar->maximum()) {
        ++current_lvl_;
        curent_item_ = 0;
        LoadNewLVL();
    }
}
