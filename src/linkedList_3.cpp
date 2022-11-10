#include <iostream>

class Node3 {
public:
	int data;
	Node3* next;
};

void pushBack(Node3* head, Node3* newNode) {
	if (head == nullptr) {
		return;
	}
	Node3* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = newNode;;
	newNode->next = nullptr;
}

void printLinkedList(Node3* head) {
	while (head != nullptr) {
		std::cout << head->data << "," << std::endl;
		head = head->next;
	}
}

Node3* genLinkedList(int n) {
	Node3* head = new Node3();
	head->data = 0;
	head->next = nullptr;
	Node3* tmp = nullptr;
	for (int i = 1; i < n; i++) {
		tmp = new Node3();
		tmp->data = i;
		pushBack(head, tmp);
	}
	printLinkedList(head);
	return head;
}

void delNode(Node3* head, int n) {
	Node3* tmp1 = head;
	if (n == 1) {
		head = tmp1->next;
		delete tmp1;
	}
	else {
		for (int i = 0; i < n - 2; i++) {
			tmp1 = tmp1->next;
		}
		Node3* tmp2 = tmp1->next;
		tmp1->next = tmp2->next;
		delete tmp2;
	}
	printLinkedList(head);
}

void delWithIndex() {
	Node3* head = genLinkedList(10);
	std::cout << " enter del index : ";
	int index;
	std::cin >> index;
	delNode(head, index);

}