 
#include <QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QAction>
#include <QMenuBar>
#include "Brute.h"
#include "Fast.h"
#include "Point.h"
#include <iostream>//perror
#include <stdlib.h>//exit 
 
 
#ifndef POINTPLOTTER_H
#define POINTPLOTTER_H



using namespace std;
class QAction;
class QLabel;
class QMenu;

class patternsMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    patternsMainWindow();
    void loadFile();
//      void paintPoints(QPainter p);
    void paintEvent(QPaintEvent *);
private slots:
    void loadBrute();
    void loadFast();
    
//     void about();

private:
    
    QMenu *fileMenu;
//     QMenu *aboutMenu;
    QAction *ActBrute;
    QAction *ActFast;
//     QAction *ActAbout;
//     QLabel *aboutLabel;
    QPainter *paintBoard;
    
    int numOfPoint;
    vector<Point> pts;
    
};






//////////////////////////////////////////////////////////////////////
/*
class :public QWidget{
  Q_OBJECT
  
public:
  
};*/


#endif