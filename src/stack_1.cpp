#include <iostream>


// implement stack with array 

constexpr int MAX_CAP = 20;


class stack_1 {
public:
	int arr[MAX_CAP] = {};
	int top = -1;

	void push(int x) {
		if (top == MAX_CAP - 1) {
			printf("Error, array overflow.\n");
			return;
		}
		arr[++top] = x;
	}

	int pop() {
		if (top < 0) {
			printf("Error, no elements.\n");
			return 0;
		}
		return arr[top--];
	}

	bool isEmpty() {
		return top == -1 ? true : false;
	}

	int topNode() {
		if (top == -1) {
			printf("Error: no elements");
			return 0;
		}
		return arr[top];
	}

	void print() {
		for (int i = 0; i <= top; i++) {
			std::cout << arr[i] << std::endl;
		}
	}

};

void test_stack1() {
	stack_1 s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.print();
	std::cout << "s.top" << s.topNode() << std::endl;
	std::cout << "s.pop" << s.pop() << std::endl;
	s.print();
	std::cout << "s.pop" << s.pop() << std::endl;
	std::cout << "s.pop" << s.pop() << std::endl;
	std::cout << "s.pop" << s.pop() << std::endl;
	std::cout << "s.isEmpty" << s.isEmpty() << std::endl;
	std::cout << "s.pop" << s.pop() << std::endl;
	std::cout << "s.isEmpty" << s.isEmpty() << std::endl;
	
}