#include <iostream>

class Node6 {
public:
	int data;
	Node6* next;
};

void pushBack(Node6* head, Node6* newN) {
	Node6* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = newN;
}

Node6* genLinkedList(int n) {
	Node6* head = new Node6();
	head->data = 0;
	head->next = nullptr;
	Node6* tmp = nullptr;
	for (int i = 1; i < n; i++) {
		tmp = new Node6();
		tmp->data = i;
		pushBack(head, tmp);
	}
	return head;
}

void printNormalList(Node6* node) {
	if (node == nullptr) {
		std::cout << "\n";
		return;
	}
	std::cout << node->data << ",";
	printNormalList(node->next);
}


Node6* reverse(Node6* head) {
	if (head->next == nullptr) {
		return head;
	}
	Node6* lastHead = reverse(head->next);
	head->next->next = head;
	head->next = nullptr;
	return lastHead;
}

void reverseList() {
	Node6* n = genLinkedList(6);
	printNormalList(n);
	Node6* h = reverse(n);
	printNormalList(h);
}