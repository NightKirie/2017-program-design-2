#include "attack_btn.h"

Attack_btn::Attack_btn()
{
    this->setAcceptHoverEvents(true);
}

void Attack_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap attack_btn_mouseon;
    attack_btn_mouseon.load("../project2/images/attack_mouseon.png");
    this->setPixmap(attack_btn_mouseon);
    this->setPos(167,290);
    this->setCursor(Qt::PointingHandCursor);
}

void Attack_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap attack_btn;
    attack_btn.load("../project2/images/attack.png");
    this->setPixmap(attack_btn);
    this->setPos(170,290);
}
