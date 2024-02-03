#include <iostream>
using namespace std;

class DynamicArray {
private:
	int* array;
	int capacity;
	int size;

public:
	DynamicArray(int initialCapacity = 2) {
		capacity = initialCapacity;
		size = 0;
		array = new int[capacity];
	}

	~DynamicArray() {
		delete[] array;
	}

	void push(int value) {
		if (size == capacity) {
			capacity *= 2;
			int* newArray = new int[capacity];

			for (int i = 0; i < size; ++i) {
				newArray[i] = array[i];
			}

			delete[] array;
			array = newArray;
		}
		array[size++] = value;
	}

	void print() {
		for (int i = 0; i < size; ++i) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};