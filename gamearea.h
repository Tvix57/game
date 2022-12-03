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
    explicit Gamearea(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent *) override;
};

#endif // GAMEAREA_H
