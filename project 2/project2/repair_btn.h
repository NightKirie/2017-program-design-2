#ifndef REPAIR_BTN_H
#define REPAIR_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Repair_btn : public QGraphicsPixmapItem
{
    public:
        Repair_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // REPAIR_BTN_H
