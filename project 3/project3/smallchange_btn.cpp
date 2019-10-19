#include "smallchange_btn.h"

Smallchange_btn::Smallchange_btn()
{
    setAcceptHoverEvents(true);
    setPos(5,276);
    setPixmap(QPixmap("../project3/images/smallchange.png"));
}

void Smallchange_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    setCursor(Qt::PointingHandCursor);
    setPixmap(QPixmap("../project3/images/smallchange_mouseon.png"));
}

void Smallchange_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/smallchange.png"));
}
