#include "PointPlotter.h" 
#include <QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QTextStream>
#include <QMessageBox>
#include <QPainter>
using namespace std;
patternsMainWindow::patternsMainWindow(){
  resize(500,500);
  move(200,200);
  numOfPoint=0;
  pts.resize(0);
  
  setWindowTitle(tr("Patterns by chuangag"));
  ActBrute=new QAction(tr("Run Brute"),this);
  ActFast=new QAction(tr("Run Fast"),this);
//   ActAbout=new QAction(tr("About"),this);
  
  connect(ActBrute,SIGNAL(triggered()),this,SLOT(loadBrute()));
  connect(ActFast,SIGNAL(triggered()),this,SLOT(loadFast()));
//   connect(ActAbout,SIGNAL(triggered()),this,SLOT(about()));
  
  fileMenu = menuBar()->addMenu(tr("File"));
  fileMenu->addAction(ActBrute);
  fileMenu->addAction(ActFast);
    
//   aboutMenu = menuBar()->addMenu(tr("About"));
//   aboutMenu->addAction(about);
 
  
  loadFile();
}

void patternsMainWindow::loadBrute(){
//     cout<<endl<<endl<<endl<<endl<<"---------------Brute------------"<<endl<<endl<<endl<<endl;
    double startTime=(double)clock();
    Brute brute=Brute(pts,numOfPoint);
    brute.BruteForce();
    double endTime=(double)clock();
    QMessageBox::information(this,"Running time ",QString("%1 microsecond").arg(endTime-startTime));
}

void patternsMainWindow::loadFast(){
//     cout<<endl<<endl<<endl<<endl<<"---------------Fast------------"<<endl<<endl<<endl<<endl;
    double startTime=(double)clock();
    Fast fast=Fast(pts,numOfPoint);
    fast.FastAlgo();
    double endTime=(double)clock();
    
    /*Paint line Fail!!!!!!!!!!!!!*/
    for(int l=0;l<fast.pointsToDraw.size();l++){
      for(int i=0;i<fast.pointsToDraw.at(l).size()-1;i++){
	QPainter p(this);
	p.setPen(QColor(Qt::blue));
	p.drawLine((double)((double)fast.pointsToDraw.at(l).at(i).getX()/32767*(this->width())),(double)(this->height()-(double)fast.pointsToDraw.at(l).at(i).getY()/32767*(this->height())),(double)((double)fast.pointsToDraw.at(l).at(i+1).getX()/32767*(this->width())),(double)(this->height()-(double)fast.pointsToDraw.at(l).at(i+1).getY()/32767*(this->height())));
      }
    }
    
    QMessageBox::information(this,"Running time ",QString("%1 microsecond").arg(endTime-startTime));
}

void patternsMainWindow::loadFile(){
  QStringList arguments=QCoreApplication::arguments();
  QString filename=arguments.at(1);
  if(!filename.isNull()){
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
      QTextStream is(&file);
       is>>numOfPoint;
      pts.resize(numOfPoint);
      int i=0;
      while (i<numOfPoint){
        Point p=Point();
        int x,y;
        is>>x;is>>y;
        p.setX(x);p.setY(y);
        pts.at(i)=p;
        i++;
      }
    }
  }
}
/*
void patternsMainWindow::paintPoints(QPainter p){
  p.setPen(QColor(Qt::blue));
  for(int i=0;i<pts.size();i++){
     p.drawPoint(pts.at(i).getX(),pts.at(i).getY());
  }
}*/

void patternsMainWindow::paintEvent(QPaintEvent * event){
//    paintBoard=new QPainter();
  QMainWindow::paintEvent(event);
  QPainter p(this);
  p.setPen(QColor(Qt::blue));
  
  p.fillRect(0,0,this->width(),this->height(),QColor(Qt::white));
  for(int i=0;i<pts.size();i++){
    p.drawEllipse((double)((double)pts.at(i).getX()/32767*(this->width())),(double)(this->height()-(double)pts.at(i).getY()/32767*(this->height())),5,5);
  }
  
  //paintlines!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   
}