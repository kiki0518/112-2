#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> stack1;
    stack<int> stack2;

public:
    MyQueue() {
        
    }
    
    void enQueue(int x) {
        // TODO
        stack1.push(x);
    }
    
    int deQueue() {
        // TODO
        int ret;
        if(isEmpty()) return -1;

        if(!stack2.empty()) {
            ret = stack2.top();
            stack2.pop();
            return ret;
        } else {
            while (!stack1.empty()) { 
                stack2.push(stack1.top());
                stack1.pop();
            }
            ret = stack2.top();
            stack2.pop();
            return ret;
        } 
    }
    
    int peek() {
        // TODO
        int ret;

        if(isEmpty()) return -1;

        if(!stack2.empty()) {
            ret = stack2.top();
            return ret;
        } else {
            while (!stack1.empty()) { 
                stack2.push(stack1.top());
                stack1.pop();
            }
            ret = stack2.top();
            return ret;
        } 
      	
    }
    
    bool isEmpty() {
        // TODO
        if(stack1.empty() && stack2.empty()) {
            return true;
        }
        return false;
      	
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    MyQueue queue;
    string command;
    while(cin >> command){
        int value;
        if (command == "enqueue") {
            // TODO
            cin >> value;
            queue.enQueue(value);
            cout << "Enqueued "<<value<<endl;
        } else if (command == "dequeue") {
            // TODO
            value = queue.deQueue();
            if(value == -1) {
                cout<<"Queue is empty"<<endl;
            } else {
          	    cout << "Dequeued "<<value<<endl;
            }
        } else if (command == "peek") {
            // TODO
            value = queue.peek();
            if(value == -1) {
                cout<<"Queue is empty"<<endl;
            } else {
          	    cout << "Front element: "<<value<<endl;
            }
        } else if (command == "empty") {
            // TODO
            if(queue.isEmpty()) {
                cout<<"Queue is empty"<<endl;
            } else {
          	    cout << "Queue is not empty"<<endl;
            }
          	
        } else {
            cout << "Invalid command" << endl;
        }
    }
    return 0;
}