
#include "Brute.h"
//sorting points by x coordinates
bool compXcord(const Point &a,const Point &b){
    return a.getX()<b.getX();}



void Brute::BruteForce(){
  
  for(int a=0;a<numOfPoints;a++){
    for(int b=a+1;b<numOfPoints;b++){
      for(int c=b+1;c<numOfPoints;c++){
	for(int d=c+1;d<numOfPoints;d++){
	  //if all slope==infinite(x==0)
	  if(points.at(a).getX()==points.at(b).getX()&&points.at(b).getX()==points.at(c).getX()&&points.at(c).getX()==points.at(d).getX()){
	    vector<Point> PointsToPrint(4);
	    PointsToPrint.at(0)=points.at(a);PointsToPrint.at(1)=points.at(b);PointsToPrint.at(2)=points.at(c);PointsToPrint.at(3)=points.at(d);
	    PrintBruteResult(PointsToPrint);
	    pointsToDraw.push_back(PointsToPrint);
          
	  }
	  //if same y
	  else if(points.at(a).getY()==points.at(b).getY()&&points.at(b).getY()==points.at(c).getY()&&points.at(c).getY()==points.at(d).getY()){
	    vector<Point> PointsToPrint(4);
	    PointsToPrint.at(0)=points.at(a);PointsToPrint.at(1)=points.at(b);PointsToPrint.at(2)=points.at(c);PointsToPrint.at(3)=points.at(d);
	    PrintBruteResult(PointsToPrint);
	    pointsToDraw.push_back(PointsToPrint);
          
	  }
	  //same slope relate to a
	  else{
	    bool slopecmp_ab_ac,slopecmp_ab_ad;//slopes between ab, ac, ad
        
    
	    slopecmp_ab_ac=((points.at(b).getY()-points.at(a).getY())*(points.at(c).getX()-points.at(a).getX())==(points.at(c).getY()-points.at(a).getY())*(points.at(b).getX()-points.at(a).getX()));
	    slopecmp_ab_ad=((points.at(b).getY()-points.at(a).getY())*(points.at(d).getX()-points.at(a).getX())==(points.at(d).getY()-points.at(a).getY())*(points.at(b).getX()-points.at(a).getX()));
          
          
	    if(slopecmp_ab_ac&&slopecmp_ab_ad){
            
	      vector<Point> PointsToPrint(4);
	      PointsToPrint.at(0)=points.at(a);PointsToPrint.at(1)=points.at(b);PointsToPrint.at(2)=points.at(c);PointsToPrint.at(3)=points.at(d);
	      //sort by x coordinates
	      sort(PointsToPrint.begin(),PointsToPrint.end(),compXcord);
	      PrintBruteResult(PointsToPrint);
	      pointsToDraw.push_back(PointsToPrint);
            
	    }
	      
	  } 
	}
      }
    }
  }
}

void Brute::PrintBruteResult(vector<Point> pointsToPrint){
  cout<<"4:";
  for(int i=0;i<4;i++){
    cout<<"("<<pointsToPrint[i].getX()<<", "<<pointsToPrint[i].getY()<<")";
    if(i!=3)//not last point
      cout<<" -> ";
    else
      cout<<endl;
  }
}
    