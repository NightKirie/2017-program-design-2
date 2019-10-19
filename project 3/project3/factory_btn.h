#ifndef FACTORY_BTN_H
#define FACTORY_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Factory_btn : public QGraphicsPixmapItem
{
    public:
        Factory_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // FACTORY_BTN_H
