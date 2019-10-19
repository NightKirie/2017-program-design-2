#ifndef SMALLCHANGE_BTN_H
#define SMALLCHANGE_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Smallchange_btn : public QGraphicsPixmapItem
{
public:
    Smallchange_btn();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // SMALLCHANGE_BTN_H
