#include<iostream>


//始终在linkedList头部加入元素
class Node {
public:
    int value;
    Node* next;
};

Node* insert(Node* head, int n) {
    Node* tmp = new Node();
    tmp->value = n;
    tmp->next = head;
    head = tmp;
    return head;
}

void printNode(Node* h) {
    while (h != nullptr) {
        std::cout << h->value << std::endl;
        h = h->next;
    }
}

void insertFromHead() {
    Node* head = nullptr;
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter a num:" << std::endl;
        int num;
        std::cin >> num;
        head = insert(head, num);
        printNode(head);
    }
}