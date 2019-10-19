#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QIcon>


int main(int argc, char *argv[])
{
    QApplication pj2(argc, argv);
    MainWindow game;
    QDesktopWidget window;  //for setting the window in the middle of the screen
    game.setStyleSheet("MainWindow {background: 'black'}");     //set background color
    game.setGeometry(window.screen()->width() / 2 - 600, window.screen()->height() / 2 - 360, 1200, 720);
    game.setWindowTitle("艦これ（偽）");
    game.setWindowIcon(QIcon("../project2/images/windowicon.jpg"));
    game.show();
    return pj2.exec();
}
