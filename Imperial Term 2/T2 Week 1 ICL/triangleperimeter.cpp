#include <iostream> 
#include <cmath> 
#include <string> 
#include <cstdlib> 

struct Point{
    double x;
    double y;
}; 

struct Triangle{
    Point p1; 
    Point p2; 
    Point p3; 
}; 

double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}

double triangle_perimeter(Triangle t){
    double perimeter; 
    perimeter = distance_points(t.p1, t.p2) + distance_points(t.p2, t.p3) + distance_points(t.p3, t.p1);
    return perimeter; 
}

int main(){

    Point pa, pb, pc; 

    std::cout << "enter coordinates for the vertices of the triangle" << std::endl; 
    std::cin >> pa.x >> pa.y;
    std::cin >> pb.x >> pb.y; 
    std::cin >> pc.x >> pc.y; 

    Triangle t1; 
    t1.p1 = pa; 
    t1.p2 = pb; 
    t1.p3 = pc; 

    std::cout << "the perimeter of the triangle is: " << triangle_perimeter(t1) << std::endl; 
}