#include "select_btn.h"

Select_btn::Select_btn()
{
    setAcceptHoverEvents(true);
    setPixmap(QPixmap("../project3/images/select_btn"));
    eff = new QGraphicsColorizeEffect;
    eff->setColor(QColor(100,179,184));
    this->setGraphicsEffect(eff);
    eff->setEnabled(false);

}

void Select_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover) {
    this->setCursor(Qt::PointingHandCursor);
    eff->setEnabled(true);
}

void Select_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){
    eff->setEnabled(false);
}
