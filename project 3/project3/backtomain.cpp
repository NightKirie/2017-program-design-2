#include "backtomain.h"

Backtomain::Backtomain()
{
    setAcceptHoverEvents(true);
    setPos(85,329);
    setPixmap(QPixmap("../project3/images/backtomain.png"));
}

void Backtomain::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/backtomain_mouseon.png"));
}

void Backtomain::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/backtomain.png"));
}
