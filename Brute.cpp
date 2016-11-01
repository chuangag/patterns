#include "Brute.h"
#include "Point.h"
#include <fstream>
#include <iostream>//perror
#include <stdlib.h>//exit
#include <assert.h>

using namespace std;

int getInput (ifstream &fin, Point::Point p)
{
    fin >>p.x;    
    fin >>p.y;
    
    if (fin.fail())         // fail to read a record return 0 for failure
        return 0;
    
    return (!fin.fail());    // return 1 for successful; 0 for failure  
}




int main(int argc, char *argv[]){
  if(argc<2){
    perror("please give the input file!");
    exit(0);
  }
  ifstream fin();                
  assert (fin.is_open ()); 
  
  int numOfPoint;
  fin>>numOfPoint;
  int i=0;
  
  Point::Point* pts;
  
  while (!fin.eof ()){
    Point::Point p;
    int val = getInput(fin,p);       
    if (val == 0)                            
      break;
    pts[i]=p;
    i++;
  }
  
  Brute::Brute brute(Point::Point p,numOfPoint);
  
  brute.BruteForce();
  fin.close ();
  return 0;
}



