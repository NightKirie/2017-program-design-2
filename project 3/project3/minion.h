#ifndef MINION_H
#define MINION_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <iostream>
using namespace std;

class Minion :  public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Minion(int health, int attack, int move, int attack_range, int group);
    friend class Fubuki;
private:
    int health;
    int attack;
    int move;
    int attack_range;
    int group;
};

#endif // MINION_H
