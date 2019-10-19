#ifndef SMALLREPAIR_BTN_H
#define SMALLREPAIR_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>


class Smallrepair_btn : public QGraphicsPixmapItem
{
public:
    Smallrepair_btn();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // SMALLREPAIR_BTN_H
