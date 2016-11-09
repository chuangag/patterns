#include "Fast.h"
//sorting points by x coordinates
bool compXcord2(const Point &a,const Point &b){
    return a.getX()<b.getX();}


bool compAngle(const Point &a,const Point &b){
    return (a<b);}

void Fast::FastAlgo(){
    vector<vector<Point> > seriesOfPointsToPrint(0);
    
    vector<vector<Point> > linesPrinted(0);
    //create a copy of original points for iterating
    vector<Point> copypoints=points;
    
    for(int i=0;i<numOfPoints;i++){
    
        //set the origin to points.at(i)
        copypoints.at(i).setOrigin(copypoints.at(i).getX(),copypoints.at(i).getY());
        //sort the other points by angle start from i+1
        sort(points.begin(),points.end(),compAngle);
        //create a vector of vector<point> points to print, ie: few lines to print
	
        bool firstLineCreated=false;
        
        for(int j=0;j<points.size();j++){
            if(copypoints.at(i).getX()==points.at(j).getX()&&copypoints.at(i).getY()==points.at(j).getY()){
                //do nothing
            }
            else if(j>0&&(points.at(j)==points.at(j-1))&&firstLineCreated){
                seriesOfPointsToPrint.back().push_back(points.at(j));
            }
            else if( (j ==0 ||points.at(j)!=points.at(j-1) )&& ( j<points.size()-1 && points.at(j)==points.at(j+1) )){
                vector<Point> PointsToPrint(0);
                firstLineCreated=true;
                seriesOfPointsToPrint.push_back(PointsToPrint);
                seriesOfPointsToPrint.back().push_back(points.at(j));
                seriesOfPointsToPrint.back().push_back(copypoints.at(i));
            }
        }
        
        //going over the sorted points and add point with same angle into points to print, only check series with more than 1 elements
              
        //note that points[i]should be included
        
    }
    for(int r=0;r<seriesOfPointsToPrint.size();r++){
        bool repeated=false;
        if(seriesOfPointsToPrint.at(r).size()>3){
            sort(seriesOfPointsToPrint.at(r).begin(),seriesOfPointsToPrint.at(r).end(),compXcord2);
            
            if(linesPrinted.empty()){
                //printFast(seriesOfPointsToPrint.at(r));
                linesPrinted.push_back(seriesOfPointsToPrint.at(r));
            }
            else{
                for(int l=0;l<linesPrinted.size();l++){
                    if((linesPrinted.at(l)==seriesOfPointsToPrint.at(r))){
                        repeated=true;
                        break;
                    }
                }
            }
            if(repeated==false){
                printFast(seriesOfPointsToPrint.at(r));
                linesPrinted.push_back(seriesOfPointsToPrint.at(r));
            }
        }
        
    }
    //add to vector for drawing
    for(int l=0;l<linesPrinted.size();l++){
       pointsToDraw.push_back(linesPrinted.at(l));
    }
    
}

void Fast::printFast(vector<Point> pointsToPrint){
    cout<<pointsToPrint.size()<<":";
    for(int i=0;i<pointsToPrint.size();i++){
        cout<<"("<<pointsToPrint[i].getX()<<", "<<pointsToPrint[i].getY()<<")";
        if(i!=pointsToPrint.size()-1)//not last point
            cout<<" -> ";
        else
            cout<<endl;
    }
}