#ifndef RIGHT_BTN_H
#define RIGHT_BTN_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneHoverEvent>
#include <QWidget>
#include <QGraphicsColorizeEffect>

class Right_btn : public QGraphicsPixmapItem
{
public:
    Right_btn();
    void hoverEnterEvent(QGraphicsSceneHoverEvent *hover);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *hover);
    QGraphicsColorizeEffect *eff;
};

#endif // RIGHT_BTN_H
