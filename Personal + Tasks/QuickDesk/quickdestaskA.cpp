#include <iostream> 
#include <string> 
#include <vector> 
#include <cstdlib>

using namespace std; 

class IQueuable {
public:
    virtual vector<string> enqueue(string value) = 0;
    virtual string dequeue() = 0;
    virtual vector<string> getQueue() = 0;
    virtual int size() = 0;
};

class FIFOQueue : public IQueuable {
private:
    vector<string> queue;

public:
    vector<string> enqueue(string value) {
        queue.push_back(value);
        return queue;
    }

    string dequeue() {
        if (!queue.empty()) {
            string item = queue[0];
            queue.erase(queue.begin());
            return item;
        }
        return "";
    }

    vector<string> getQueue() {
        return queue;
    }

    int size() {
        return queue.size();
    }
};

class LIFOQueue : public IQueuable {
private:
    vector<string> queue;

public:
    vector<string> enqueue(string value) {
        queue.push_back(value);
        return queue;
    }

    string dequeue() {
        if (!queue.empty()) {
            string item = queue[queue.size() - 1];
            queue.pop_back();
            return item;
        }
        return "";
    }

    vector<string> getQueue() {
        return queue;
    }

    int size() {
        return queue.size();
    }
};

 int main() {
    FIFOQueue fifo;
    fifo.enqueue("apple");
    fifo.enqueue("banana");
    fifo.enqueue("cherry");

    cout << "FIFO queue: ";
    for (string item : fifo.getQueue()) {
        cout << item << " ";
    }
    cout << endl;

    cout << "Dequeued: " << fifo.dequeue() << endl;

    cout << "FIFO queue: ";
    for (string item : fifo.getQueue()) {
        cout << item << " ";
    }
    cout << endl;

    LIFOQueue lifo;
    lifo.enqueue("apple");
    lifo.enqueue("banana");
    lifo.enqueue("cherry");

    cout << "LIFO queue: ";
    for (string item : lifo.getQueue()) {
        cout << item << " ";
    }
    cout << endl;

    cout << "Dequeued: " << lifo.dequeue() << endl;

    cout << "LIFO queue: ";
    for (string item : lifo.getQueue()) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}

//b. If you’ve written your enqueue and dequeue using array methods, how would you rewrite the same functions without using any array methods?
// instead of using vector or array data structure, I would instead used a linked list style with head and tail nodes, filling in the values and moving them along
// granted this will be much more complex and doesn't improve efficiency, but it is an alternative method to solving this. 
// FIFO would have a head and tail, where the enqueue would continue to shift the new node to head, while tail is fixed. 
// LIFO would only need a head, where similarly the enqueue would add a new node to the beginning of the linked list and the next pointer of head would change


//c. Show how you would improve the design of your classes, apply various design patterns and techniques as you see fit
// We include an additional function that shows the current value at the front of the queue
// One improvement we could have is the factory method pattern, where we add a new class with a static method that takes a string argument or any type of variable
// This method then returns the corresponding queue method relating to the variable or string argument
// This is a useful improvement as it allows for us to add any additional types of queues and for us to easily switch between the methods without modifying the code. 

// An Example Of Improvement: 
class QueueFactory {
public:
    static IQueuable* createQueue(const string& type) {
        if (type == "FIFO") {
            return new FIFOQueue();
        } else if (type == "LIFO") {
            return new LIFOQueue();
        } else {
            return NULL;
        }
    }
};