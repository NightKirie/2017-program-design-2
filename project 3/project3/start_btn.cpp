#include "start_btn.h"

Start_btn::Start_btn()
{
    this->setAcceptHoverEvents(true);
    this->setPixmap(QPixmap("../project3/images/startbutton.png"));
    this->setPos(645,545);
}

void Start_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    this->setPixmap(QPixmap("../project3/images/startbutton_mouseon.png"));
    this->setPos(634,534);
    this->setCursor(Qt::PointingHandCursor);
}

void Start_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    this->setPixmap(QPixmap("../project3/images/startbutton.png"));
    this->setPos(645,545);
}


