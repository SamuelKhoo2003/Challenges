//Add a new version of the member function distance in points with only one parameter which returns the distance to the origin. 
//Write a main to test the function.

#include <iostream>
#include <cmath>
#include <string>
 
struct Point{
  double x;
  double y;
 
  Point(double ix, double iy){
    x = ix;
    y = iy;
  }
 
  std::string to_s() const {
      return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }
 
  double distance(Point p) const {
      return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }

  double distance_to_origin(Point p) const {
      return std::sqrt(std::pow((0 - p.x), 2) + std::pow((0 - p.y), 2));
  }


}; 
 
int main(){
  Point p(2, -0.5);
  std::cout << p.distance_to_origin(p) << std::endl;
}