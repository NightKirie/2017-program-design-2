#include "smallrepair_btn.h"

Smallrepair_btn::Smallrepair_btn()
{
    setAcceptHoverEvents(true);
    setPos(4,439);
    setPixmap(QPixmap("../project3/images/smallrepair.png"));
}

void Smallrepair_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    setCursor(Qt::PointingHandCursor);
    setPixmap(QPixmap("../project3/images/smallrepair_mouseon.png"));
}

void Smallrepair_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/smallrepair.png"));
}
