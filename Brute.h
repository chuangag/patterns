#ifndef _BRUTE_H
#define _BRUTE_H
#include "Point.h"
#include <iostream>
using namespace std;

class Brute{
private:
  Point::Point* points;//array of points
  int numOfPoints;
public:
  //constructor and destructor
  Brute():points(NULL),numOfPoints(0){}
  Brute(Point::Point* pts,int n):points(pts),numOfPoints(n){}
  ~Brute(){}
  
  //brute force calculation
  void BruteForce();
  
  //print fuction
  void PrintBruteResult(Point::Point* pointsToPrint);
    
};

void Brute::BruteForce(){
  if(!points[3])//return if input points less than 4
    return;
  
  for(int a=0;a<n;a++){
    for(int b=a+1;b<n;b++){
      for(int c=b+1;c<n;c++){
	for(int d=c+1;d<n;d++){
	  //if all slope==infinite(x==0)
	  if(points[a].getX()==points[b].getX()&&points[b].getX()==points[c].getX()&&points[c].getX()==points[d].getX()){
	    Point::Point* PointsToPrint;
	    PointsToPrint[0]=points[a];PointsToPrint[1]=points[b];PointsToPrint[2]=points[c];PointsToPrint[3]=points[d];
	    PrintBruteResult(PointsToPrint);
	  }
	  //if same y
	  else if(points[a].getY()==points[b].getY()&&points[b].getY()==points[c].getY()&&points[c].getY()==points[d].getY()){
	    Point::Point* PointsToPrint;
	    PointsToPrint[0]=points[a];PointsToPrint[1]=points[b];PointsToPrint[2]=points[c];PointsToPrint[3]=points[d];
	    PrintBruteResult(PointsToPrint);
	  }
	  //same slope relate to a
	  else{
	    float slope[3];//slopes between ab, ac, ad
	    slope[0]=(points[b].getY()-points[a].getY())/(points[b].getX()-points[a].getX());
	    slope[1]=(points[c].getY()-points[a].getY())/(points[c].getX()-points[a].getX());
	    slope[2]=(points[d].getY()-points[a].getY())/(points[d].getX()-points[a].getX());
	    //if same slopes=>form a line
	    if(slope[0]==slope[1]&&slope[1]==slope[2]){
	      Point::Point* PointsToPrint;
	      PointsToPrint[0]=points[a];PointsToPrint[1]=points[b];PointsToPrint[2]=points[c];PointsToPrint[3]=points[d];
	      PrintBruteResult(PointsToPrint);
	    }
	      
	  } 
	}
      }
    }
  }
}

void Brute::PrintBruteResult(Point* pointsToPrint){
  cout<<"4:";
  for(int i=0;i<4;i++){
    cout<<"("<<pointsToPrint[i].x<<", "<<pointsToPrint[i].y<<")";
    if(i!=3)//not last point
      cout<<" -> "
    else
      cout<<endl;
  }
}

#endif
