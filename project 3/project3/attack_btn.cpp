#include "attack_btn.h"

Attack_btn::Attack_btn()
{
    this->setAcceptHoverEvents(true); 
    this->setPixmap(QPixmap("../project3/images/attack.png"));
    this->setPos(170,290);
}

void Attack_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/attack_mouseon.png"));
    this->setPos(167,290);
    this->setCursor(Qt::PointingHandCursor);
}

void Attack_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/attack.png"));
    this->setPos(170,290);
}
