#include "change_btn.h"

Change_btn::Change_btn()
{
    this->setAcceptHoverEvents(true);
}

void Change_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap change_btn_mouseon;
    change_btn_mouseon.load("../project2/images/change_mouseon.png");
    this->setPixmap(change_btn_mouseon);
    this->setPos(410,267);
    this->setCursor(Qt::PointingHandCursor);
}

void Change_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap change_btn;
    change_btn.load("../project2/images/change.png");
    this->setPixmap(change_btn);
    this->setPos(410,265);
}
