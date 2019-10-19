#ifndef CARDSETTING_H
#define CARDSETTING_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QWidget>


class Cardsetting : public QObject
{
    Q_OBJECT  

    public:
        Cardsetting(int x);
        int ID;
        int ori_hp; //for settlement
        int cur_hp; //current hp
        int shell;
        int attack;
        int torpedo;
        int air_atk;
        int sub_atk;
        int double_atk;     //0~100
        bool air_strike;
        bool sub_strike;
        bool tor_strike;
        bool double_strike;
        QGraphicsPixmapItem *previewpic;
        QGraphicsPixmapItem *grouppic;
        QGraphicsPixmapItem *battlepic;                       
};

#endif // CARDSETTING_H
