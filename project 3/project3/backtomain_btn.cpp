#include "backtomain_btn.h"

Backtomain_btn::Backtomain_btn()
{
    setAcceptHoverEvents(true);
    setPos(85,329);
    setPixmap(QPixmap("../project3/images/backtomain.png"));
}

void Backtomain_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    setCursor(Qt::PointingHandCursor);
    setPixmap(QPixmap("../project3/images/backtomain_mouseon.png"));
}

void Backtomain_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    setPixmap(QPixmap("../project3/images/backtomain.png"));
}
