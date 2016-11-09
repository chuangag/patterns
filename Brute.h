#ifndef _BRUTE_H
#define _BRUTE_H
#include "Point.h"
#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;




class Brute{
private:
  vector<Point> points;//vector of points
  int numOfPoints;
public:
  //constructor and destructor
    Brute():numOfPoints(0){points.resize(0);pointsToDraw.resize(0);}
    Brute(vector<Point> pts,int n):numOfPoints(n){points=pts;}
  ~Brute(){}
  
  //brute force calculation
  void BruteForce();
  
  //print fuction
  void PrintBruteResult(vector<Point> pointsToPrint);
  vector<vector<Point> > pointsToDraw;
};
#endif
