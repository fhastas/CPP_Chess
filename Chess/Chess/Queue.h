#pragma once
#include <string>
using namespace std;

#ifndef __QUEUE
#define __QUEUE
class Node {
public:
	string recode;
	Node* next = NULL;
};
class Recode {
private:
	Node* data = NULL;
	Node* front = NULL, * rear = NULL;
	int len = 0;
public:
	int size();
	bool isEmpty();
	void enqueue(string recode);
	string dequeue();
};

#endif // __QUEUE
