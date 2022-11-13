#include <iostream>


// 实现双向链表
class Node7 {
	int data;
	Node7* next;
	Node7* prev;
};

Node7* newNode(int data);

Node7* insertFromHead(Node7* head);

Node7* insertFromTail(Node7* head);

void printNode7();