#ifndef RYUUJOU_H
#define RYUUJOU_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Ryuujou : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Ryuujou();
    int count = 0;
    int health = 25;
    int attack = 50;
    int attack_range = 200;
    float x = -80;
    QProgressBar *hpbar;

private:
    int move = 100;
    int group = 1;
    int y = rand() % 541;

public slots:
    void ChangePic();
    void Move();
};

#endif // RYUUJOU_H
