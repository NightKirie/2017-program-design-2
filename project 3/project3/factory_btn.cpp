#include "factory_btn.h"

Factory_btn::Factory_btn()
{
    this->setAcceptHoverEvents(true);
    this->setPixmap(QPixmap("../project3/images/factory.png"));
    this->setPos(335,475);
}

void Factory_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/factory_mouseon.png"));
    this->setPos(335,475);
    this->setCursor(Qt::PointingHandCursor);
}

void Factory_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/factory.png"));
    this->setPos(335,475);
}
