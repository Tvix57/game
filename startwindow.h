#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>

#include "profilemanager.h"

namespace Ui {
class StartWindow;
}

class StartWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = nullptr);
    ~StartWindow();

private slots:
    void on_play_btn_clicked();
    void on_load_btn_clicked();
    void on_exit_btn_clicked();

private:
    Ui::StartWindow *ui;
    ProfileManager * profile_;
};

#endif // STARTWINDOW_H
