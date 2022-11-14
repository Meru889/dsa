#include <iostream>


// 实现双向链表
class Node7 {
public:
	int data;
	Node7* next;
	Node7* prev;
};

Node7* newNode(int data) {
	Node7* node = new Node7();
	node->data = data;
	return node;
}

Node7* insertFromHead(Node7* head, Node7* node) {
	if (head == nullptr) {
		head = node;
		return head;
	}
	head->prev = node;
	node->next = head;
	return node;
}



void printNode7(Node7* head) {
	if (head != nullptr) {
		std::cout << head->data << ",";
		printNode7(head->next);
	}
}

void testNode7Head() {
	Node7* n1 = insertFromHead(nullptr, newNode(1));
	Node7* n2 = insertFromHead(n1, newNode(2));
	Node7* n3 = insertFromHead(n2, newNode(3));
	Node7* n4 = insertFromHead(n3, newNode(4));
	Node7* n5 = insertFromHead(n4, newNode(5));
	printNode7(n5);
}

Node7* insertFromTail(Node7* head, Node7* node) {
	if (head == nullptr) {
		head = node;
		return head;
	}
	Node7* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = node;
	node->prev = tmp;
	return head;
}

void testNode7Tail() {
	Node7* n1 = insertFromTail(nullptr, newNode(7));
	Node7* n2 = insertFromTail(n1, newNode(8));
	Node7* n3 = insertFromTail(n2, newNode(9));
	Node7* n4 = insertFromTail(n3, newNode(10));
	Node7* n5 = insertFromTail(n4, newNode(11));
	Node7* n6 = insertFromTail(n5, newNode(12));
	printNode7(n6);
}