 #include "Brute.h"
#include "Fast.h"
#include "Point.h"
#include <vector>
#include <iostream>//perror
#include <stdlib.h>//exit 
using namespace std;
int main(){
      int numOfPoint;
      vector<Point> pts;
      cin>>numOfPoint;
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
      
      Fast fast=Fast(pts,numOfPoint);
      fast.FastAlgo();
      return 0;
}
