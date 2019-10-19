#ifndef I168_H
#define I168_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class I168 : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    I168();
    int count = 0;
    int health = 15;
    int attack = 30;
    int attack_range = 75;
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


#endif // I168_H
