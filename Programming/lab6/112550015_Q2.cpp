#include <iostream>

class CircularQueue {
public:
	CircularQueue(int size) {
        this->size = size;
        arr = new int(this->size);
        front = 0;
        rear = -1;
	}

	void enQueue(int data) {
        if(this->isFull()) {
            std::cout<<"Queue is full"<<std::endl;
            return;
        }
        if(rear+1 == size) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = data;
	}

	void deQueue() {
        if(this->isEmpty()) {
            std::cout<<"Queue is empty"<<std::endl;
            return;
        }
        if(front == rear) {
            rear = -1;
            front = 0;
        } else if(front+1 == size) {
            front = 0;
        } else {
            front++;
        }
	}

	int peek() {
        if(this->isEmpty()) {
            std::cout<<"Queue is empty"<<std::endl;
            return -1;
        } else {
            return arr[front];
        }
	}

	bool isEmpty() {
        return (rear == -1);
	}

	bool isFull() {
        if(this->isEmpty())   return false;
        if(front == rear + 1) {
            return true;
        } else if(!front && (rear + 1 == size)) {
            return true;
        } else 
            return false;
	}

	void expand(int newSize) {        
        if(newSize > size) {
            // std::cout<<"Can only expand the size"<< std::endl;
            
            int* newArr = new int(newSize);
            if(front <= rear) {
                for(int i = 0; i < size; i++) {
                    newArr[i] = arr[i];
                }
            } else {
                for(int i = front; i < size; i++) {
                    newArr[i] = arr[i];
                }
                for(int i = size; i%size!=rear+1; i++) {
                    newArr[i%newSize] = arr[i%size];
                }
            }
            this->size = newSize;
            free(arr);
            arr = newArr;
        }
        
	}
    

private:
	int *arr;
	int front, rear, size;
};

int main(void) {
	CircularQueue q(5);
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	q.enQueue(6);
	q.expand(6);
	q.enQueue(6);
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.enQueue(10);
	std::cout << q.peek() << std::endl;
	q.deQueue();
	q.deQueue();
	q.deQueue();
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.deQueue();
	std::cout << q.peek() << std::endl;
	q.deQueue();
}