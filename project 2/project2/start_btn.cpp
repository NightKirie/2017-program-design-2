#include "start_btn.h"

Start_btn::Start_btn()
{
    this->setAcceptHoverEvents(true);
}

void Start_btn::hoverEnterEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover on
    QPixmap start_btn_mouseon;
    start_btn_mouseon.load("../project2/images/startbutton_mouseon.png");
    this->setPixmap(start_btn_mouseon);
    this->setPos(634,534);
    this->setCursor(Qt::PointingHandCursor);
}

void Start_btn::hoverLeaveEvent(QGraphicsSceneHoverEvent *hover){   //cursor hover off
    QPixmap start_btn;
    start_btn.load("../project2/images/startbutton.png");
    this->setPixmap(start_btn);
    this->setPos(645,545);
}


