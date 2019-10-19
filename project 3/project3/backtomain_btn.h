#ifndef BACKTOMAIN_BTN_H
#define BACKTOMAIN_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Backtomain_btn : public QGraphicsPixmapItem
{
    public:
        Backtomain_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // BACKTOMAIN_BTN_H
