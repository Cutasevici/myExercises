#include <iostream>
using namespace std;

class Node {
public:
	int value;
	Node* next;

	Node(int value) {
		this->value = value;
		next = nullptr;
	}
};

class Stack {
private:
	Node* top;
	int hight;
public:
	Stack(int value) {
		Node* newNode = new Node(value);
		top = newNode;
		hight = 1;
	}

	void push(int value) {
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		hight++;
	}

	void display() {
		Node* temp = top;
		while (temp) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}
	void pop() {
		if (isEmpty()) {
			cout << "Stack is empty" << endl;
		}
		else {
			Node* temp = top;
			top = temp->next;
			delete temp;
			hight--;
		}
	}

	bool isEmpty() {
		if (hight == 0) return true;
		else {
			return false;
		}
	}
};