#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QtMath>

#include "dbmanager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindow; }
QT_END_NAMESPACE

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QString player_name, int lvl = 1, QWidget *parent = nullptr);
    ~GameWindow();

private slots:
    void on_help_btn_clicked();
    void on_save_btn_clicked();
    bool RemoveImg(QString);
    void on_progressBar_valueChanged(int value);

signals:
    void saveGame(QString, int);

private:
    void AddToMainList(QString path);
    void AddToItemList(QString path);
    void LoadNewLVL();
    void ShowCurrent();
    QColor getAvgColor(QPixmap pixmap);
    Ui::GameWindow *ui;
    QString player_name_;
    int current_lvl_;
    DBManager db_manager_;
    int curent_item_ = 0;
    int layout_pos_ = 0;
};
#endif // GAMEWINDOW_H
