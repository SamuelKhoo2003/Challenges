#include <iostream> 

double area(double l1, double l2){
    double a; 
    a = l1 * l2; 
    return a; 

}

double perimeter(double l3, double l4){
    double p; 
    p = 2*l3 + 2*l4; 
    return p; 

}

int main(){
    double length, width; 
    std::cout << "What is the length and width of your rectangle? " << std::endl; 
    std::cin >> length >> width; 
    std::cout << "The area is: " << area(length, width) << std::endl; 
    std::cout << "The perimeter is: " << perimeter(length, width) << std::endl; 
}