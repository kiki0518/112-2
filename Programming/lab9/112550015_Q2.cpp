#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class MaxHeap {
public:
    MaxHeap() : elements(1) {} // Initialize with a dummy element at index 0

    MaxHeap(const std::vector<int>& data) : elements(1) { 
      	for (int val : data) {
            elements.push_back(val);
        }
        buildHeap();
    }

    void insertValueInHeap(int value) {
        elements.push_back(value);
        heapifyUp(sizeOfHeap());
    }

    void extractMax() {
        if(isEmpty())   return;
        int last = elements.back();
        elements.pop_back();
        elements[1] = last;
        heapifyDown(1);
    }
  
  	int peekTopOfHeap() const {
        if(isEmpty())   return -1;
        return elements[1];
    }
  
  	int sizeOfHeap() const {
        return elements.size() - 1;
    }

    bool isEmpty() const {
        return (sizeOfHeap() == 0);
    }

    void print() const {
        for(int i = 1; i < elements.size(); i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
  
  	// Can add anything you needed

private:
    std::vector<int> elements;

    void heapifyUp(int index) {
        while(index > 1 && elements[parent(index)] < elements[index]) {
            swap(elements[parent(index)], elements[index]);
            index = parent(index);
        }      	
    }

    void heapifyDown(int index) {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;
       
        if(left < elements.size() && elements[left] > elements[largest]) {
            largest = left;
        }
        if(right < elements.size() && elements[right] > elements[largest]) {
            largest = right;
        }

        if(largest != index) {
            swap(elements[largest], elements[index]);
            heapifyDown(largest);
        }
    }

  	int parent(int index) const {
        return index / 2;
    }

    int leftChild(int index) const {
        return index * 2;
    }

    int rightChild(int index) const {
        return index * 2 + 1;
    }
  	// Can add anything you need
    void buildHeap() {
        for(int i = sizeOfHeap()/2; i >= 1; i--) {
            heapifyDown(i);
        }
    }
  	
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;
    std::vector<int> data(t);
    for (int i = 0; i < t; ++i){
        int value;
        cin >> value;
        data[i] = value;
    }
    
    MaxHeap maxHeap(data); // build max heap from array data
    
    maxHeap.print();
    
    string s;
    int value;
    cin >> s >> value;
    maxHeap.insertValueInHeap(value); // insertValueInHeap
    
    maxHeap.print();
    
    cin >> s;
    maxHeap.extractMax(); // extractMax
    
    maxHeap.print();

    return 0;
}