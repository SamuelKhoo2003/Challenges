#include <iostream>
#include <vector> 

template<typename T> 
class Stack{
public:
    void push(T const& value) {
        elements.push_back(value);
    }
    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): empty stack");
        }
        elements.pop_back();
    }
    T const& top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): empty stack");
        }
        return elements.back();
    }
    bool empty() const {
        return elements.empty();
    }
    std::size_t size() const {
        return elements.size();
    }
private:
    std::vector<T> elements; 
 
};

int main(){
 
    Stack<int> s1;
 
    s1.push(1);
    s1.push(2);
 
    std::cout << s1.top() << std::endl;
    // should print 2
 
    s1.pop();
 
    std::cout << s1.top() << std::endl;
    // should print 1
 
    // TODO: suitably declare/instantiate Stack s2
    Stack<double> s2; 

    s2.push(1.5);
    s2.push(1.3);
 
    std::cout << s2.top() << std::endl;
    // should print 1.3
 
    s2.pop();
 
    std::cout << s2.size() << std::endl;
    // should print 1
 
    std::cout << s2.top() << std::endl;
    // should print 1.5
 
}