#include "factory_btn.h"

Factory_btn::Factory_btn()
{
    this->setAcceptHoverEvents(true);
}

void Factory_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap factory_btn_mouseon;
    factory_btn_mouseon.load("../project2/images/factory_mouseon.png");
    this->setPixmap(factory_btn_mouseon);
    this->setPos(335,475);
    this->setCursor(Qt::PointingHandCursor);
}

void Factory_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap factory_btn;
    factory_btn.load("../project2/images/factory.png");
    this->setPixmap(factory_btn);
    this->setPos(335,475);
}
