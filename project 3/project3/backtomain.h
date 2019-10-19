#ifndef BACKTOMAIN_H
#define BACKTOMAIN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Backtomain : public QGraphicsPixmapItem
{
    public:
        Backtomain();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // BACKTOMAIN_H
