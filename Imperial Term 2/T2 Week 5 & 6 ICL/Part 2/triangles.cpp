//Define a Triangle structured data type that contains three Point fields for the vertices.
//Include in Triangle a member function double perimeter() which returns the perimeter of the Triangle on which it is called.
//Use member function distance of Point in the implementation of member function perimeter of Triangle.
//Write a main to test the perimeter member function.

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
 
    std::string to_s(){
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
 
    double distance(Point p){
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }
}; 

struct Triangle{
    Point p1; 
    Point p2; 
    Point p3; 

    double perimeter(Triangle t){
        return p1.distance(p2) + p2.distance(p3) + p3.distance(p1); 
    }
}; 
 
int main(){
    Triangle t1; 

    std::cout << "Please enter the first coordinates of the triangle: " << std::endl; 
    std::cin >> t1.p1.x >> t1.p1.y; 
    std::cout << "Please enter the second coordinates of the triangle: " << std::endl; 
    std::cin >> t1.p2.x >> t1.p2.y; 
    std::cout << "Please enter the third coordinates of the triangle: " << std::endl; 
    std::cin >> t1.p3.x >> t1.p3.y; 

    std::cout << "The perimeter of the triangle is: " << std::endl; 
    std::cout << t1.perimeter(t1) << std::endl; 
}