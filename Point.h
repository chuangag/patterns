#ifndef _POINT_H
#define _POINT_H
#include <math.h>
class Point{
private:
  int x;
  int y;
public:
  //constructors and destructors
  Point():x(0),y(0){}
  Point(int a,int b):x(a),y(b){}
  ~Point(){}
  
  //get functions
  inline int getX() const{return x;}
  inline int getY() const{return y;}
  float getAngle(Point p1,Point p2) const;
  
  //set functions
  void setX(int a);
  void setY(int b);
  
  /*not yet
  //overload operator
  //compare angles
  bool operator<(Point p);
  bool operator==(Point p);
  */
};

void Point::setX(int a){
  this->x=a;
}

void Point::setY(int b){
  this->y=b;
}

/* not yet
bool Point::operator<(Point p){
  if(this->getAngle()<p.getAngle())
    return true;
  else
    return false;
}

bool Point::operator==(Point p){
  if(this->getAngle()==p.getAngle())
    return true;
  else
    return false;
}
*/

float Point::getAngle(Point p1,Point p2) const{
  float angle = atan2(p1.getY() - p2.getY(), p1.getX() - p2.getX());
  return angle;
}

#endif