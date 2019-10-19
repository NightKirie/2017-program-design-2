#include "left_btn.h"

Left_btn::Left_btn()
{
    setAcceptHoverEvents(true);
    setPixmap(QPixmap("../project3/images/left_btn.png"));
    setPos(0,260);
    eff = new QGraphicsColorizeEffect;
    eff->setColor(QColor(255,123,0));
    this->setGraphicsEffect(eff);
    eff->setEnabled(false);
}

void Left_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){
    this->setCursor(Qt::PointingHandCursor);
    eff->setEnabled(true);
}

void Left_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    eff->setEnabled(false);
}
