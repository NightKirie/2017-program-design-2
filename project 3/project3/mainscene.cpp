#include "mainscene.h"


Mainscene::Mainscene(){
    SetScreen = 0;
    //0 for initial the game
    //1 for click play
    //2 for input player name
    //3 for main page
    //4 for group page
    //5 for pick ship page
    //6 for battle page
    //7 for settlement
    //8 for drawcard
    //10 for error neko chan
}

void Mainscene::InitThings(){
    //innitial total cards
    timewait = new QTimer;
    for(int i = 0; i < 30; i++){
        cards = new Cardsetting(i);
        totalcard.append(cards);
    }
    movie = new QMovie;
    movie->setFileName("../project3/videos/first.gif");
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
    else if(SetScreen == 2){
        //username
        if(event->scenePos().x() > 475 && event->scenePos().x() <= 723) {
            if(event->scenePos().y() > 507 && event->scenePos().y() <= 593) {
                Readuserdata();
                this->clear();
                movie->setFileName("../project3/videos/third");
                movie->setPaused(false);
                this->setBackgroundBrush(Qt::transparent);
                QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
                    if (frameNumber > movie->frameCount() - 1){
                        ChangeGif();
                    }
                });
            }
        }
    }
    else if(SetScreen == 3){
        //main screen
        if(event->scenePos().y() > groupbutton_btn->pos().y()+30 && event->scenePos().y() <= groupbutton_btn->pos().y()+105) {
            if(event->scenePos().x() > groupbutton_btn->pos().x()+30 && event->scenePos().x() <= groupbutton_btn->pos().x()+105) {
                SetScreen = 4;
                SetGroupScreen();
            }
        }   //press group button
        else if(event->scenePos().y() > supplybutton_btn->pos().y()+30 && event->scenePos().y() <= attackbutton_btn->pos().y()+170) {
            if(event->scenePos().x() > supplybutton_btn->pos().x()+30 && event->scenePos().x() <= supplybutton_btn->pos().x()+105) {
                SetScreen = 10;
                ErrorScreen();
            }   //press supply button
            else if(event->scenePos().x() > attackbutton_btn->pos().x()+65 && event->scenePos().x() <= attackbutton_btn->pos().x()+180) {
                SetScreen = 6;
                BattleScreen();
            }   //press attack button
            else if(event->scenePos().x() > changebutton_btn->pos().x()+30 && event->scenePos().x() <= changebutton_btn->pos().x()+105) {
                SetScreen = 10;
                ErrorScreen();
            }   //press change button
        }
        else if(event->scenePos().y() > repairbutton_btn->pos().y()+30 && event->scenePos().y() <= repairbutton_btn->pos().y()+105) {
            if(event->scenePos().x() > repairbutton_btn->pos().x()+30 && event->scenePos().x() <= repairbutton_btn->pos().x()+105) {
                SetScreen = 10;
                ErrorScreen();
            }   //press repair button
            else if(event->scenePos().x() > factorybutton_btn->pos().x()+30 && event->scenePos().x() <= factorybutton_btn->pos().x()+105) {
                SetScreen = 10;
                ErrorScreen();
            }   //press factory button
        }
    }
    else if(SetScreen == 4){
        //group page
        if(event->scenePos().x() > 3 && event->scenePos().x() <= 58) {
            //the leftest bar
            if(event->scenePos().y() > 276 && event->scenePos().y() <= 343) {
                SetScreen = 10;
                ErrorScreen();
            }
            else if(event->scenePos().y() > 357 && event->scenePos().y() <= 424) {
                SetScreen = 10;
                ErrorScreen();
            }
            else if(event->scenePos().y() > 439 && event->scenePos().y() <= 506) {
                SetScreen = 10;
                ErrorScreen();
            }
            else if(event->scenePos().y() > 517 && event->scenePos().y() <= 584) {
                SetScreen = 10;
                ErrorScreen();
            }
        }
        else if(event->scenePos().x() > 85 && event->scenePos().x() <= 134) {
            //the back to main page btn
            if(event->scenePos().y() > 329 && event->scenePos().y() <= 443) {
                this->clear();
                SetScreen = 3;
                SetMainScreen();
            }
        }
        else if(event->scenePos().x() > 182 && event->scenePos().x() <= 675) {
            //the first column of pick
            if(event->scenePos().y() > 200 && event->scenePos().y() <= 356 && (pickedcard == 0 || pickedcard == 1)) {
                SetScreen = 5;
                selarea = 0;
                Pickcard();
            }
            else if(event->scenePos().y() > 369 && event->scenePos().y() <= 525 && (pickedcard == 2 || pickedcard == 3)) {
                SetScreen = 5;
                selarea = 2;
                Pickcard();
            }
            else if(event->scenePos().y() > 539 && event->scenePos().y() <= 695 && (pickedcard == 4 || pickedcard == 5)) {
                SetScreen = 5;
                selarea = 4;
                Pickcard();
            }
        }
        else if(event->scenePos().x() > 695 && event->scenePos().x() <= 1188) {
            //the second column of pick
            if(event->scenePos().y() > 200 && event->scenePos().y() <= 356 && (pickedcard == 1 || pickedcard == 2)) {
                SetScreen = 5;
                selarea = 1;
                Pickcard();
            }
            else if(event->scenePos().y() > 369 && event->scenePos().y() <= 525 && (pickedcard == 3 || pickedcard == 4)) {
                SetScreen = 5;
                selarea = 3;
                Pickcard();
            }
            else if(event->scenePos().y() > 539 && event->scenePos().y() <= 695 && (pickedcard == 5 || pickedcard == 6)) {
                SetScreen = 5;
                selarea = 5;
                Pickcard();
            }
        }
    }
    else if(SetScreen == 5){
        //pick the card
        if(event->scenePos().x() > 0 && event->scenePos().x() <= 200) {
            if(event->scenePos().y() > 260 && event->scenePos().y() <= 460) {
                //to left
                if(own[firstintro] == 1)    //own
                    removeItem(totalcard.at(firstintro)->previewpic);
                else if(own[firstintro] == 0)   //not own
                    removeItem(totalcard.at(22)->previewpic);
                else if(own[firstintro] == 2)   //picked
                    removeItem(totalcard.at(23)->previewpic);

                if(firstintro == 0){
                    firstintro = 21;
                    if(own[firstintro] == 1)    //own
                        addItem(totalcard.at(firstintro)->previewpic);
                    else if(own[firstintro] == 0)   //not own
                        addItem(totalcard.at(22)->previewpic);
                    else if(own[firstintro] == 2)   //picked
                        addItem(totalcard.at(23)->previewpic);
                }
                else{
                    --firstintro;
                    if(own[firstintro] == 1)    //own
                        addItem(totalcard.at(firstintro)->previewpic);
                    else if(own[firstintro] == 0)   //not own
                        addItem(totalcard.at(22)->previewpic);
                    else if(own[firstintro] == 2)   //picked
                        addItem(totalcard.at(23)->previewpic);
                }
            }
        }
        else if(event->scenePos().x() > 200 && event->scenePos().x() <= 1000) {
            //pick it!
            if(firstintro == 0){
                if(pickedcard == 0){
                    removeItem(totalcard.at(firstintro)->previewpic);
                    SetScreen = 4;
                    SetGroupScreen();
                }
                else if(pickedcard != 0 && selarea == pickedcard){
                    removeItem(totalcard.at(firstintro)->previewpic);
                    SetScreen = 4;
                    SetGroupScreen();
                }
                else if(pickedcard != 0 && selarea == (pickedcard - 1)){
                    own[ingroup[pickedcard - 1]] = 1;
                    ingroup[pickedcard - 1] = 0;
                    --pickedcard;
                    removeItem(totalcard.at(firstintro)->previewpic);
                    SetScreen = 4;
                    SetGroupScreen();
                }
            }   //delete choose
            else if(firstintro != 0 && own[firstintro] == 1){
                if(pickedcard == 6){
                    own[ingroup[5]] = 1;
                    ingroup[5] = firstintro;
                    own[firstintro] = 2;
                    removeItem(totalcard.at(firstintro)->previewpic);
                    SetScreen = 4;
                    SetGroupScreen();
                }
                else if(pickedcard != 6){
                    ingroup[pickedcard] = firstintro;
                    own[firstintro] = 2;
                    ++pickedcard;
                    removeItem(totalcard.at(firstintro)->previewpic);
                    SetScreen = 4;
                    SetGroupScreen();
                }
            }   //add choose

        }
        else if(event->scenePos().x() > 1000 && event->scenePos().x() <= 1200) {
            if(event->scenePos().y() > 260 && event->scenePos().y() <= 460) {
                //to right
                if(own[firstintro] == 1)    //own
                    removeItem(totalcard.at(firstintro)->previewpic);
                else if(own[firstintro] == 0)   //not own
                    removeItem(totalcard.at(22)->previewpic);
                else if(own[firstintro] == 2)   //picked
                    removeItem(totalcard.at(23)->previewpic);

                if(firstintro == 21){
                    firstintro = 0;
                    if(own[firstintro] == 1)    //own
                        addItem(totalcard.at(firstintro)->previewpic);
                    else if(own[firstintro] == 0)   //not own
                        addItem(totalcard.at(22)->previewpic);
                    else if(own[firstintro] == 2)   //picked
                        addItem(totalcard.at(23)->previewpic);
                }
                else{
                    ++firstintro;
                    if(own[firstintro] == 1)    //own
                        addItem(totalcard.at(firstintro)->previewpic);
                    else if(own[firstintro] == 0)   //not own
                        addItem(totalcard.at(22)->previewpic);
                    else if(own[firstintro] == 2)   //picked
                        addItem(totalcard.at(23)->previewpic);
                }
            }
        }
    }
    else if(SetScreen == 7){
        SetScreen = 100;
        Drawcard();
    }
    else if(SetScreen == 8){
        removeItem(get);
        SetScreen = 3;
        SetMainScreen();
    }
}

void Mainscene::MovieChange() {
    this->clear();
    movie->setPaused(true);
    movie->setFileName("../project3/videos/second.gif");
    movie->setPaused(false);
    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber > movie->frameCount() - 1){
           ChangeGif();
        }
    });
}

void Mainscene::Inputplayername(){
    this->clear();
    setBackgroundBrush(QImage("../project3/images/setusername.png"));
    confirmusername = new Confirmusername;
    addItem(confirmusername);
    username = new QLineEdit;
    username->setMaxLength(12);
    username->setFont(QFont ("Arial", 30));
    username->setGeometry(376,333,449,50);
    addWidget(username);
    username->setFocus();
}

void Mainscene::Readuserdata(){
    username_str = username->text();
    if(username_str.isEmpty())
        username_str = "guest";
    username_str.append(".txt");
    username_str.prepend("../project3/savedata/");
    if(savedata.exists(username_str)){
        savedata.setFileName(username_str);
        savedata.open(QIODevice::ReadOnly);
        QTextStream in(&savedata);
        for(int i = 0; i < 6; i++)
            in >> ingroup[i];
        for(int i = 0; i < 22; i++)
            in >> own[i];
        in >> pickedcard;
        savedata.close();
    }
    else{
        savedata.setFileName(username_str);
        savedata.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        QTextStream out(&savedata);
        out << "0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0" << endl;
        savedata.close();
    }
}

void Mainscene::SetMainScreen(){
    for(int i = 1; i < 22; i++)
        totalcard.at(i)->cur_hp = totalcard.at(i)->ori_hp;
    for(int i = 24; i < 30; i++)
        totalcard.at(i)->cur_hp = totalcard.at(i)->ori_hp;

    Storeuserdata();
    this->setBackgroundBrush(QImage("../project3/images/background_title.jpg"));

    attackbutton_btn = new Attack_btn;
    addItem(attackbutton_btn);

    changebutton_btn = new Change_btn;
    addItem(changebutton_btn);

    factorybutton_btn = new Factory_btn;
    addItem(factorybutton_btn);

    groupbutton_btn = new Group_btn;
    addItem(groupbutton_btn);

    repairbutton_btn = new Repair_btn;
    addItem(repairbutton_btn);

    supplybutton_btn = new Supply_btn;
    addItem(supplybutton_btn);
}

void Mainscene::SetGroupScreen() {
    this->clear();
    this->setBackgroundBrush(QImage("../project3/images/group_background.png"));

    backtomain_btn = new Backtomain_btn;
    addItem(backtomain_btn);

    smallsupply_btn = new Smallsupply_btn;
    addItem(smallsupply_btn);

    smallchange_btn = new Smallchange_btn;
    addItem(smallchange_btn);

    smallrepair_btn = new Smallrepair_btn;
    addItem(smallrepair_btn);

    smallfactory_btn = new Smallfactory_btn;
    addItem(smallfactory_btn);

    for(int i = 0; i < 6; i++){
        if(ingroup[i] != 0) {
            cards = new Cardsetting(ingroup[i]);
            cards->grouppic->setPos(groupxpos[i], groupypos[i]);
            addItem(cards->grouppic);
        }
    }   //show the grouppic;
    if(pickedcard == 0){
        select_btn = new Select_btn;
        select_btn->setPos(182,200);
        addItem(select_btn);
    }
    else if(pickedcard == 2){
        select_btn = new Select_btn;
        select_btn->setPos(182,369);
        addItem(select_btn);
    }
    else if(pickedcard == 4){
        select_btn = new Select_btn;
        select_btn->setPos(182,539);
        addItem(select_btn);
    }
    else if(pickedcard == 1){
        select_btn = new Select_btn;
        select_btn->setPos(695,200);
        addItem(select_btn);
    }
    else if(pickedcard == 3){
        select_btn = new Select_btn;
        select_btn->setPos(695,369);
        addItem(select_btn);
    }
    else if(pickedcard == 5){
        select_btn = new Select_btn;
        select_btn->setPos(695,539);
        addItem(select_btn);
    }
}

void Mainscene::Pickcard(){
    this->clear();
    this->setBackgroundBrush(Qt::black);
    left_btn = new Left_btn;
    right_btn = new Right_btn;
    firstintro = 0;
    addItem(totalcard.at(firstintro)->previewpic);
    addItem(left_btn);
    addItem(right_btn);
}

void Mainscene::Storeuserdata(){
    if(username_str != "../project3/savedata/guest.txt") {
        savedata.setFileName(username_str);
        savedata.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);
        QTextStream out(&savedata);
        for(int i = 0; i < 6; i++)
            out << ingroup[i] << " ";
        for(int i = 0; i < 22; i++)
            out << own[i] << " ";
        out << pickedcard;
        savedata.close();
    }
}

void Mainscene::BattleScreen(){
    this->clear();
    this->setBackgroundBrush(Qt::transparent);
    movie->setFileName("../project3/videos/battlestart.gif");
    movie->setPaused(false);
    QObject::connect(movie, &QMovie::frameChanged, [=](int frameNumber) {
        if (frameNumber > movie->frameCount() - 1){
            ChangeGif();
        }
    });
}

void Mainscene::Setbattlescreen(){
    int posy = 0;
    for(int i = 0; i < 6; i++){
        if(ingroup[i] != 0){
            totalcard.at(ingroup[i])->battlepic->setPos(0,174+posy);
            addItem(totalcard.at(ingroup[i])->battlepic);
        }
        posy += 62;
    }
    posy = 0;
    for(int i = 0; i < 6; i++){
        totalcard.at(enemy[i])->battlepic->setPos(971,174+posy);
        addItem(totalcard.at(enemy[i])->battlepic);
        posy += 62;
    }
    timewait->singleShot(2000, this, SLOT(Setwait()));
}

void Mainscene::Setairstrike(){
    target = rand() % 5;
    if(totalcard.at(enemy[target])->cur_hp <= 0)
        target = rand() % 5;
    bool exist = false;
    for(int i = 0; i < 6; i++){
        if(totalcard.at(ingroup[i])->air_strike == true){
            exist = true;
            totalcard.at(ingroup[i])->battlepic->setX(100);
        }
    }
    if(exist == true) {
        totalcard.at(enemy[target])->battlepic->setX(871);
        timewait->singleShot(2500, this, SLOT(Eachairstrike()));
    }
    else if(exist == false)
        Setsubstrike();
}

void Mainscene::Setsubstrike(){
    target = 5;
    bool exist = false;
    for(int i = 0; i < 6; i++){
        if(ingroup[i] == 13 || ingroup[i] == 17){
            exist = true;
            totalcard.at(ingroup[i])->battlepic->setX(100);
        }
    }
    if(exist == true) {
        totalcard.at(enemy[target])->battlepic->setX(871);
        timewait->singleShot(2500, this, SLOT(Eachsubstrike()));
    }
    else if(exist == false)
        Setfirsttor();
}

void Mainscene::Setfirsttor(){
    target = rand() % 5;
    if(totalcard.at(enemy[target])->cur_hp <= 0)
        target = rand() % 5;
    bool exist = false;
    for(int i = 0; i < 6; i++){
        if(ingroup[i] == 4 || ingroup[i] == 9 || ingroup[i] == 19 || ingroup[i] == 20){
            exist = true;
            totalcard.at(ingroup[i])->battlepic->setX(100);
        }
    }
    if(exist == true) {
        totalcard.at(enemy[target])->battlepic->setX(871);
        timewait->singleShot(2500, this, SLOT(Eachfirsttor()));
    }
    else if(exist == false)
        Setattack();
}

void Mainscene::Setattack(){
    target = rand() % 6;
    round = 0;
    current = 0;
    if(current % 2 == 0 && totalcard.at(ingroup[current])->cur_hp > 0) {
        totalcard.at(ingroup[current/2])->battlepic->setX(100);
        totalcard.at(enemy[target])->battlepic->setX(871);
    }
    else if(current % 2 == 1 && totalcard.at(enemy[current])->cur_hp > 0){
        totalcard.at(enemy[current/2])->battlepic->setX(871);
        totalcard.at(ingroup[target])->battlepic->setX(100);
    }

    connect(timewait,SIGNAL(timeout()), this, SLOT(Eachattack()));
    timewait->start(1000);
}

void Mainscene::Setsecondtor(){
    target = rand() % 5;
    int count = 0;
    for(int i = 0; i < 6; i++){
        if(totalcard.at(enemy[i])->cur_hp <= 0){
            target = rand() % 5;
            ++count;
        }
    }
    bool exist = false;
    for(int i = 0; i < 6; i++){
        if(totalcard.at(ingroup[i])->sub_strike == true){
            totalcard.at(ingroup[i])->battlepic->setX(100);
            exist = true;
        }
    }
    if(exist == true && count != 6){
        totalcard.at(enemy[target])->battlepic->setX(871);
        timewait->singleShot(2500, this, SLOT(Eachsecondtor()));
    }
    else if(exist == false || count == 6)
        Settlement();

}

void Mainscene::Settlement(){    
    timewait->singleShot(3000, this, SLOT(Eachsettlement()));
}

void Mainscene::Drawcard(){
    setBackgroundBrush(QImage("../project3/images/drawbg.png"));
    removeItem(result);
    get = new QGraphicsPixmapItem(QPixmap("../project3/images/get.png"));
    get->setPos(0,0);
    addItem(get);
    timewait->singleShot(3000, this, SLOT(Eachdrawcard()));
}

void Mainscene::ErrorScreen(){
    this->clear();
    this->setBackgroundBrush(QImage("../project3/images/error.jpg"));
}

void Mainscene::ChangeGif() {
    if(SetScreen == 0){
        startbutton_btn = new Start_btn;
        addItem(startbutton_btn);
        movie->setPaused(true);
        movie->setFileName("../project3/videos/loop.gif");
        movie->setPaused(false);
    }
    else if(SetScreen == 1){
        movie->setPaused(true);        
        SetScreen = 2;
        Inputplayername();
    }
    else if(SetScreen == 2){
        movie->setPaused(true);
        SetScreen = 3;
        SetMainScreen();
    }
    else if(SetScreen == 6){
        movie->setPaused(true);
        this->setBackgroundBrush(QPixmap("../project3/images/background_day.jpg"));
        Setbattlescreen();
    }
}

void Mainscene::Setwait(){
    Setairstrike();
}

void Mainscene::Eachairstrike(){
    int attack = 0;
    for(int i = 0; i < 6; i++){
        if(totalcard.at(ingroup[i])->air_strike == true){
            cout << ingroup[i] << endl;
            totalcard.at(ingroup[i])->battlepic->setX(0);
            attack += totalcard.at(ingroup[i])->air_atk;
        }
    }
    totalcard.at(enemy[target])->cur_hp -= attack;
    totalcard.at(enemy[target])->battlepic->setX(971);
    if(totalcard.at(enemy[target])->cur_hp <= 0)
        removeItem(totalcard.at(enemy[target])->battlepic);

    Setsubstrike();
}

void Mainscene::Eachsubstrike(){
    int attack = 0;
    for(int i = 0; i < 6; i++){
        if(ingroup[i] == 13 || ingroup[i] == 17){
            cout << ingroup[i] << endl;
            totalcard.at(ingroup[i])->battlepic->setX(0);
            attack += totalcard.at(ingroup[i])->sub_atk;
        }
    }
    totalcard.at(enemy[target])->cur_hp -= attack;
    totalcard.at(enemy[target])->battlepic->setX(971);
    if(totalcard.at(enemy[target])->cur_hp <= 0)
        removeItem(totalcard.at(enemy[target])->battlepic);
    Setfirsttor();
}

void Mainscene::Eachfirsttor(){
    int attack = 0;
    for(int i = 0; i < 6; i++){
        if(ingroup[i] == 4 || ingroup[i] == 9 || ingroup[i] == 19 || ingroup[i] == 20){
            cout << ingroup[i] << endl;
            totalcard.at(ingroup[i])->battlepic->setX(0);
            attack += totalcard.at(ingroup[i])->torpedo;
        }
    }
    totalcard.at(enemy[target])->cur_hp -= attack;
    totalcard.at(enemy[target])->battlepic->setX(971);
    if(totalcard.at(enemy[target])->cur_hp <= 0)
        removeItem(totalcard.at(enemy[target])->battlepic);
    Setattack();
}

void Mainscene::Eachattack(){
    if(current % 2 == 0 && totalcard.at(ingroup[current/2])->cur_hp > 0){
        cout << ingroup[current/2] << endl;
        totalcard.at(ingroup[current/2])->battlepic->setX(0);
        totalcard.at(enemy[target])->battlepic->setX(971);
        totalcard.at(enemy[target])->cur_hp -= totalcard.at(ingroup[current/2])->attack;
        if(totalcard.at(enemy[target])->cur_hp <= 0)
            removeItem(totalcard.at(enemy[target])->battlepic);
    }
    else if(current % 2 == 1 && totalcard.at(enemy[current/2])->cur_hp > 0){
        cout << enemy[current/2] << endl;
        totalcard.at(enemy[current/2])->battlepic->setX(971);
        totalcard.at(ingroup[target])->battlepic->setX(0);
        totalcard.at(ingroup[target])->cur_hp -= totalcard.at(enemy[current/2])->attack;
        if(totalcard.at(ingroup[target])->cur_hp <= 0)
            removeItem(totalcard.at(ingroup[target])->battlepic);
    }
    target = rand() % 6;
    ++current;
    if(current == 12 && round == 0){
        current = 0;
        round = 1;
    }
    else if(current == 12 && round == 1){
        timewait->stop();
        disconnect(timewait,SIGNAL(timeout()), this, SLOT(Eachattack()));
        Setsecondtor();
    }
}

void Mainscene::Eachsecondtor(){
    int attack = 0;
    for(int i = 0; i < 6; i++){
        if(totalcard.at(ingroup[i])->sub_strike == true){
            cout << ingroup[i] << endl;
            totalcard.at(ingroup[i])->battlepic->setX(0);
            attack += totalcard.at(ingroup[i])->torpedo;
        }
    }
    totalcard.at(enemy[target])->cur_hp -= attack;
    totalcard.at(enemy[target])->battlepic->setX(971);
    if(totalcard.at(enemy[target])->cur_hp <= 0)
        removeItem(totalcard.at(enemy[target])->battlepic);
    Settlement();
}

void Mainscene::Eachsettlement(){
    SetScreen = 7;
    for(int i = 0; i < 6; i++){
        if(ingroup[i] != 0 && totalcard.at(ingroup[i])->cur_hp != 0)
            removeItem(totalcard.at(ingroup[i])->battlepic);
    }
    for(int i = 0; i < 6; i++){
        if(totalcard.at(enemy[i])->cur_hp != 0)
            removeItem(totalcard.at(enemy[i])->battlepic);
    }
    result = new QGraphicsPixmapItem;
    if(totalcard.at(enemy[0])->cur_hp > 0){
        result->setPos(414,273);
        result->setPixmap(QPixmap("../project3/images/lose.png"));
    }
    else if(totalcard.at(enemy[0])->cur_hp <= 0){
        result->setPos(100,198);
        result->setPixmap(QPixmap("../project3/images/win.png"));
    }
    addItem(result);
    setBackgroundBrush(Qt::black);
}

void Mainscene::Eachdrawcard(){
    SetScreen = 8;
    removeItem(get);
    for(int i = 0; i < 23; i++){
        if(own[getid[i]] == 0){
            get = totalcard.at(getid[i])->previewpic;
            get->setPos(200,0);
            own[getid[i]] = 1;
            break;
        }
        else if(i == 22 && own[getid[i]] != 0){
            get = totalcard.at(1)->previewpic;
            get->setPos(200,0);
            break;
        }
    }
    addItem(get);
}

