#include "repair_btn.h"

Repair_btn::Repair_btn()
{
    this->setAcceptHoverEvents(true);
    this->setPixmap(QPixmap("../project3/images/repair.png"));
    this->setPos(117,475);
}

void Repair_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/repair_mouseon.png"));
    this->setPos(117,477);
    this->setCursor(Qt::PointingHandCursor);
}

void Repair_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/repair.png"));
    this->setPos(117,475);
}
