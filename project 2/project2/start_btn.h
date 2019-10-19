#ifndef START_BTN_H
#define START_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Start_btn : public QGraphicsPixmapItem
{
    public:
        Start_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // START_BTN_H
