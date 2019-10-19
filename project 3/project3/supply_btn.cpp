#include "supply_btn.h"

Supply_btn::Supply_btn()
{
    this->setAcceptHoverEvents(true);
    this->setPixmap(QPixmap("../project3/images/supply.png"));
    this->setPos(50,265);
}

void Supply_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/supply_mouseon.png"));
    this->setPos(50,266);
    this->setCursor(Qt::PointingHandCursor);
}

void Supply_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/supply.png"));
    this->setPos(50,265);
}
