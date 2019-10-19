#ifndef CHANGE_BTN_H
#define CHANGE_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Change_btn : public QGraphicsPixmapItem
{
    public:
        Change_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // CHANGE_BTN_H
