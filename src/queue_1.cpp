// implement queue with array

#include <iostream>

constexpr auto cap = 5;

class queue {
private:
	int front, rear;
	int arr[cap] = {};

public:
	queue() {
		front = -1;
		rear = -1;
	}

	bool isEmpty() {
		return front == -1 && rear == -1;
	}

	bool isFull() {
		return (rear + 1) % cap == front ? true:false;
	}

	void push(int data) {
		if (isFull()) {
			std::cout << "QUEUE IS FULL." << std::endl;
			return;
		}

		if (isEmpty()) {
			front = 0;
			rear = 0;
		}
		else {
			rear = (rear + 1) % cap;
		}

		arr[rear] = data;
	}

	void pop() {
		int a = arr[front];
		if (isEmpty()) {
			return;
		} 

		// just one node in the queue
		if (front == rear) {
			front = rear = -1;
		}
		else {
			front = (front + 1) % cap;
		}
		std::cout << "pop front: " << a << std::endl;
	}

	int header() {
		if (isEmpty()) {
			std::cout << "queue is empty" << std::endl;
			return -1;
		}
		return arr[front];
	}

	void printQ() {
		std::cout << "front: " << front << "; rear: " << rear << std::endl;
		int size = (rear + cap - front) % cap;
		for (int i = 0; i <= size; i++) {
			std::cout << arr[(front+i) % cap] << ",";
		}
		std::cout << std::endl;
	}
};

void testQueue() {
	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	std::cout << "header: " << q.header() << std::endl;
	q.printQ();
	q.push(6);
	q.push(7);
	q.push(4);
	q.pop();
	std::cout << "header: " << q.header() << std::endl;
	q.push(5);
	q.printQ();

}