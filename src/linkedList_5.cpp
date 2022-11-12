#include <iostream>

class Node5 {
public:
	int data;
	Node5* next;
};

void pushBack(Node5* head, Node5* newN) {
	Node5* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = newN;
}

Node5* genLinkedList(int n) {
	Node5* head = new Node5();
	head->data = 0;
	head->next = nullptr;
	Node5* tmp = nullptr;
	for (int i = 1; i < n; i++) {
		tmp = new Node5();
		tmp->data = i;
		pushBack(head, tmp);
	}
	return head;
}

void printNormalList(Node5* node) {
	if (node == nullptr) {
		std::cout << "\n";
		return;
	}
	std::cout << node->data << ",";
	printNormalList(node->next);
	
}

void printReverseList(Node5* node) {
	if (node == nullptr) {
		std::cout << "\n";
		return;
	}
	printReverseList(node->next);
	std::cout << node->data << ",";

}

void printList() {
	Node5* head = genLinkedList(8);
	printNormalList(head);
	printReverseList(head);
}


