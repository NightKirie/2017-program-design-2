#include "boss.h"

Boss::Boss()
{
    this->setPixmap(QPixmap("../project2/images/boss_1.png"));
    this->setPos(x,y);
    hpbar = new QProgressBar;
    hpbar->setStyleSheet("QProgressBar{border: 2px solid grey; border-radius: 5px; text-align: center;} QProgressBar::chunk {background-color: #FF0000;}");
    hpbar->setMaximum(10000);
    hpbar->setGeometry(860,530,300,20);
}

void Boss::sethpbar(){
    hpbar->setValue(health);
    if(health <= 6000){
        this->setPixmap(QPixmap("../project2/images/boss_2.png"));
        this->attack = 45;
    }
    if(health <= 3000){
        this->setPixmap(QPixmap("../project2/images/boss_3.png"));
        this->attack = 60;
    }
}
