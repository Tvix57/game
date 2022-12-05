#include "gamearea.h"
#include <QDebug>
Gamearea::Gamearea(QWidget *parent)
    : QLabel{parent} {}

void Gamearea::mouseReleaseEvent(QMouseEvent *event) {
    emit ItemName(this->whatsThis());
}

