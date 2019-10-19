#ifndef FUBUKI_H
#define FUBUKI_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Fubuki : public QObject, public QGraphicsPixmapItem {
    Q_OBJECT

public:
    Fubuki();
    int count =0;
    int health = 30;
    float x = -80;
    int attack_range = 50;
    int attack = 5;
    QProgressBar *hpbar;

private:
    float move = 150;
    int group = 1;
    int y = rand() % 541;

public slots:
    void ChangePic();
    void Move();
};

#endif // FUBUKI_H
