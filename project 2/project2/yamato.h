#ifndef YAMATO_H
#define YAMATO_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Yamato : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Yamato();
    int count = 0;
    int health = 100;
    int attack = 100;
    int attack_range = 250;
    float x = -80;
    QProgressBar *hpbar;

private:
    int move = 80;
    int group = 1;
    int y = rand() % 541;

public slots:
    void ChangePic();
    void Move();
};

#endif // YAMATO_H
