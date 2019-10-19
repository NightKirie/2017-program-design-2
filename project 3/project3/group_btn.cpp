#include "group_btn.h"

Group_btn::Group_btn()
{
    this->setAcceptHoverEvents(true);
    this->setPixmap(QPixmap("../project3/images/group.png"));
    this->setPos(225,128);
}

void Group_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/group_mouseon.png"));
    this->setPos(230,135);
    this->setCursor(Qt::PointingHandCursor);
}

void Group_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/group.png"));
    this->setPos(225,130);
}
