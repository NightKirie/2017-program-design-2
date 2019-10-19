#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mainscene = new Mainscene();
    ui->label->setGeometry(0,0,1200,720);
    mainscene->setSceneRect(0,0,1200,720);  //initialize the pos
    ui->graphicsView->setStyleSheet("background: transparent");
    ui->graphicsView->setScene(mainscene);
    ui->graphicsView->setGeometry(0,0,1200,720);    //set the background pos
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //set the annoy scrollbar off
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   //set the annoy scrollbar off
    SetStartScreen();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetStartScreen(){
    mainscene->InitThings();
    ui->label->setMovie(mainscene->movie);
    ui->label->show();
    ui->graphicsView->show();
}

