#ifndef KITAKAMI_H
#define KITAKAMI_H
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QMainWindow>
#include <iostream>
#include <QObject>
#include <QProgressBar>
using namespace std;

class Kitakami : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    Kitakami();
    int count = 0;
    int health = 45;
    int attack = 10;
    int attack_range = 100;
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

#endif // KITAKAMI_H
