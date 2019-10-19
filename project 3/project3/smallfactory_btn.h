#ifndef SMALLFACTORY_BTN_H
#define SMALLFACTORY_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>

class Smallfactory_btn : public QGraphicsPixmapItem
{
public:
    Smallfactory_btn();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
};

#endif // SMALLFACTORY_BTN_H
