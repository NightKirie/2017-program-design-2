#ifndef SMALLSUPPLY_BTN_H
#define SMALLSUPPLY_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>


class Smallsupply_btn : public QGraphicsPixmapItem
{
public:
    Smallsupply_btn();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // SMALLSUPPLY_BTN_H
