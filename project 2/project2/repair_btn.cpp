#include "repair_btn.h"

Repair_btn::Repair_btn()
{
    this->setAcceptHoverEvents(true);
}

void Repair_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap repair_btn_mouseon;
    repair_btn_mouseon.load("../project2/images/repair_mouseon.png");
    this->setPixmap(repair_btn_mouseon);
    this->setPos(117,477);
    this->setCursor(Qt::PointingHandCursor);

}

void Repair_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap repair_btn;
    repair_btn.load("../project2/images/repair.png");
    this->setPixmap(repair_btn);
    this->setPos(117,475);
}
