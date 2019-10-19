#ifndef BOSS_H
#define BOSS_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Boss : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Boss();
    int health = 10000;
    int attack = 35;
    QProgressBar *hpbar;

private:
    int attack_range = 600;
    int group = 2;
    int x = 820;
    int y = 210;

public slots:
    void sethpbar();
};

#endif // BOSS_H
