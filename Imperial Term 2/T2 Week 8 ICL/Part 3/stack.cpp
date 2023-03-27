#include <iostream>
 
typedef int stack_t;
 
struct StackLayer{
    stack_t val;
    StackLayer* next;
};
 
class Stack{
 
public:


    // TODO: implement the member functions (see the main)

    // this is the constructor which initialises an empty stack
    Stack() : top_layer(nullptr), size_(0) {}

    // this is the copy constructor
    Stack(const Stack& other) : top_layer(nullptr), size_(0){
        StackLayer* other_layer = other.top_layer; 
        while (other_layer){
            push(other_layer->val); 
            other_layer = other_layer->next; 
        }
    }

    // we then add an assignment operator 
    Stack& operator=(const Stack& other){
        if (this != &other){
            Stack temp(other); 
            swap(temp); 
        }
        return *this; 
    }


    // TODO: remember to add a destructor
    ~Stack(){
        while(top_layer){
            StackLayer* temp = top_layer; 
            top_layer = top_layer->next; 

        }
    }
 
    // push is the function which adds a value to the top layer of the stack, so new top stack 
    void push(int n){
        StackLayer* new_layer = new StackLayer{n, top_layer}; 
        top_layer = new_layer;
        size_++; 
    }

    // pop is the function which removes the top layer from the stack 
    void pop(){
        if(top_layer){
            StackLayer* tmp = top_layer; 
            top_layer =  top_layer->next; 
            delete tmp; 
            size_--; 
        }
    }

    int size() const{
        return size_; 
        
    }

    int top() const{
        if(top_layer){
            return top_layer->val; 
        }
        else{
            // we need to write a line which handles the case where the stack is empty so we throw an exception or default value
            throw std::out_of_range("stack is empty"); 
        }
    }

    // the void swap function is created to make it easier for me to write my assignment operator
    void swap(Stack& other){
        std::swap(top_layer, other.top_layer); 
        std::swap(size_, other.size_); 
    }
 
    
private:
 
    StackLayer* top_layer;  
    int size_;
    // i renamed it to size_ as it was confusing to have the function size and the int value size both being named the same
    // you can add other member data if needed but do not defeat the purpose of the exercise
    // e.g. don't add an std::vector to store the elements of the stack...
 
};
 
// this is in order to test that const correctness is implemented
void test_stack_const_correctness(const Stack& s){
    s.top();
    s.size();

}
 
int main(){
 
    Stack s1;
 
    s1.push(1);
    s1.push(2);
 
    std::cout << s1.top() << std::endl;
    // should print 2
 
    s1.pop();
 
    std::cout << s1.top() << std::endl;
    // should print 1
 
    Stack s2(s1);
 
    s2.push(3);
 
    std::cout << s2.top() << std::endl;
    // should print 3
 
    std::cout << s2.size() << std::endl;
    // should print 2
 
    std::cout << s1.top() << std::endl;
    // should print 1
    std::cout << "test" << "\n"; 

    std::cout << s1.size() << std::endl; 

    s1 = Stack(s2);
 
    std::cout << s1.top() << std::endl;
    std::cout << s1.size() << std::endl; 

    s1.pop(); 

    std::cout << s1.top() << std::endl; 

    // not sure why it should print 3, but i get 1 when 1 print 
    // i have discovered that this is because it copies the s2 in an opposite order as 3, 1 instead of 1,3
    // the correct way to get a completely identical swap is by having s1 = stack(s2)

 
}