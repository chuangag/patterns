#ifndef _FAST_H
#define _FAST_H
#include "Point.h"
#include <iostream>
#include <vector>
using namespace std;

bool compAngle(const Point &a,const Point &b){
    return (a<b);}

class Fast{
private:
    vector<Point> points;//vector of points
    vector<Line> lines;//vector of lines
    int numOfPoints;
public:
    //constructor and destructor
    Fast():numOfPoints(0){points.resize(64);lines.resize(64);}
    Fast(vector<Point> pts,int n):numOfPoints(n){points=pts;lines.resize(64);}
    ~Fast(){}
    
    //Fast algorithm
    void FastAlgo();
    
    //print fuction
    void printFast(vector<Point> pointsToPrint);
};
void Fast::FastAlgo(){
    vector<vector<Point> > seriesOfPointsToPrint(100);
    //vector<vector<Point>> seriesOfPointsToPrint(100);
    for(int i=0;i<numOfPoints;i++){
        //TODO：=====================================
        
        //set the origin to points.at(i)
        points.at(i).setOrigin(points.at(i).getX(),points.at(i).getY());
        //sort the other points by angle start from i+1
        sort(points.begin(),points.end(),compAngle);
        //create a vector of vector<point> points to print, ie: few lines to print
        //vector<vector<Point>> seriesOfPointsToPrint(20);
        for(int j=0;j<points.size();j++){
            if(points.at(i).getX()==points.at(j).getX()&&points.at(i).getY()==points.at(j).getY()){}
            else if(j>0&&points.at(j)==points.at(j-1)){
                seriesOfPointsToPrint.end()->push_back(points.at(j));
            }
            //????????????check brackets!!!!!!!!!!!!!
            else if( (j ==0 ||(points.at(j)!=points.at(j-1)))&& ((points.at(j)!=points.at(j+1)) && (j<points.size()-1))){
                vector<Point> PointsToPrint(10);
                seriesOfPointsToPrint.push_back(PointsToPrint);
                seriesOfPointsToPrint.end()->push_back(points.at(i));
                seriesOfPointsToPrint.end()->push_back(points.at(j));
            }
                    //create new Points to print
                
            
        }
        
        //going over the sorted points and add point with same angle into points to print, only check series with more than 1 elements
        
        //check if points to print fit any line in vector<>lines,if not then print and save it to the vector<>lines
        for(int i;i<seriesOfPointsToPrint.size();i++){
            Point a=Point::Point(seriesOfPointsToPrint.at(i).at(0).getX(),seriesOfPointsToPrint.at(i).at(0).getY());
            Point b=Point::Point(seriesOfPointsToPrint.at(i).at(1).getX(),seriesOfPointsToPrint.at(i).at(1).getY());
            for(int l=0;l<lines.size();l++){
                if((!lines.at(l).checkIsOnline(a))&&(!lines.at(l).checkIsOnline(b))){
                    int x1=a.getX();
                    int x2=b.getX();
                    int y1=a.getY();
                    int y2=b.getY();
                    Line newline=Line::Line(y1-y2,x2-x1,y1*x1-y1*x2+x1*y2-x1*y1);
                    lines.push_back(newline);
                    printFast(seriesOfPointsToPrint.at(i));
                }
            }
        }
        //note that points[i]should be included
        /*
         for two points (x1,y1) (y1,y2)
         we have 
         a=y1-y2
         b=x2-x1
         c=y1x1-y1x2+x1y2-x1y1
         */
    }
}

void Fast::printFast(vector<Point> pointsToPrint){
    cout<<pointsToPrint.size()<<":";
    for(int i=0;i<pointsToPrint.size();i++){
        cout<<"("<<pointsToPrint[i].getX()<<", "<<pointsToPrint[i].getY()<<")";
        if(i!=3)//not last point
            cout<<" -> ";
        else
            cout<<endl;
    }
}


#endif
