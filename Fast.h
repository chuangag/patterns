#ifndef _FAST_H
#define _FAST_H
#include "Point.h"
#include <iostream>
#include <vector>
#include <algorithm> 
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
    Fast():numOfPoints(0){points.resize(0);lines.resize(1);}
    Fast(vector<Point> pts,int n):numOfPoints(n){points=pts;lines.resize(1);}
    ~Fast(){}
    
    //Fast algorithm
    void FastAlgo();
    
    //print fuction
    void printFast(vector<Point> pointsToPrint);
};
void Fast::FastAlgo(){
    vector<vector<Point> > seriesOfPointsToPrint(0);
    //create a copy of original points for iterating
    vector<Point> copypoints=points;
    
    for(int i=0;i<numOfPoints;i++){
      /*test
	   
	   
	   
	  cout<<"origin= "<<Point::origin.getX()<<","<<Point::origin.getY()<<endl;
	  
	  cout<<"point= "<<points[i].getX()<<","<<points[i].getY()<<" amgle: "<<points[i].getAngle(points[i])<<endl;
	  
	   
	   
	   */
      
      
        //TODO：=====================================
        
        //set the origin to points.at(i)
        copypoints.at(i).setOrigin(copypoints.at(i).getX(),copypoints.at(i).getY());
        //sort the other points by angle start from i+1
        sort(points.begin(),points.end(),compAngle);
        //create a vector of vector<point> points to print, ie: few lines to print
        //vector<vector<Point>> seriesOfPointsToPrint(20);
	
	
	cout<<"origin====================== "<<Point::origin.getX()<<","<<Point::origin.getY()<<endl;
	/*
	cout<<"-----------------print Sort---------"<<endl;
	for(int r=0;r<points.size();r++){
	   cout<<"point= "<<points[r].getX()<<","<<points[r].getY()<<" angle: "<<points[r].getAngle()<<endl;
	}*/
	
	bool firstLineCreated=false;
// 	bool samePointIsTheFirst=false;
	
	
        for(int j=0;j<points.size();j++){
	  /*test
	   
	   
	   
	  cout<<"size: "<<points.size()<<" j:"<<j<<endl;
	  cout<<"point= "<<points[j].getX()<<","<<points[j].getY()<<" angle: "<<points[j].getAngle()<<endl;
	  
	   */
	   
	   
	  
            if(copypoints.at(i).getX()==points.at(j).getX()&&copypoints.at(i).getY()==points.at(j).getY()){
	      /*if(!firstLineCreated){
		vector<Point> PointsToPrint(10);
		cout<<"new self line created!"<<endl;
                seriesOfPointsToPrint.push_back(PointsToPrint);
		seriesOfPointsToPrint.end()->push_back(copypoints.at(i));
		firstLineCreated=true;
		samePointIsTheFirst=true;
	      }*/
	    }
            else if(j>0&&points.at(j)==points.at(j-1)&&firstLineCreated){
                seriesOfPointsToPrint.back().push_back(points.at(j));
		//cout<<"new element pushed!"<<endl;
            }
            //????????????check brackets!!!!!!!!!!!!!
            else if( (j ==0 ||points.at(j)!=points.at(j-1))&& (j<points.size()-1&&points.at(j)==points.at(j+1))){
                vector<Point> PointsToPrint(0);
		//cout<<"new line created!"<<endl;
		firstLineCreated=true;
                seriesOfPointsToPrint.push_back(PointsToPrint);
                
                seriesOfPointsToPrint.back().push_back(points.at(j));
		seriesOfPointsToPrint.back().push_back(copypoints.at(i));
            }
                    //create new Points to print
            
            
        }
        
        //going over the sorted points and add point with same angle into points to print, only check series with more than 1 elements
       
        //check if points to print fit any line in vector<>lines,if not then print and save it to the vector<>lines
        for(int r=0;r<seriesOfPointsToPrint.size();r++){
	   
            Point a=Point(seriesOfPointsToPrint.at(r).at(0).getX(),seriesOfPointsToPrint.at(r).at(0).getY());
            Point b=Point(seriesOfPointsToPrint.at(r).at(1).getX(),seriesOfPointsToPrint.at(r).at(1).getY());
            cout<<lines.size()<<endl;
	    for(int l=0;l<lines.size();l++){
	    
                if((!lines.at(l).checkIsOnline(a))&&(!lines.at(l).checkIsOnline(b))){
                    int x1=a.getX();
                    int x2=b.getX();
                    int y1=a.getY();
                    int y2=b.getY();
                    Line newline=Line(y1-y2,x2-x1,y1*x1-y1*x2+x1*y2-x1*y1);
                    lines.push_back(newline);
                    printFast(seriesOfPointsToPrint.at(r));
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
        if(i!=pointsToPrint.size()-1)//not last point
            cout<<" -> ";
        else
            cout<<endl;
    }
}


#endif
