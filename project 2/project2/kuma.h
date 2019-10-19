#ifndef KUMA_H
#define KUMA_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Kuma : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Kuma();
    int count = 0;
    int health = 40;
    int attack = 8;
    int attack_range = 70;
    float x = -80;
    QProgressBar *hpbar;

private:
    int move = 120;
    int group = 1;
    int y = rand() % 541;

public slots:
    void ChangePic();
    void Move();
};

#endif // KUMA_H
