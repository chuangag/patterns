#ifndef _FAST_H
#define _FAST_H
#include "Point.h"
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

//sorting points by x coordinates
bool compXcord2(const Point &a,const Point &b){
    return a.getX()<b.getX();}


bool compAngle(const Point &a,const Point &b){
    return (a<b);}

class Fast{
private:
    vector<Point> points;//vector of points
    vector<Line> lines;//vector of lines
    
    int numOfPoints;
public:
    //constructor and destructor
    Fast():numOfPoints(0){points.resize(0);lines.resize(0);}
    Fast(vector<Point> pts,int n):numOfPoints(n){points=pts;lines.resize(0);}
    ~Fast(){}
    
    //Fast algorithm
    void FastAlgo();
    
    //print fuction
    void printFast(vector<Point> pointsToPrint);
};
void Fast::FastAlgo(){
    vector<vector<Point> > seriesOfPointsToPrint(0);
    
    
    vector<vector<Point> > linesPrinted(0);
    //create a copy of original points for iterating
    vector<Point> copypoints=points;
    
    for(int i=0;i<numOfPoints;i++){
    
        //set the origin to points.at(i)
        copypoints.at(i).setOrigin(copypoints.at(i).getX(),copypoints.at(i).getY());
        //sort the other points by angle start from i+1
        sort(points.begin(),points.end(),compAngle);
        //create a vector of vector<point> points to print, ie: few lines to print
	
        // cout<<"origin====================== "<<Point::origin.getX()<<","<<Point::origin.getY()<<endl;
        bool firstLineCreated=false;
        
        for(int j=0;j<points.size();j++){
            if(copypoints.at(i).getX()==points.at(j).getX()&&copypoints.at(i).getY()==points.at(j).getY()){
                //do nothing
            }
            else if(j>0&&(points.at(j)==points.at(j-1))&&firstLineCreated){
                seriesOfPointsToPrint.back().push_back(points.at(j));
            }
            else if( (j ==0 ||points.at(j)!=points.at(j-1) )&& ( j<points.size()-1 && points.at(j)==points.at(j+1) )){
                vector<Point> PointsToPrint(0);
                firstLineCreated=true;
                seriesOfPointsToPrint.push_back(PointsToPrint);
                seriesOfPointsToPrint.back().push_back(points.at(j));
                seriesOfPointsToPrint.back().push_back(copypoints.at(i));
            }
        }
        
        //going over the sorted points and add point with same angle into points to print, only check series with more than 1 elements
       
        //check if points to print fit any line in vector<>lines,if not then print and save it to the vector<>lines
        //cout<<"seriesOfPointsToPrint.size(): "<<seriesOfPointsToPrint.size()<<endl;
        /*for(int r=0;r<seriesOfPointsToPrint.size();r++){
            
            
            Point a=Point(seriesOfPointsToPrint.at(r).at(0).getX(),seriesOfPointsToPrint.at(r).at(0).getY());
            Point b=Point(seriesOfPointsToPrint.at(r).at(1).getX(),seriesOfPointsToPrint.at(r).at(1).getY());
            if(lines.empty()){
                int x1=a.getX();
                int x2=b.getX();
                int y1=a.getY();
                int y2=b.getY();
                Line newline=Line(y1-y2,x2-x1,y1*x1-y1*x2+x1*y2-x1*y1);
                lines.push_back(newline);
                sort(seriesOfPointsToPrint.at(r).begin(),seriesOfPointsToPrint.at(r).end(),compXcord2);
                printFast(seriesOfPointsToPrint.at(r));
                //cout<<"create first line"<<endl;
            }
            cout<<"linesize: "<<lines.size()<<endl;
            for(int l=0;l<lines.size();l++){
                
                if((lines.at(l).isNotOnline(a))&&(lines.at(l).isNotOnline(b))){
                    cout<<"yessss"<<endl;
                    int x1=a.getX();
                    int x2=b.getX();
                    int y1=a.getY();
                    int y2=b.getY();
                    Line newline=Line(y1-y2,x2-x1,y1*x1-y1*x2+x1*y2-x1*y1);
                    //cout<<"new line:"<<y1-y2<<", "<<x2-x1<<", "<<y1*x1-y1*x2+x1*y2-x1*y1<<endl;
                    lines.push_back(newline);
                    sort(seriesOfPointsToPrint.at(r).begin(),seriesOfPointsToPrint.at(r).end(),compXcord2);
                    //printFast(seriesOfPointsToPrint.at(r));
                }
            }
        }*/
        //note that points[i]should be included
        /*
         for two points (x1,y1) (y1,y2)
         we have 
         a=y1-y2
         b=x2-x1
         c=y1x1-y1x2+x1y2-x1y1
         */
        //seriesOfPointsToPrint.clear();
    }
    for(int r=0;r<seriesOfPointsToPrint.size();r++){
        bool repeated=false;
        if(seriesOfPointsToPrint.at(r).size()>3){
            sort(seriesOfPointsToPrint.at(r).begin(),seriesOfPointsToPrint.at(r).end(),compXcord2);
            
            if(linesPrinted.empty()){
                //printFast(seriesOfPointsToPrint.at(r));
                linesPrinted.push_back(seriesOfPointsToPrint.at(r));
            }
            else{
                for(int l=0;l<linesPrinted.size();l++){
                    if((linesPrinted.at(l)==seriesOfPointsToPrint.at(r))){
                        repeated=true;
                        break;
                    }
                }
            }
            if(repeated==false){
                printFast(seriesOfPointsToPrint.at(r));
                linesPrinted.push_back(seriesOfPointsToPrint.at(r));
            }
        }
        /*
        Point a=Point(seriesOfPointsToPrint.at(r).at(0).getX(),seriesOfPointsToPrint.at(r).at(0).getY());
        Point b=Point(seriesOfPointsToPrint.at(r).at(1).getX(),seriesOfPointsToPrint.at(r).at(1).getY());
        if(lines.empty()){
            int x1=a.getX();
            int x2=b.getX();
            int y1=a.getY();
            int y2=b.getY();
            Line newline=Line(y1-y2,x2-x1,y1*x1-y1*x2+x1*y2-x1*y1);
            lines.push_back(newline);
            sort(seriesOfPointsToPrint.at(r).begin(),seriesOfPointsToPrint.at(r).end(),compXcord2);
            printFast(seriesOfPointsToPrint.at(r));
            //cout<<"create first line"<<endl;
        }
        cout<<"linesize: "<<lines.size()<<endl;
        for(int l=0;l<lines.size();l++){
            
            if((lines.at(l).isNotOnline(a))&&(lines.at(l).isNotOnline(b))){
                int x1=a.getX();
                int x2=b.getX();
                int y1=a.getY();
                int y2=b.getY();
                Line newline=Line(y1-y2,x2-x1,y1*x1-y1*x2+x1*y2-x1*y1);
                //cout<<"new line:"<<y1-y2<<", "<<x2-x1<<", "<<y1*x1-y1*x2+x1*y2-x1*y1<<endl;
                lines.push_back(newline);
                sort(seriesOfPointsToPrint.at(r).begin(),seriesOfPointsToPrint.at(r).end(),compXcord2);
                //printFast(seriesOfPointsToPrint.at(r));
            }
        }*/
    }
}

void Fast::printFast(vector<Point> pointsToPrint){
    cout<<pointsToPrint.size()<<":";
    for(int i=0;i<pointsToPrint.size();i++){
        cout<<"("<<pointsToPrint[i].getX()<<", "<<pointsToPrint[i].getY()<<")";
        if(i!=pointsToPrint.size()-1)//not last point
            cout<<" -> ";
        else
            cout<<endl;
    }
}


#endif
