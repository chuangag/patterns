#ifndef _FAST_H
#define _FAST_H
#include "Point.h"
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


class Fast{
private:
    vector<Point> points;//vector of points
    vector<Line> lines;//vector of lines
    
    
    int numOfPoints;
public:
    //constructor and destructor
    Fast():numOfPoints(0){points.resize(0);lines.resize(0);pointsToDraw.resize(0);}
    Fast(vector<Point> pts,int n):numOfPoints(n){points=pts;lines.resize(0);pointsToDraw.resize(0);}
    ~Fast(){}
    
    //Fast algorithm
    void FastAlgo();
    
    //print fuction
    void printFast(vector<Point> pointsToPrint);
    
    
    vector<vector<Point> > pointsToDraw;
};


#endif
