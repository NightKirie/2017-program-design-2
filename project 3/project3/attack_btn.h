#ifndef ATTACK_BTN_H
#define ATTACK_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Attack_btn : public QGraphicsPixmapItem
{
    public:
        Attack_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // ATTACK_BTN_H
