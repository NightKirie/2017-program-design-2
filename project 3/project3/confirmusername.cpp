#include "confirmusername.h"

Confirmusername::Confirmusername()
{
    setAcceptHoverEvents(true);
    setPixmap(QPixmap("../project3/images/confirmusername.png"));
    setPos(475,507);
    eff = new QGraphicsColorizeEffect;
    eff->setColor(QColor(255,123,0));
    this->setGraphicsEffect(eff);
    eff->setEnabled(false);
}

void Confirmusername::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    this->setCursor(Qt::PointingHandCursor);
    eff->setEnabled(true);
}

void Confirmusername::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    eff->setEnabled(false);
}
