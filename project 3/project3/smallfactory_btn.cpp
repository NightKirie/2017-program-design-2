#include "smallfactory_btn.h"

Smallfactory_btn::Smallfactory_btn()
{
    setAcceptHoverEvents(true);
    setPos(5,357);
    setPixmap(QPixmap("../project3/images/smallfactory.png"));
}

void Smallfactory_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    setCursor(Qt::PointingHandCursor);
    setPixmap(QPixmap("../project3/images/smallfactory_mouseon.png"));
}

void Smallfactory_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/smallfactory.png"));
}
