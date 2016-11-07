#ifndef _POINT_H
#define _POINT_H
#include <math.h>
//class of point
class Point{
private:
    static Point origin;
  int x;
  int y;
public:
  //constructors and destructors
    Point():x(0),y(0){setOrigin(0,0);}
    Point(int a,int b):x(a),y(b){setOrigin(0,0);}
  ~Point(){}
  
  //get functions
  inline int getX() const{return x;}
  inline int getY() const{return y;}
  float getAngle(Point p)const;
  
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
  if(getAngle(*this)<getAngle(p))
    return true;
  else
    return false;
}

bool Point::operator==(const Point p)const{
  if(getAngle(*this)==getAngle(p))
    return true;
  else
    return false;
}

bool Point::operator!=(const Point p)const{
    if(*this==p)
        return false;
    else
        return true;
}


float Point::getAngle(Point p) const{
  float angle = atan2(p.getY()-origin.getY(), p.getX()-origin.getX());
  return angle;
}


//class of line, purpose is for checking if a points on the line
class Line{
private:
    //coefficient of ax+by+c=0
    int a,b,c;
public:
    Line(int A=1,int B=1, int C=0):a(A),b(B),c(C){}
    ~Line(){}
    bool checkIsOnline(Point p){
        if(a*p.getX()+b*p.getY()+c==0)
            return true;
        else
            return false;
    }
};


#endif
