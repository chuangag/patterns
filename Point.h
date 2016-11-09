#ifndef _POINT_H
#define _POINT_H
#include <math.h>
#include <iostream>
using namespace std;

//class of point
class Point{
private:
    
  int x;
  int y;
public:
  static Point origin;
  //constructors and destructors
    Point(){}
    Point(int a,int b):x(a),y(b){}
  ~Point(){}
  
  //get functions
  inline int getX() const{return x;}
  inline int getY() const{return y;}
  double getAngle() const;
  
  //set functions
  void setX(int a);
  void setY(int b);
void setOrigin(int ox,int oy);
  
  //overload operator
  //compare angles
  bool operator<(const Point p)const;
  bool operator==(const Point p)const;
  bool operator!=(const Point p)const;
  
};



//class of line, purpose is for checking if a points on the line, not used after all
class Line{
private:
    //coefficient of ax+by+c=0
    int a,b,c;
public:
    Line(){a=0;b=0;c=0;}
    Line(int A,int B, int C):a(A),b(B),c(C){}
    ~Line(){}
    bool isNotOnline(Point p){
        if(p.getX()*a+p.getY()*b+c==0){
            //cout<<"is on line"<<endl;
            return false;
        }
        else{
            return true;
        }
    }
    bool operator==(Line ln){
        
        if(a/ln.a==b/ln.b&&b/ln.b==c/ln.c){return true;}
        else
            return false;
        
    }
};



#endif
