#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <iostream>
#include <QMainWindow>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QTime>
#include <QSound>
#include <QMovie>
#include <QGraphicsView>
#include <QLabel>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QLCDNumber>
#include <QList>
#include "start_btn.h"
#include "attack_btn.h"
#include "repair_btn.h"
#include "factory_btn.h"
#include "change_btn.h"
#include "supply_btn.h"
#include "group_btn.h"
#include "fubuki.h"
#include "kuma.h"
#include "kitakami.h"
#include "furutaka.h"
#include "suzuya.h"
#include "kongo.h"
#include "fusou.h"
#include "yamato.h"
#include "ryuujou.h"
#include "akagi.h"
#include "taiho.h"
#include "i168.h"
#include "boss.h"



using namespace std;

class Mainscene : public QGraphicsScene
{
    Q_OBJECT

public:
    Mainscene();
    int SetScreen;
    int ID;
    void InitThings();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void MovieChange();
    void SetMainScreen();
    void ErrorScreen();
    void BattleScreen();
    void ChangeGif();
    void SetBattlebutton();
    void SetMinions();
    QTimer *change;
    QTimer *move;
    QTimer *time;
    QMovie *movie;
    QGraphicsPixmapItem *intro;
    Start_btn *startbutton_btn;
    Attack_btn *attackbutton_btn;
    Repair_btn *repairbutton_btn;
    Factory_btn *factorybutton_btn;
    Change_btn *changebutton_btn;
    Supply_btn *supplybutton_btn;
    Group_btn *groupbutton_btn;
    QPushButton *fubuki_btn;
    QPushButton *kuma_btn;
    QPushButton *kitakami_btn;
    QPushButton *furutaka_btn;
    QPushButton *suzuya_btn;
    QPushButton *kongo_btn;
    QPushButton *fusou_btn;
    QPushButton *yamato_btn;
    QPushButton *ryuujou_btn;
    QPushButton *akagi_btn;
    QPushButton *taiho_btn;
    QPushButton *i168_btn;
    Fubuki *minifubuki;
    Kuma *minikuma;
    Kitakami *minikitakami;
    Furutaka *minifurutaka;
    Suzuya *minisuzuya;
    Kongo *minikongo;
    Fusou *minifusou;
    Yamato *miniyamato;
    Ryuujou *miniryuujou;
    Akagi *miniakagi;
    Taiho *minitaiho;
    I168 *minii168;
    Boss *boss;
    QLCDNumber *clock;
    QLCDNumber *mana;
    QLabel *clocklb;
    QLabel *manalb;
    QList <Fubuki*> fubukilist;
    QList <Kuma*> kumalist;
    QList <Kitakami*> kitakamilist;
    QList <Furutaka*> furutakalist;
    QList <Suzuya*> suzuyalist;
    QList <Kongo*> kongolist;
    QList <Fusou*> fusoulist;
    QList <Yamato*> yamatolist;
    QList <Ryuujou*> ryuujoulist;
    QList <Akagi*> akagilist;
    QList <Taiho*> taiholist;
    QList <I168*> i168list;

public slots:
    void BossAttack();
    void FubukiAttack();
    void KumaAttack();
    void KitakamiAttack();
    void FurutakaAttack();
    void SuzuyaAttack();
    void KongoAttack();
    void FusouAttack();
    void YamatoAttack();
    void RyuujouAttack();
    void AkagiAttack();
    void TaihoAttack();
    void I168Attack();
    void ShowTime();
    void ShowMana();
private:
    int totaltime = 200;
    int initialmana = 10;
};

#endif // MAINSCENE_H
