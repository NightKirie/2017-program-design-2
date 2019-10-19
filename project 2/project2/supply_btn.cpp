#include "supply_btn.h"

Supply_btn::Supply_btn()
{
    this->setAcceptHoverEvents(true);
}

void Supply_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap supply_btn_mouseon;
    supply_btn_mouseon.load("../project2/images/supply_mouseon.png");
    this->setPixmap(supply_btn_mouseon);
    this->setPos(50,266);
    this->setCursor(Qt::PointingHandCursor);
}

void Supply_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap supply_btn;
    supply_btn.load("../project2/images/supply.png");
    this->setPixmap(supply_btn);
    this->setPos(50,265);
}
