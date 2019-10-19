#include "right_btn.h"

Right_btn::Right_btn()
{
    setAcceptHoverEvents(true);
    setPixmap(QPixmap("../project3/images/right_btn.png"));
    setPos(1000,260);
    eff = new QGraphicsColorizeEffect;
    eff->setColor(QColor(255,123,0));
    this->setGraphicsEffect(eff);
    eff->setEnabled(false);
}

void Right_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    this->setCursor(Qt::PointingHandCursor);
    eff->setEnabled(true);
}

void Right_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    eff->setEnabled(false);
}
