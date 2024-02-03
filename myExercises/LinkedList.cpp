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

class LinkedList {
private:
	Node* head;
	Node* tail;
	int length;
public:
	LinkedList(int value) {
		Node* newNode = new Node(value);
		head = newNode;
		tail = newNode;
		length = 1;
	}

	~LinkedList() {
		Node* temp = head;
		while (temp) {
			head = temp->next;
			delete temp;
			temp = head;
			length--;
		}
	}

	void append(int value) {
		Node* newNode = new Node(value);
		if (length == 0) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		length++;
	}

	void printList() {
		Node* temp = head;
		while (temp) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}

	int getIndex(int value) {
		Node* temp = head;
		int index = 0;

		while (temp) {
			if (temp->value == value) {
				return index;
			}
			temp = temp->next;
			index++;
		}

		cout << "index not found " << endl;
		return -1;
	}
	void deleteLast() {
		if (length == 0) {
			cout << "the list is empty" << endl;
			return;
		}
		if (length == 1) {
			delete head;
			head = nullptr;
			tail = nullptr;
			length--;
		}
		else {
			Node* temp = head;
			Node* previous = nullptr;
			while (temp->next != nullptr) {
				previous = temp;
				temp = temp->next;
			}
			delete temp;
			tail = previous;
			tail->next = nullptr;
			length--;	
		}
	}

	void deleteFirst() {
		Node* temp = head;
		if (length == 0) {
			cout << "the list is empty" << endl;
			return;
		}
		if (length == 1) {
			head = nullptr;
			tail = nullptr;
			delete temp;
			length--;
		}
		else {
			head = head->next;
			delete temp;
			length--;
		}
	}
};