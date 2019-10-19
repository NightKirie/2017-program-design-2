#include "smallsupply_btn.h"

Smallsupply_btn::Smallsupply_btn()
{
    setAcceptHoverEvents(true);
    setPos(3,517);
    setPixmap(QPixmap("../project3/images/smallsupply.png"));
}

void Smallsupply_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    setCursor(Qt::PointingHandCursor);
    setPixmap(QPixmap("../project3/images/smallsupply_mouseon.png"));
}

void Smallsupply_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/smallsupply.png"));
}
