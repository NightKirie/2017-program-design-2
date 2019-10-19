#ifndef CONFIRMUSERNAME_H
#define CONFIRMUSERNAME_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>
#include <QGraphicsColorizeEffect>

class Confirmusername : public QGraphicsPixmapItem
{
public:
    Confirmusername();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
    QGraphicsColorizeEffect *eff;
};

#endif // CONFIRMUSERNAME_H
