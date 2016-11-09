#include "PointPlotter.h" 
#include <QCoreApplication>
#include <QFile>
#include <QtDebug>
#include <QTextStream>
#include <QPainter>
#include <ctime>
using namespace std;
patternsMainWindow::patternsMainWindow(){
  resize(500,500);
  move(200,200);
  numOfPoint=0;
  pts.resize(0);
  linesToDraw.resize(0);
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
  haslines=false;
}

void patternsMainWindow::loadBrute(){
//     cout<<endl<<endl<<endl<<endl<<"---------------Brute------------"<<endl<<endl<<endl<<endl;
  clock_t s,e;  
  s=clock();
    Brute brute=Brute(pts,numOfPoint);
    brute.BruteForce();
    e=clock();
    linesToDraw=brute.pointsToDraw;
    haslines=true;
    update();
    cout<<(double(e - s)/CLOCKS_PER_SEC)<<" sec"<<endl;
}

void patternsMainWindow::loadFast(){
//     cout<<endl<<endl<<endl<<endl<<"---------------Fast------------"<<endl<<endl<<endl<<endl;
    clock_t s,e;
    s=clock();
    Fast fast=Fast(pts,numOfPoint);
    fast.FastAlgo();
    e=clock();
    linesToDraw=fast.pointsToDraw;
    haslines=true;
    update();
    cout<<(double(e - s)/CLOCKS_PER_SEC)<<" sec"<<endl;
    
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


void patternsMainWindow::paintEvent(QPaintEvent * event){

  QMainWindow::paintEvent(event);
  QPainter p(this);
  p.setPen(QColor(Qt::blue));
  
  p.fillRect(0,0,this->width(),this->height(),QColor(Qt::white));
  for(int i=0;i<pts.size();i++){
    p.drawEllipse((double)((double)pts.at(i).getX()/32767*(this->width()))-2.5,(double)(this->height()-(double)pts.at(i).getY()/32767*(this->height()))-2.5,5,5);
  }
  
  if(haslines){
    for(int l=0;l<linesToDraw.size();l++){
      for(int i=0;i<linesToDraw.at(l).size()-1;i++){
	
	p.setPen(QColor(Qt::red));
	p.drawLine((double)((double)linesToDraw.at(l).at(i).getX()/32767*(this->width())),(double)(this->height()-(double)linesToDraw.at(l).at(i).getY()/32767*(this->height())),(double)((double)linesToDraw.at(l).at(i+1).getX()/32767*(this->width())),(double)(this->height()-(double)linesToDraw.at(l).at(i+1).getY()/32767*(this->height())));
      }
    }
    
  }
     
}