#ifndef FURUTAKA_H
#define FURUTAKA_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Furutaka : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Furutaka();
    int count = 0;
    int health = 50;
    float x = -80;
    int attack = 15;
    int attack_range = 120;
    QProgressBar *hpbar;

private:
    float move = 100;
    int group = 1;
    int y = rand() % 541;

public slots:
    void ChangePic();
    void Move();
};
#endif // FURUTAKA_H
