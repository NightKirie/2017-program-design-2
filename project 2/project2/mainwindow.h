#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QGraphicsPixmapItem>
#include <QLabel>
#include "mainscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Mainscene *mainscene;
    void SetStartScreen();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
