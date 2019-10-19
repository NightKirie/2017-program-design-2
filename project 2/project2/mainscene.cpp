#include "mainscene.h"


Mainscene::Mainscene(){
    SetScreen = 0;
}

void Mainscene::InitThings(){
    //set start button
    movie = new QMovie;
    movie->setFileName("../project2/videos/first.gif");
    movie->start();
    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber == movie->frameCount() - 1){
            ChangeGif();
        }
    });

}

void Mainscene::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(SetScreen == 0) {
        //Start Screen
        if(event->scenePos().x() > startbutton_btn->pos().x()+42 && event->scenePos().x() <= startbutton_btn->pos().x()+492) {
            if(event->scenePos().y() > startbutton_btn->pos().y() && event->scenePos().y() <= startbutton_btn->pos().y()+116) {
                SetScreen = 1;
                MovieChange();
            }
        }
     }
     else if(SetScreen == 1){
            //main screen
        if(event->scenePos().y() > groupbutton_btn->pos().y()+30 && event->scenePos().y() <= groupbutton_btn->pos().y()+105) {
            if(event->scenePos().x() > groupbutton_btn->pos().x()+30 && event->scenePos().x() <= groupbutton_btn->pos().x()+105) {
                SetScreen = 0;
                ErrorScreen();
            }
        }   //press group button
        else if(event->scenePos().y() > supplybutton_btn->pos().y()+30 && event->scenePos().y() <= attackbutton_btn->pos().y()+170) {
            if(event->scenePos().x() > supplybutton_btn->pos().x()+30 && event->scenePos().x() <= supplybutton_btn->pos().x()+105) {
                SetScreen = 0;
                ErrorScreen();
            }   //press supply button
            else if(event->scenePos().x() > attackbutton_btn->pos().x()+65 && event->scenePos().x() <= attackbutton_btn->pos().x()+180) {
                SetScreen = 2;
                BattleScreen();
            }   //press attack button
            else if(event->scenePos().x() > changebutton_btn->pos().x()+30 && event->scenePos().x() <= changebutton_btn->pos().x()+105) {
                SetScreen = 0;
                ErrorScreen();
            }   //press change button
        }
        else if(event->scenePos().y() > repairbutton_btn->pos().y()+30 && event->scenePos().y() <= repairbutton_btn->pos().y()+105) {
            if(event->scenePos().x() > repairbutton_btn->pos().x()+30 && event->scenePos().x() <= repairbutton_btn->pos().x()+105) {
                SetScreen = 0;
                ErrorScreen();
            }   //press repair button
            else if(event->scenePos().x() > factorybutton_btn->pos().x()+30 && event->scenePos().x() <= factorybutton_btn->pos().x()+105) {
                SetScreen = 0;
                ErrorScreen();
            }   //press factory button
        }
    }
    else if(SetScreen == 3){
        if(event->scenePos().y() > 670 && event->scenePos().y() <= 720) {
            if(event->scenePos().x() > 0 && event->scenePos().x() <= 50) {
                ID = 1;
                SetMinions();
                //cout << "fubuki" << endl;
            }
            else if(event->scenePos().x() > 50 && event->scenePos().x() <= 100) {
                ID = 2;
                SetMinions();
                //cout << "kuma" << endl;
            }
            else if(event->scenePos().x() > 100 && event->scenePos().x() <= 150) {
                ID = 3;
                SetMinions();
                //cout << "kitakami" << endl;
            }
            else if(event->scenePos().x() > 150 && event->scenePos().x() <= 200) {
                ID = 4;
                SetMinions();
                //cout << "furutaka" << endl;
            }
            else if(event->scenePos().x() > 200 && event->scenePos().x() <= 250) {
                ID = 5;
                SetMinions();
                //cout << "suzuya" << endl;
            }
            else if(event->scenePos().x() > 250 && event->scenePos().x() <= 300) {
                ID = 6;
                SetMinions();
                //cout << "kongo" << endl;
            }
            else if(event->scenePos().x() > 300 && event->scenePos().x() <= 350) {
                ID = 7;
                SetMinions();
                //cout << "fusou" << endl;
            }
            else if(event->scenePos().x() > 350 && event->scenePos().x() <= 400) {
                ID = 8;
                SetMinions();
                //cout << "yamato" << endl;
            }
            else if(event->scenePos().x() > 400 && event->scenePos().x() <= 450) {
                ID = 9;
                SetMinions();
                //cout << "ryuujou" << endl;
            }
            else if(event->scenePos().x() > 450 && event->scenePos().x() <= 500) {
                ID = 10;
                SetMinions();
                //cout << "akagi" << endl;
            }
            else if(event->scenePos().x() > 500 && event->scenePos().x() <= 550) {
                ID = 11;
                SetMinions();
                //cout << "taiho" << endl;
            }
            else if(event->scenePos().x() > 550 && event->scenePos().x() <= 600) {
                ID = 12;
                SetMinions();
                //cout << "i168" << endl;
            }
        }
    }
}

void Mainscene::MovieChange() {
    this->clear();
    movie->setPaused(true);
    movie->setFileName("../project2/videos/second.gif");
    movie->setPaused(false);
    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber > movie->frameCount() - 1){
           ChangeGif();
        }
    });
}

void Mainscene::SetMainScreen(){
    this->setBackgroundBrush(QImage("../project2/images/background_title.jpg"));

    attackbutton_btn = new Attack_btn;
    attackbutton_btn->setPixmap(QPixmap("../project2/images/attack.png"));
    attackbutton_btn->setPos(170,290);
    addItem(attackbutton_btn);

    changebutton_btn = new Change_btn;
    changebutton_btn->setPixmap(QPixmap("../project2/images/change.png"));
    changebutton_btn->setPos(410,265);
    addItem(changebutton_btn);

    factorybutton_btn = new Factory_btn;
    factorybutton_btn->setPixmap(QPixmap("../project2/images/factory.png"));
    factorybutton_btn->setPos(335,475);
    addItem(factorybutton_btn);

    groupbutton_btn = new Group_btn;
    groupbutton_btn->setPixmap(QPixmap("../project2/images/group.png"));
    groupbutton_btn->setPos(225,128);
    addItem(groupbutton_btn);

    repairbutton_btn = new Repair_btn;
    repairbutton_btn->setPixmap(QPixmap("../project2/images/repair.png"));
    repairbutton_btn->setPos(117,475);
    addItem(repairbutton_btn);

    supplybutton_btn = new Supply_btn;
    supplybutton_btn->setPixmap(QPixmap("../project2/images/supply.png"));
    supplybutton_btn->setPos(50,265);
    addItem(supplybutton_btn);
}

void Mainscene::ErrorScreen(){
    this->clear();
    this->setBackgroundBrush(QImage("../project2/images/error.jpg"));
}

void Mainscene::BattleScreen(){
    this->clear();
    this->setBackgroundBrush(QImage("../project2/images/invisible_background.png"));
    movie->setFileName("../project2/videos/battlestart.gif");
    movie->setPaused(false);
    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber > movie->frameCount() - 1){
            ChangeGif();
        }
    });
}

void Mainscene::ChangeGif() {
    if(SetScreen == 0){
            startbutton_btn = new Start_btn;
            startbutton_btn->setPixmap(QPixmap("../project2/images/startbutton.png"));
            startbutton_btn->setPos(645,545);
            addItem(startbutton_btn);
            movie->setPaused(true);
            movie->setFileName("../project2/videos/loop.gif");
            movie->setPaused(false);
    }
    else if(SetScreen == 1){
        movie->setPaused(true);
        SetMainScreen();
    }
    else if(SetScreen == 2){
        movie->setPaused(true);
        this->setBackgroundBrush(QImage("../project2/images/background_day.jpg"));
        SetScreen = 3;
        SetBattlebutton();
    }
}

void Mainscene::SetBattlebutton() {
    change = new QTimer;
    move = new QTimer;
    time = new QTimer;
    change->start(125);
    move->start(20);
    time->start(1000);
    clock = new QLCDNumber;
    clocklb = new QLabel("CountDown");
    clock->setDigitCount(3);
    clock->setGeometry(1100,0,100,50);
    clock->display(totaltime);
    clocklb->setGeometry(1100,50,100,20);
    mana = new QLCDNumber;
    manalb = new QLabel("Mana");
    mana->setDigitCount(2);
    mana->setGeometry(0,0,100,50);
    mana->display(initialmana);
    manalb->setGeometry(0,50,100,20);
    addWidget(clock);
    addWidget(clocklb);
    addWidget(mana);
    addWidget(manalb);
    connect(time, SIGNAL(timeout()), this, SLOT(ShowTime()));
    connect(time, SIGNAL(timeout()), this, SLOT(ShowMana()));


    fubuki_btn = new QPushButton;
    fubuki_btn->setIcon(QIcon("../project2/images/fubuki_btn.png"));
    fubuki_btn->setIconSize(QSize(50,50));
    fubuki_btn->setFixedSize(50,50);
    fubuki_btn->setCursor(Qt::PointingHandCursor);
    fubuki_btn->setGeometry(0,670,50,50);
    addWidget(fubuki_btn);

    kuma_btn = new QPushButton;
    kuma_btn->setIcon(QIcon("../project2/images/kuma_btn.png"));
    kuma_btn->setIconSize(QSize(50,50));
    kuma_btn->setFixedSize(50,50);
    kuma_btn->setCursor(Qt::PointingHandCursor);
    kuma_btn->setGeometry(50,670,50,50);
    addWidget(kuma_btn);

    kitakami_btn = new QPushButton;
    kitakami_btn->setIcon(QIcon("../project2/images/kitakami_btn.png"));
    kitakami_btn->setIconSize(QSize(50,50));
    kitakami_btn->setFixedSize(50,50);
    kitakami_btn->setCursor(Qt::PointingHandCursor);
    kitakami_btn->setGeometry(100,670,50,50);
    addWidget(kitakami_btn);

    furutaka_btn = new QPushButton;
    furutaka_btn->setIcon(QIcon("../project2/images/furutaka_btn.png"));
    furutaka_btn->setIconSize(QSize(50,50));
    furutaka_btn->setFixedSize(50,50);
    furutaka_btn->setCursor(Qt::PointingHandCursor);
    furutaka_btn->setGeometry(150,670,50,50);
    addWidget(furutaka_btn);

    suzuya_btn = new QPushButton;
    suzuya_btn->setIcon(QIcon("../project2/images/suzuya_btn.png"));
    suzuya_btn->setIconSize(QSize(50,50));
    suzuya_btn->setFixedSize(50,50);
    suzuya_btn->setCursor(Qt::PointingHandCursor);
    suzuya_btn->setGeometry(200,670,50,50);
    addWidget(suzuya_btn);

    kongo_btn = new QPushButton;
    kongo_btn->setIcon(QIcon("../project2/images/kongo_btn.png"));
    kongo_btn->setIconSize(QSize(50,50));
    kongo_btn->setFixedSize(50,50);
    kongo_btn->setCursor(Qt::PointingHandCursor);
    kongo_btn->setGeometry(250,670,50,50);
    addWidget(kongo_btn);

    fusou_btn = new QPushButton;
    fusou_btn->setIcon(QIcon("../project2/images/fusou_btn.png"));
    fusou_btn->setIconSize(QSize(50,50));
    fusou_btn->setFixedSize(50,50);
    fusou_btn->setCursor(Qt::PointingHandCursor);
    fusou_btn->setGeometry(300,670,50,50);
    addWidget(fusou_btn);

    yamato_btn = new QPushButton;
    yamato_btn->setIcon(QIcon("../project2/images/yamato_btn.png"));
    yamato_btn->setIconSize(QSize(50,50));
    yamato_btn->setFixedSize(50,50);
    yamato_btn->setCursor(Qt::PointingHandCursor);
    yamato_btn->setGeometry(350,670,50,50);
    addWidget(yamato_btn);

    ryuujou_btn = new QPushButton;
    ryuujou_btn->setIcon(QIcon("../project2/images/ryuujou_btn.png"));
    ryuujou_btn->setIconSize(QSize(50,50));
    ryuujou_btn->setFixedSize(50,50);
    ryuujou_btn->setCursor(Qt::PointingHandCursor);
    ryuujou_btn->setGeometry(400,670,50,50);
    addWidget(ryuujou_btn);

    akagi_btn = new QPushButton;
    akagi_btn->setIcon(QIcon("../project2/images/akagi_btn.png"));
    akagi_btn->setIconSize(QSize(50,50));
    akagi_btn->setFixedSize(50,50);
    akagi_btn->setCursor(Qt::PointingHandCursor);
    akagi_btn->setGeometry(450,670,50,50);
    addWidget(akagi_btn);

    taiho_btn = new QPushButton;
    taiho_btn->setIcon(QIcon("../project2/images/taiho_btn.png"));
    taiho_btn->setIconSize(QSize(50,50));
    taiho_btn->setFixedSize(50,50);
    taiho_btn->setCursor(Qt::PointingHandCursor);
    taiho_btn->setGeometry(500,670,50,50);
    addWidget(taiho_btn);

    i168_btn = new QPushButton;
    i168_btn->setIcon(QIcon("../project2/images/i168_btn.png"));
    i168_btn->setIconSize(QSize(50,50));
    i168_btn->setFixedSize(50,50);
    i168_btn->setCursor(Qt::PointingHandCursor);
    i168_btn->setGeometry(550,670,50,50);
    addWidget(i168_btn);

    boss = new Boss;
    connect(move, SIGNAL(timeout()), boss, SLOT(sethpbar()));
    connect(time, SIGNAL(timeout()), this, SLOT(BossAttack()));
    addItem(boss);
    addWidget(boss->hpbar);


}

void Mainscene::SetMinions(){
    switch(ID) {
        case 1:
            if(initialmana >= 1){
                initialmana -= 1;
                minifubuki = new Fubuki;
                connect(change, SIGNAL(timeout()), minifubuki, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minifubuki, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(FubukiAttack()));
                addItem(minifubuki);
                addWidget(minifubuki->hpbar);
                fubukilist.push_back(minifubuki);
            }
            break;
        case 2:
            if(initialmana >= 2){
                initialmana -= 2;
                minikuma = new Kuma;
                connect(change, SIGNAL(timeout()), minikuma, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minikuma, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(KumaAttack()));
                addItem(minikuma);
                addWidget(minikuma->hpbar);
                kumalist.push_back(minikuma);
            }
            break;
        case 3:
            if(initialmana >= 3){
                initialmana -= 3;
                minikitakami = new Kitakami;
                connect(change, SIGNAL(timeout()), minikitakami, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minikitakami, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(KitakamiAttack()));
                addItem(minikitakami);
                addWidget(minikitakami->hpbar);
                kitakamilist.push_back(minikitakami);
            }
            break;
        case 4:
            if(initialmana >= 4){
                initialmana -= 4;
                minifurutaka = new Furutaka;
                connect(change, SIGNAL(timeout()), minifurutaka, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minifurutaka, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(FurutakaAttack()));
                addItem(minifurutaka);
                addWidget(minifurutaka->hpbar);
                furutakalist.push_back(minifurutaka);
            }
            break;
        case 5:
            if(initialmana >= 4){
                initialmana -= 4;
                minisuzuya = new Suzuya;
                connect(change, SIGNAL(timeout()), minisuzuya, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minisuzuya, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(SuzuyaAttack()));
                addItem(minisuzuya);
                addWidget(minisuzuya->hpbar);
                suzuyalist.push_back(minisuzuya);
            }
            break;
        case 6:
            if(initialmana >= 6){
                initialmana -= 6;
                minikongo = new Kongo;
                connect(change, SIGNAL(timeout()), minikongo, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minikongo, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(KongoAttack()));
                addItem(minikongo);
                addWidget(minikongo->hpbar);
                kongolist.push_back(minikongo);
            }
            break;
        case 7:
            if(initialmana >= 6){
                initialmana -= 6;
                minifusou = new Fusou;
                connect(change, SIGNAL(timeout()), minifusou, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minifusou, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(FusouAttack()));
                addItem(minifusou);
                addWidget(minifusou->hpbar);
                fusoulist.push_back(minifusou);
            }
            break;
        case 8:
            if(initialmana >= 8){
                initialmana -= 8;
                miniyamato = new Yamato;
                connect(change, SIGNAL(timeout()), miniyamato, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), miniyamato, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(YamatoAttack()));
                addItem(miniyamato);
                addWidget(miniyamato->hpbar);
                yamatolist.push_back(miniyamato);
            }
            break;
        case 9:
            if(initialmana >= 4){
                initialmana -= 4;
                miniryuujou = new Ryuujou;
                connect(change, SIGNAL(timeout()), miniryuujou, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), miniryuujou, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(RyuujouAttack()));
                addItem(miniryuujou);
                addWidget(miniryuujou->hpbar);
                ryuujoulist.push_back(miniryuujou);
            }
            break;
        case 10:
            if(initialmana >= 6){
                initialmana -= 6;
                miniakagi = new Akagi;
                connect(change, SIGNAL(timeout()), miniakagi, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), miniakagi, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(AkagiAttack()));
                addItem(miniakagi);
                addWidget(miniakagi->hpbar);
                akagilist.push_back(miniakagi);
            }
            break;
        case 11:
            if(initialmana >= 6){
                initialmana -= 6;
                minitaiho = new Taiho;
                connect(change, SIGNAL(timeout()), minitaiho, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minitaiho, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(TaihoAttack()));
                addItem(minitaiho);
                addWidget(minitaiho->hpbar);
                taiholist.push_back(minitaiho);
            }
            break;
        case 12:
            if(initialmana >= 1){
                initialmana -= 1;
                minii168 = new I168;
                connect(change, SIGNAL(timeout()), minii168, SLOT(ChangePic()));
                connect(move, SIGNAL(timeout()), minii168, SLOT(Move()));
                connect(time, SIGNAL(timeout()), this, SLOT(I168Attack()));
                addItem(minii168);
                addWidget(minii168->hpbar);
                i168list.push_back(minii168);
            }
            break;
    }
}

void Mainscene::BossAttack(){
    int attacktime = 1;
    if(fubukilist.size() != 0){
        for(int i = 0; i < fubukilist.size();i++) {
            if(fubukilist.at(i)->x+160 >= 220 && attacktime > 0){
                fubukilist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(fubukilist.at(i)->health <= 0){
                removeItem(fubukilist.at(i));
                fubukilist.at(i)->hpbar->hide();
                fubukilist.removeAt(i);
            }
        }
    }
    if(kumalist.size() != 0){
        for(int i = 0; i < kumalist.size();i++) {
            if(kumalist.at(i)->x+160 >= 220 && attacktime > 0){
                kumalist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(kumalist.at(i)->health <= 0){
                removeItem( kumalist.at(i));
                kumalist.at(i)->hpbar->hide();
                kumalist.removeAt(i);
            }
        }
    }
    if(kitakamilist.size() != 0){
        for(int i = 0; i < kitakamilist.size();i++) {
            if(kitakamilist.at(i)->x+160 >= 220 && attacktime > 0){
                kitakamilist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(kitakamilist.at(i)->health <= 0){
                removeItem( kitakamilist.at(i));
                kitakamilist.at(i)->hpbar->hide();
                kitakamilist.removeAt(i);
            }
        }
    }
    if(furutakalist.size() != 0){
        for(int i = 0; i < furutakalist.size();i++) {
            if(furutakalist.at(i)->x+160 >= 220 && attacktime > 0){
                furutakalist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(furutakalist.at(i)->health <= 0){
                removeItem( furutakalist.at(i));
                furutakalist.at(i)->hpbar->hide();
                furutakalist.removeAt(i);
            }
        }
    }
    if(suzuyalist.size() != 0){
        for(int i = 0; i < suzuyalist.size();i++) {
            if(suzuyalist.at(i)->x+160 >= 220 && attacktime > 0){
                suzuyalist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(suzuyalist.at(i)->health <= 0){
                removeItem( suzuyalist.at(i));
                suzuyalist.at(i)->hpbar->hide();
                suzuyalist.removeAt(i);
            }
        }
    }
    if(kongolist.size() != 0){
        for(int i = 0; i < kongolist.size();i++) {
            if(kongolist.at(i)->x+160 >= 220 && attacktime > 0){
                kongolist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(kongolist.at(i)->health <= 0){
                removeItem( kongolist.at(i));
                kongolist.at(i)->hpbar->hide();
                kongolist.removeAt(i);
            }
        }
    }
    if(fusoulist.size() != 0){
        for(int i = 0; i < fusoulist.size();i++) {
            if(fusoulist.at(i)->x+160 >= 220 && attacktime > 0){
                fusoulist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(fusoulist.at(i)->health <= 0){
                removeItem( fusoulist.at(i));
                fusoulist.at(i)->hpbar->hide();
                fusoulist.removeAt(i);
            }
        }
    }
    if(yamatolist.size() != 0){
        for(int i = 0; i < yamatolist.size();i++) {
            if(yamatolist.at(i)->x+160 >= 220 && attacktime > 0){
                yamatolist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(yamatolist.at(i)->health <= 0){
                removeItem(yamatolist.at(i));
                yamatolist.at(i)->hpbar->hide();
                yamatolist.removeAt(i);
            }
        }
    }
    if(ryuujoulist.size() != 0){
        for(int i = 0; i < ryuujoulist.size();i++) {
            if(ryuujoulist.at(i)->x+160 >= 220 && attacktime > 0){
                ryuujoulist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(ryuujoulist.at(i)->health <= 0){
                removeItem(ryuujoulist.at(i));
                ryuujoulist.at(i)->hpbar->hide();
                ryuujoulist.removeAt(i);
            }
        }
    }
    if(akagilist.size() != 0){
        for(int i = 0; i < akagilist.size();i++) {
            if(akagilist.at(i)->x+160 >= 220 && attacktime > 0){
                akagilist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(akagilist.at(i)->health <= 0){
                removeItem(akagilist.at(i));
                akagilist.at(i)->hpbar->hide();
                akagilist.removeAt(i);
            }
        }
    }
    if(taiholist.size() != 0){
        for(int i = 0; i < taiholist.size();i++) {
            if(taiholist.at(i)->x+160 >= 220 && attacktime > 0){
                taiholist.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(taiholist.at(i)->health <= 0){
                removeItem(taiholist.at(i));
                taiholist.at(i)->hpbar->hide();
                taiholist.removeAt(i);
            }
        }
    }
    if(i168list.size() != 0){
        for(int i = 0; i < i168list.size();i++) {
            if(i168list.at(i)->x+160 >= 220 && attacktime > 0){
                i168list.at(i)->health -= boss->attack;
                --attacktime;
            }
            if(i168list.at(i)->health <= 0){
                removeItem(i168list.at(i));
                i168list.at(i)->hpbar->hide();
                i168list.removeAt(i);
            }
        }
    }
}

void Mainscene::FubukiAttack(){
    if(minifubuki->x+160+minifubuki->attack_range >= 820 && minifubuki->health > 0){
        boss->health -= minifubuki->attack;
    cout << "minifubuki" << endl;
    }
}

void Mainscene::KumaAttack() {
    if(minikuma->x+160+minikuma->attack_range >= 820 && minikuma->health > 0){
        boss->health -= minikuma->attack;
    cout << "minikuma" << endl;}
}

void Mainscene::KitakamiAttack() {
    if(minikitakami->x+160+minikitakami->attack_range >= 820 && minikitakami->health > 0){
        boss->health -= minikitakami->attack;
    cout << "minikitakami" << endl;}
}

void Mainscene::FurutakaAttack() {
    if(minifurutaka->x+160+minifurutaka->attack_range >= 820 && minifurutaka->health > 0){
        boss->health -= minifurutaka->attack;
    cout << "minifurutaka" << endl;}
}

void Mainscene::SuzuyaAttack() {
    if(minisuzuya->x+160+minisuzuya->attack_range >= 820 && minisuzuya->health > 0){
        boss->health -= minisuzuya->attack;
    cout << "minisuzuya" << endl;}
}

void Mainscene::KongoAttack() {
    if(minikongo->x+160+minikongo->attack_range >= 820 && minikongo->health > 0){
        boss->health -= minikongo->attack;
    cout << "minikongo" << endl;}
}

void Mainscene::FusouAttack() {
    if(minifusou->x+160+minifusou->attack_range >= 820 && minifusou->health > 0){
        boss->health -= minifusou->attack;
    cout << "minifusou" << endl;}
}

void Mainscene::YamatoAttack() {
    if(miniyamato->x+160+miniyamato->attack_range >= 820 && miniyamato->health > 0){
        boss->health -= miniyamato->attack;
    cout << "miniyamato" << endl;}
}

void Mainscene::RyuujouAttack() {
    if(miniryuujou->x+160+miniryuujou->attack_range >= 820 && miniryuujou->health > 0){
        boss->health -= miniryuujou->attack;
    cout << "miniryuujou" << endl;}
}

void Mainscene::AkagiAttack() {
    if(miniakagi->x+160+miniakagi->attack_range >= 820 && miniakagi->health > 0){
        boss->health -= miniakagi->attack;
    cout << "miniakagi" << endl;}
}

void Mainscene::TaihoAttack() {
    if(minitaiho->x+160+minitaiho->attack_range >= 820 && minitaiho->health > 0){
        boss->health -= minitaiho->attack;
    cout << "minitaiho" << endl;}
}

void Mainscene::I168Attack() {
    if(minii168->x+160+minii168->attack_range >= 820 && minii168->health > 0){
        boss->health -= minii168->attack;
        cout << "minii168" << endl;

    }
}

void Mainscene::ShowTime(){
    clock->display(--totaltime);
    initialmana += 2;
    if(initialmana > 20){
        initialmana = 20;
    }
    if(totaltime <= 100)
        this->setBackgroundBrush(QImage("../project2/images/background_night.jpg"));
    if(totaltime >= 0 && boss->health <= 0){
        move->stop();
        change->stop();
        time->stop();
        fubuki_btn->setCursor(Qt::ArrowCursor);
        kuma_btn->setCursor(Qt::ArrowCursor);
        kitakami_btn->setCursor(Qt::ArrowCursor);
        furutaka_btn->setCursor(Qt::ArrowCursor);
        suzuya_btn->setCursor(Qt::ArrowCursor);
        kongo_btn->setCursor(Qt::ArrowCursor);
        fusou_btn->setCursor(Qt::ArrowCursor);
        yamato_btn->setCursor(Qt::ArrowCursor);
        ryuujou_btn->setCursor(Qt::ArrowCursor);
        akagi_btn->setCursor(Qt::ArrowCursor);
        taiho_btn->setCursor(Qt::ArrowCursor);
        i168_btn->setCursor(Qt::ArrowCursor);
        fubukilist.clear();
        kumalist.clear();
        kitakamilist.clear();
        furutakalist.clear();
        suzuyalist.clear();
        kongolist.clear();
        fusoulist.clear();
        yamatolist.clear();
        ryuujoulist.clear();
        akagilist.clear();
        taiholist.clear();
        i168list.clear();
        QGraphicsPixmapItem *bg = new QGraphicsPixmapItem(QPixmap("../project2/images/hannahlove.jpg"));
        QGraphicsPixmapItem *win = new QGraphicsPixmapItem(QPixmap("../project2/images/win.png"));
        bg->setPos(0,0);
        win->setPos(100,198);
        this->addItem(bg);
        this->addItem(win);
        SetScreen = 6;
    }
    else if(totaltime == 0 && boss->health > 0) {
        move->stop();
        change->stop();
        time->stop();
        fubuki_btn->setCursor(Qt::ArrowCursor);
        kuma_btn->setCursor(Qt::ArrowCursor);
        kitakami_btn->setCursor(Qt::ArrowCursor);
        furutaka_btn->setCursor(Qt::ArrowCursor);
        suzuya_btn->setCursor(Qt::ArrowCursor);
        kongo_btn->setCursor(Qt::ArrowCursor);
        fusou_btn->setCursor(Qt::ArrowCursor);
        yamato_btn->setCursor(Qt::ArrowCursor);
        ryuujou_btn->setCursor(Qt::ArrowCursor);
        akagi_btn->setCursor(Qt::ArrowCursor);
        taiho_btn->setCursor(Qt::ArrowCursor);
        i168_btn->setCursor(Qt::ArrowCursor);
        fubukilist.clear();
        kumalist.clear();
        kitakamilist.clear();
        furutakalist.clear();
        suzuyalist.clear();
        kongolist.clear();
        fusoulist.clear();
        yamatolist.clear();
        ryuujoulist.clear();
        akagilist.clear();
        taiholist.clear();
        i168list.clear();
        QGraphicsPixmapItem *bg = new QGraphicsPixmapItem(QPixmap("../project2/images/UCCU.jpg"));
        QGraphicsPixmapItem *lose = new QGraphicsPixmapItem(QPixmap("../project2/images/lose.png"));
        bg->setPos(0,0);
        lose->setPos(414,273);
        this->addItem(bg);
        this->addItem(lose);
        SetScreen = 6;
    }

}

void Mainscene::ShowMana(){
    mana->display(initialmana);
}
