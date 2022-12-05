#ifndef GAMEAREA_H
#define GAMEAREA_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>
#include <QMessageBox>
#include <QPainter>

class Gamearea : public QLabel
{
    Q_OBJECT
public:
    void setAvg(QColor avgin) {avg = avgin;}
    QColor getAvg() {return avg;}
    explicit Gamearea(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *) override;
private:
    QColor avg;
signals:
    void ItemName(QString);
};

#endif // GAMEAREA_H
