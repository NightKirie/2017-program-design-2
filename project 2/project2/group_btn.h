#ifndef GROUP_BTN_H
#define GROUP_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Group_btn : public QGraphicsPixmapItem
{
    public:
        Group_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // GROUP_BTN_H
