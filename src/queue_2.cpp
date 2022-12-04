// implement queue with Linkedlist

#include <iostream>

struct q_node {
public:
	int data;
	q_node* next;
};

class queue2 {

private:
	q_node* head;
	q_node* rear;

public:
	queue2() {
		head = nullptr;
		rear = nullptr;
	}

	bool isEmpty() {
		this->head == nullptr ? true : false;
	}

	void push(int x) {
		q_node* n = new q_node();
		n->data = x;
		n->next = nullptr;
		if (rear == nullptr && head == nullptr) {
			head = rear = n;
			return;
		}
		if (rear != nullptr) {
			rear->next = n;
		}
		rear = n;
	}

	void pop() {
		if (rear == nullptr) {
			return;
		}
		if (head == rear) {
			head = rear = nullptr;
			return;
		}
		
		q_node* tmp = head;
		head = tmp->next;
		delete tmp;
	}

	void top() {
		if (head != nullptr) {
			std::cout << "top: " << head->data << std::endl;
		}
		else { 
			std::cout << "queue is empty" << std::endl; 
		}
	}

	void printQ() {
		q_node* tmp = this->head;
		while (tmp != nullptr) {
			std::cout << tmp->data << ",";
			tmp = tmp->next;
		}
		std::cout << std::endl;
	}
};

void testQueue2() {
	queue2* q = new queue2();
	q->push(1);
	q->push(2);
	q->push(3);
	q->push(4);
	q->push(5);
	q->printQ();
	q->top();
	q->pop();
	q->printQ();

}