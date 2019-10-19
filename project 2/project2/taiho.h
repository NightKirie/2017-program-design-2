#ifndef TAIHO_H
#define TAIHO_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Taiho : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Taiho();
    int count = 0;
    int health = 40;
    int attack = 60;
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

#endif // TAIHO_H
