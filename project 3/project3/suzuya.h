#ifndef SUZUYA_H
#define SUZUYA_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Suzuya : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Suzuya();
    int count = 0;
    int health = 60;
    int attack = 15;
    int attack_range = 120;
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

#endif // SUZUYA_H
