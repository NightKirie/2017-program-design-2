#include "suzuya.h"

Suzuya::Suzuya()
{
    this->setPixmap(QPixmap("../project2/images/suzuya_1.png"));
    this->setPos(x, y);
    hpbar = new QProgressBar;
    hpbar->setStyleSheet("QProgressBar{ border: 2px solid grey; border-radius: 5px;text-align: center;} QProgressBar::chunk { width: 10px; height: 10px; background-color: 	#00DB00;}");
    hpbar->setMaximum(60);
    hpbar->setValue(health);
    hpbar->setGeometry(x+30,y+160,100,20);}

void Suzuya::ChangePic(){
    if(count % 2 == 0){
        this->setPixmap(QPixmap("../project2/images/suzuya_2.png"));
        ++count;
    }
    else{
        this->setPixmap(QPixmap("../project2/images/suzuya_1.png"));
        ++count;
    }
}

void Suzuya::Move() {
    if(x+160+attack_range >= 820 || health <= 0){
    }
    else{
        x += move / 50;
        this->setPos(x, y);
        hpbar->setGeometry(x+30,y+160,100,20);
        hpbar->setValue(health);
    }
}
