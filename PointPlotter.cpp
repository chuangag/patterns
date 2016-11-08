#include "Brute.h"
#include "Fast.h"
#include "Point.h"
#include <fstream>
#include <iostream>//perror
#include <stdlib.h>//exit
#include <qapplication.h>
#include "mainWindow.h"
using namespace std;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QWidget* w = new MainWindow();
    a.setMainWidget(w);
    w->show();
    return a.exec();
};



int main(int argc, char *argv[]){
  
  
    int numOfPoint;
    cin>>numOfPoint;  
  
    vector<Point> pts;
    pts.resize(numOfPoint);
    int i=0;
    while (i<numOfPoint){
        Point p=Point();
        int x,y;
        cin>>x;cin>>y;
        p.setX(x);p.setY(y);
        pts.at(i)=p;
        i++;
    }
    cout<<endl<<endl<<endl<<endl<<"---------------Fast------------"<<endl<<endl<<endl<<endl;
    Fast fast=Fast(pts,numOfPoint);
    fast.FastAlgo();

    cout<<endl<<endl<<endl<<endl<<"---------------Brute------------"<<endl<<endl<<endl<<endl;
    Brute brute=Brute(pts,numOfPoint);
    brute.BruteForce();
    
    cout<<"Finish"<<endl;
    
    return 0;
}

