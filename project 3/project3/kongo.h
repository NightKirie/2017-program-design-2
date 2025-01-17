#ifndef KONGO_H
#define KONGO_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Kongo : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Kongo();
    int count = 0;
    int health = 80;
    int attack = 30;
    int attack_range = 200;
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

#endif // KONGO_H
