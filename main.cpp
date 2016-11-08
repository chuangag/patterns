#include "Brute.h"
#include "Fast.h"
#include "Point.h"
#include "PointPlotter.h"
#include <fstream>
#include <iostream>//perror
#include <stdlib.h>//exit
#include <QApplication>

using namespace std;
int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    /*
    
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
    }*/
    QMainWindow* w = new patternsMainWindow();
    w->show();
    /*
    cout<<endl<<endl<<endl<<endl<<"---------------Fast------------"<<endl<<endl<<endl<<endl;
    Fast fast=Fast(pts,numOfPoint);
    fast.FastAlgo();
*/
    /*
    cout<<endl<<endl<<endl<<endl<<"---------------Brute------------"<<endl<<endl<<endl<<endl;
    Brute brute=Brute(pts,numOfPoint);
    brute.BruteForce();
    */
    return a.exec();
};
