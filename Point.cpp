 
#include "Point.h"
const double eps=0.0000000000001;
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