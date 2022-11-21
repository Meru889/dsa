#include <iostream>

// reverse linkedlist using iterative
class Node4 {
public:
	int data;
	Node4* next;
};

void pushBack(Node4* head, Node4* newNode) {
	if (head == nullptr) {
		return;
	}
	Node4* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = newNode;;
	newNode->next = nullptr;
}

void printLinkedList(Node4* head) {
	while (head != nullptr) {
		std::cout << head->data << ",";
		head = head->next;
	}
	std::cout << "\n";
}

Node4* genLinkedList(int n) {
	Node4* head = new Node4();
	head->data = 0;
	head->next = nullptr;
	Node4* tmp = nullptr;
	for (int i = 1; i < n; i++) {
		tmp = new Node4();
		tmp->data = i;
		pushBack(head, tmp);
	}
	return head;
}

Node4* reverseLinked(Node4* head) {
	Node4 *pre, *current, *nt;
	current = head;
	pre = nullptr;
	while (current!= nullptr) {
		nt = current->next;
		current->next = pre;
		pre = current;
		current = nt;
	}
	head = pre;
	return head;
}

void reverse() {
	Node4* head = genLinkedList(9);
	head = reverseLinked(head);
	printLinkedList(head);
}