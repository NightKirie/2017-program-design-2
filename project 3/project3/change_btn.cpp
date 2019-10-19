#include "change_btn.h"

Change_btn::Change_btn()
{
    this->setAcceptHoverEvents(true);
    this->setPixmap(QPixmap("../project3/images/change.png"));
    this->setPos(410,265);
}

void Change_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/change_mouseon.png"));
    this->setPos(410,267);
    this->setCursor(Qt::PointingHandCursor);
}

void Change_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/change.png"));
    this->setPos(410,265);
}
