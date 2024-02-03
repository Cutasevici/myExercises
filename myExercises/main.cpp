#include <iostream>
#include <string>
#include <vector>
#include "dinamic_array_stack.cpp"
using namespace std;

void findTwoNumbers(int array[], int size, int targetSum) {
	int indexOne;
	int indexTwo;
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size; ++j) {
			if (array[i] + array[j] == targetSum) {
				indexOne = i;
				indexTwo = j;
				cout << "indexOnde: " << indexOne << endl;
				cout << "indexTwo: " << indexTwo << endl;
				return;
			}
		}
	}
	cout << "no such sum" << endl;
}

int findMaxElement(int array[], int size) {
	if (size == 0) {
		cout << "Empty array. " << endl;
		return -1;
	}
	int maxNumber = array[0];
	for (int i = 1; i < size; ++i) {
		if (array[i] > maxNumber) {
			maxNumber = array[i];
		}
	}
	return maxNumber;
}

int factorial(int n) {
	if (n < 0) {
		cout << "No factorial for such number" << endl;
		return -1;
	}

	if (n == 0 || n == 1) {
		return 1;
	}

	int result = 1;

	for (int i = 2; i <= n; ++i) {
		result *= i;
	}
	return result;
}

bool isPrime(int n) {
	if (n < 0) return false;
	if (n == 2) {
		cout << "Number is 2 this is the exception" << endl;
		return true;
	}
	if (n % 2 == 0) {
		cout << "number defenetly not prime" << endl;
		return false;
	}
	for (int i = 3; i * i <= n; i += 2) {
		if (n % i == 0) {
			return false;
		}
	}	
}


void display(int array[], int size) {
	
	for (int i = 0; i < size;++i) {
			
			cout << "Index: " << i << ", Value: " << array[i] << endl;
		
	}
}
int sum_ofArray_and_average(int array[], int size) {
	int average = 0;
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += array[i];
		
	}

	cout << "sum: " << sum << endl;
	if (size == 0) return -1;
	else {
		average = sum / size;
	}
	cout << "average: " << average << endl;
	return sum;
}
int sumArray(int array[],int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	cout << sum << endl;
	return sum;
}

void reverseArray(int array[], int size) {
	int start = 0;
	int end = size - 1;

	while(start < end){
		int temp = array[start];
		array[start] = array[end];
		array[end] = temp;

		start++;
		end--;
	}	
}

string encript(string word, int key) {
	string myString = "";
	

	for (size_t i = 0; i < word.length(); ++i) {
		if (word[i] == ' ') {
			myString += ' ';
		}
		else {
			char currentChar = (word[i] + key - 'a') % 26 + 'a';
			myString += currentChar;
		}
	}
	return myString;
}
	
string decript(string newWord, int key){
	string decryptedString = "";
	for (size_t i = 0; i < newWord.length(); ++i) {
		if (newWord[i] == ' ') {
			decryptedString += ' ';
		}
		else {
			char newCurrentChar = (newWord[i] - key - 'a' + 26) % 26 + 'a';
			decryptedString += newCurrentChar;
		}
	}
	return decryptedString;
}

bool userInput(int key) {
	return static_cast<int>(key) == key;
	return false;
}


int main() {
    int nums[] = { 23, 92, 88, 425,16,4,5,76,67,43 };
	
	
	string word = "";
	string newWord = "";
	int key;
	cout << "Introcduce the word you want to encript: ";
	getline(cin, word);
	
	cout << "Introduce the key: (only int) :";
	cin >> key;

	if (userInput(key)) {
		cout << "valid key " << endl;
		cout << "\nEncripted word: " << encript(word, key) << endl;
		newWord = encript(word, key);
	}
	else {
		cout << "Invalid key, it must be int. " << endl;
		return -1;
	}

	cout << "\nDecripting word: " << endl;
	cout << endl;
	system("pause");
	cout << endl;
	cout << "Decripted word: " << decript(newWord, key) << endl;

	
	






    return 0;
}