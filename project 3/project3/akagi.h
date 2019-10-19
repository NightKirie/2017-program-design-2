#ifndef AKAGI_H
#define AKAGI_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Akagi : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Akagi();
    int count = 0;
    int health = 60;
    float x = -80;
    int attack_range = 200;
    int attack = 65;
    QProgressBar *hpbar;

private:
    float move = 100;
    int group = 1;
    int y = rand() % 541;

public slots:
    void ChangePic();
    void Move();
};

#endif // AKAGI_H
