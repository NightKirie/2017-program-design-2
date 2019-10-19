#ifndef LEFT_BTN_H
#define LEFT_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>
#include <QGraphicsColorizeEffect>

class Left_btn : public QGraphicsPixmapItem
{
public:
    Left_btn();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
    QGraphicsColorizeEffect *eff;
};

#endif // LEFT_BTN_H
