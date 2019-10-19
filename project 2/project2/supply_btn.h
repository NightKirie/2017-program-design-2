#ifndef SUPPLY_BTN_H
#define SUPPLY_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Supply_btn : public QGraphicsPixmapItem
{
    public:
        Supply_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // SUPPLY_BTN_H
