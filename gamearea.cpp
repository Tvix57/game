#include "gamearea.h"
#include <QDebug>
Gamearea::Gamearea(QWidget *parent)
    : QLabel{parent}
{

}

void Gamearea::mouseReleaseEvent(QMouseEvent *event) {
    QMessageBox a;
    a.setText(this->whatsThis());
    a.exec();
}

