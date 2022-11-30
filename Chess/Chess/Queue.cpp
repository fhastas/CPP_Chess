#include <iostream>
#include <Windows.h>
#include "Queue.h"
using namespace std;
int Recode::size() {
	return len;
}
bool Recode::isEmpty() {
	if (size() > 0) {
		return false;
	}
	return true;
}
void Recode::enqueue(string recode) {
	Node* newNode = new Node;
	newNode->recode = recode;
	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = rear->next;
	}
	len++;
}
string Recode::dequeue() {
	string null;
	if (isEmpty()) {
		cout << "큐가 비어있습니다!" << endl;
		Sleep(1000);
		return null;
	}
	Node* delNode = front;
	string recode = delNode->recode; 
	front = delNode->next;
	delete delNode;

	return recode;
}
