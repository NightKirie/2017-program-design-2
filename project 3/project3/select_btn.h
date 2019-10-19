#ifndef SELECT_BTN_H
#define SELECT_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>
#include <QGraphicsColorizeEffect>

class Select_btn : public QGraphicsPixmapItem
{
    public:
        Select_btn();
        void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
        QGraphicsColorizeEffect *eff;
};

#endif // SELECT_BTN_H
