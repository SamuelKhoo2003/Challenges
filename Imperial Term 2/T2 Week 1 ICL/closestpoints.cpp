
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
};
 
double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}
 
std::string point_to_s(Point p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}
 
// idxp1 and idxp2 are output parameters
// after the function call they will contain
// the indices of the two closest points in vp
// if vp contains two points or more
// (otherwise they will just contain uninitialised values)
 
void closest_points(const std::vector<Point>& vp, int& idxp1, int& idxp2){
    // TODO:
    // complete this function
    // (make use of function distance_points)
    double val, min; 
    min = 99; 
    for(int n = 0; n < vp.size() - 1; n++){
        for(int i = n+1; i < vp.size(); i++){
            val = distance_points(vp[n], vp[i]); 
            if(val <= min){
                idxp1 = n; 
                idxp2 = i;
                min = val; 
            }
        }
    }
}

// function doesn't work when the 2 closest points are the last 2 values in the vector
// function doesn't work for more than 4 points
// this is a case specific solution
 
// correction - this function is now functional

int main(){
 
    // TODO:
    // read the points from the file
    // and store them in vector points
    std::ifstream infile; 
    infile.open("points.txt");

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl; 
        return EXIT_FAILURE; 

    }

    std::vector<Point> points; 
    Point tmp; 
    
    while(infile >> tmp.x >> tmp.y){
        points.push_back(tmp); 
    }

    infile.close(); 


    if(points.size() == 0){
        std::cout << "there are no points in the file" << std::endl;
    }
    else if(points.size() == 1){
        std::cout << "there is only one point in the file" << std::endl;
    }
    else{
        int idxp1, idxp2;
        closest_points(points, idxp1, idxp2);
 
        // TODO: 
        // print the two points
        std::string pnt1, pnt2; 
        pnt1 = point_to_s(points[idxp1]); 
        pnt2 = point_to_s(points[idxp2]); 
        std::cout << pnt1 << std::endl; 
        std::cout << pnt2 << std::endl; 
    }
}