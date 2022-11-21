#include<iostream>



// add a element to the linkedlist anywhere

class Node2 {
public:
    int data;
    Node2* next;
};

void printData(Node2* head) {
    while (head != nullptr) {
        std::cout << head->data << std::endl;
        head = head->next;
    }
}

Node2* insertData(Node2* head, int value, int index) {
    Node2* tmp = new Node2();
    tmp->data = value;
    tmp->next = 0;
    // index 1
    if (index == 1 || head == nullptr) {
        tmp->next = head;
        head = tmp;
    }
    else {
        Node2* t2 = head;
        Node2* t3 = new Node2();
        for (int i = 0; i < index - 2; i++) {
            if (t2 == nullptr) {
                break;
            }
            t2 = t2->next;
        }
        if (t2 == nullptr) {
            t2 = head;
            while (t2 != nullptr) {
                t3 = t2;
                t2 = t2->next;
            }
            t3->next = tmp;
        }
        else {
            tmp->next = t2->next;
            t2->next = tmp;
        }
    }
    return head;
}

void insertWithIndex() {
    Node2* head = nullptr;
    for (int i = 0; i < 4; i++) {
        std::cout << "enter data:" << std::endl;
        int data;
        std::cin >> data;
        std::cout << "enter index" << std::endl;
        int index;
        std::cin >> index;
        head = insertData(head, data, index);
        printData(head);
    }
}