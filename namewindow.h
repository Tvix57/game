#ifndef PAUSEWINDOW_H
#define PAUSEWINDOW_H

#include <QWidget>

namespace Ui {
class NameWindow;
}

class NameWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NameWindow(QWidget *parent = nullptr);
    ~NameWindow();

private slots:
    void on_save_btn_clicked();
signals:
    void newProfile(QString);

private:
    Ui::NameWindow *ui;
};

#endif // PAUSEWINDOW_H
