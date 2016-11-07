#include "Brute.h"
#include "Fast.h"
#include "Point.h"
#include <fstream>
#include <iostream>//perror
#include <stdlib.h>//exit
#include <assert.h>

using namespace std;
/*
int getInput (ifstream &fin, Point::Point p)
{
    int x,y;
    fin >>x;
    fin >>y;
    p.setX(x);p.setY(y);
    
    if (fin.fail())         // fail to read a record return 0 for failure
        return 0;
    
    return (!fin.fail());    // return 1 for successful; 0 for failure  
}*/




int main(int argc, char *argv[]){
  /*if(argc<2){
    perror("please give the input file!");
    exit(0);
  }*/
    //const char *MARK_FILE  = "input6.txt";
/*ifstream fin;
    fin.open("input6.txt");
    if (! fin.is_open())
    { cout << "Error opening file"<<endl; exit(1); }*/
  
  int numOfPoint;
  cin>>numOfPoint;
    //cout<<numOfPoint<<endl;
    
  
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
 
   /* Brute brute=Brute(pts,numOfPoint);
  brute.BruteForce();//problems HERE!!!!!!!!
  */
    Fast fast=Fast(pts,numOfPoint);
    fast.FastAlgo();
  //fin.close ();
  return 0;
}



