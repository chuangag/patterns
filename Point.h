#ifndef _POINT_H
#define _POINT_H
#include <math.h>
#include <iostream>
using namespace std;
const double eps=0.0000000000001;
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

Point Point::origin;//definition of static member

void Point::setX(int a){
  this->x=a;
}

void Point::setY(int b){
  this->y=b;
}

void Point::setOrigin(int ox,int oy){
    origin.setX(ox);
    origin.setY(oy);
}

bool Point::operator<(const Point p)const{
  if(this->getAngle()<p.getAngle())
    return true;
  else
    return false;
}

bool Point::operator==(const Point p)const{
    if(this->getAngle()-p.getAngle()<eps){
        return true;}
  else
    return false;
}

bool Point::operator!=(const Point p)const{
    if(*this==p)
        return false;
    else
        return true;
}


double Point::getAngle()const{
  double angle;
  if(x-origin.getX()==0)angle=-10;
  else if(y-origin.getY()==0)angle=0;
  else
    angle= atan((float)(y-origin.getY())/(float)(x-origin.getX()));
  return angle;
}


//class of line, purpose is for checking if a points on the line
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
