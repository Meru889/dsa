#include <iostream>

// stack- linked list implementation

struct s_node {
public:
	int data;
	s_node* next;
};

class stack_2 {
private:
	s_node* top;
	

public:
	int s_size;
	stack_2() {
		s_size = 0;
		top = nullptr;
	}

	void push(int x) {
		s_node* s = new s_node();
		s->data = x;
		s->next = top;
		top = s;
		s_size++;
	}

	int pop() {
		s_node* tmp = this->top;
		top = tmp->next;
		tmp->next = nullptr;
		s_size--;
		return tmp->data;
	}

	bool isEmpty() {
		return s_size == 0 ? true : false;
	}

	int topNode() {
		return this->top->data;
	}

	void print() {
		s_node* tmp = this->top;
		std::cout << "stack:" << std::endl;
		while (tmp != nullptr) {
			std::cout << tmp->data << ",";
			tmp = tmp->next;
		}
	}
};

void testStack2() {
	stack_2 s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.print();
	std::cout << "pop:::::" << s.pop() << std::endl;
	s.print();
	std::cout << "size::::::" << s.s_size << std::endl;
	s.push(5);
	s.print();
	std::cout << "empty::::::" << s.isEmpty() << std::endl;
}