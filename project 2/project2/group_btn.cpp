#include "group_btn.h"

Group_btn::Group_btn()
{
    this->setAcceptHoverEvents(true);
}

void Group_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap group_btn_mouseon;
    group_btn_mouseon.load("../project2/images/group_mouseon.png");
    this->setPixmap(group_btn_mouseon);
    this->setPos(230,135);
    this->setCursor(Qt::PointingHandCursor);
}

void Group_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap group_btn;
    group_btn.load("../project2/images/group.png");
    this->setPixmap(group_btn);
    this->setPos(225,130);
}
