#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <iostream>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QTime>
#include <QTimeLine>
#include <QSound>
#include <QMovie>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QLCDNumber>
#include <QList>
#include <QLineEdit>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QThread>
#include "start_btn.h"
#include "attack_btn.h"
#include "repair_btn.h"
#include "factory_btn.h"
#include "change_btn.h"
#include "supply_btn.h"
#include "group_btn.h"
#include "select_btn.h"
#include "backtomain_btn.h"
#include "smallchange_btn.h"
#include "smallfactory_btn.h"
#include "smallrepair_btn.h"
#include "smallsupply_btn.h"
#include "cardsetting.h"
#include "confirmusername.h"
#include "left_btn.h"
#include "right_btn.h"


using namespace std;

class Mainscene : public QGraphicsScene
{
    Q_OBJECT

public:
    Mainscene();
    int SetScreen;
    int pickedcard = 0;
    int own[22] = {1,0,0,1,1,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,1,1};
    int ingroup[6] = {0,0,0,0,0,0};
    int enemy[6] = {24,25,26,27,28,29};
    int firstintro = 0; //first card show up in the pick page
    int selarea;
    int groupxpos[6] = {182,695,182,695,182,695};
    int groupypos[6] = {200,200,369,369,539,539};
    int getid[22] = {0,12,11,13,10,8,14,9,17,4,19,20,21,15,6,7,5,3,2,1,16,18};
    void InitThings();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void MovieChange();
    void SetMainScreen();
    void ErrorScreen();
    void BattleScreen();
    void ChangeGif();
    void SetGroupScreen();
    void Pickcard();
    void Inputplayername();
    void Readuserdata();
    void Storeuserdata();
    void Setbattlescreen();
    void Setairstrike();
    void Setsubstrike();
    void Setfirsttor();
    void Setattack();
    void Setsecondtor();
    void Settlement();
    void Drawcard();
    QTimer *timewait;
    QMovie *movie;
    Start_btn *startbutton_btn;
    Attack_btn *attackbutton_btn;
    Repair_btn *repairbutton_btn;
    Factory_btn *factorybutton_btn;
    Change_btn *changebutton_btn;
    Supply_btn *supplybutton_btn;
    Group_btn *groupbutton_btn;
    Select_btn *select_btn;
    Backtomain_btn *backtomain_btn;
    Smallchange_btn *smallchange_btn;
    Smallfactory_btn *smallfactory_btn;
    Smallrepair_btn *smallrepair_btn;
    Smallsupply_btn *smallsupply_btn;
    Cardsetting *cards;
    QList<Cardsetting*> totalcard;
    QLineEdit *username;
    Confirmusername *confirmusername;
    Left_btn *left_btn;
    Right_btn *right_btn;
    QString username_str;
    QFile savedata;
    QGraphicsPixmapItem *result;
    QGraphicsPixmapItem *get;
    int round = 0;
    int current = 0;
    int target;
public slots:
    void Setwait();
    void Eachairstrike();
    void Eachsubstrike();
    void Eachfirsttor();
    void Eachattack();
    void Eachsecondtor();
    void Eachsettlement();
    void Eachdrawcard();
};

#endif // MAINSCENE_H
