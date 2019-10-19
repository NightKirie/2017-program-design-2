#ifndef FUSOU_H
#define FUSOU_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Fusou : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Fusou();
    int count = 0;
    int health = 75;
    int attack = 25;
    int attack_range = 180;
    float x = -80;
    QProgressBar *hpbar;

private:
    int move = 50;
    int group = 1;
    int y = rand() % 541;


public slots:
    void ChangePic();
    void Move();
};

#endif // FUSOU_H
