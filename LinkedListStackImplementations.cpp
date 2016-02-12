/*
Implimenting stack using Linked List operations :
1> Pop
2> Push
3> empty
4> peek
6> Print

Some more cleanup might be needed but just wanted to get the code going so implimented quick code. 

*/
#include <iostream>
#include <string>
using namespace std;
#define NOT_FOUND -32767
//ToDo : Find out why use int vs void
// Do it for Arrays, trees, LL, vectors, dyn Arrays, graphs

class Node {

	int Data; 
	Node *next; 

public: 
	Node(){};
	Node(int adata, Node* aNext){
		Data = adata;
		next = aNext;
	}
	
	void setData(int aData) {
		Data = aData ;
	};
	
	void setNext(Node* aNext) {
		next = aNext;
	};

	int getData() { 
		return Data;
	};

	Node* getNext() { 

		return next; 
	};
};

class Stack {
	
	Node *stackPointer;
	int counter;

public: 
	Stack(){ stackPointer = NULL ; counter = 0;};
	
	void Push(const int aData) {
		
		Node *nodeToAdd = new Node;
		nodeToAdd->setData(aData);
		nodeToAdd->setNext(NULL);
	
		if (stackPointer == NULL) {
			stackPointer = nodeToAdd;
			counter++;
			return;
		} 

		nodeToAdd->setNext(stackPointer);
		stackPointer = nodeToAdd;
		counter++;
		cout << endl << "Added : "  << nodeToAdd->getData()<< " to stack ! " << endl << endl;
		return;
	};

	bool isEmpty() {
		if (stackPointer) {
			return false;
		} else {
			return true;
		}
	}

	void printStack() {

		if (isEmpty()) {
			cout << endl <<"Stack is empty !" << endl << endl;
			return;
		}

		Node *iterator;
		iterator = stackPointer;

		cout << endl << endl << " Values in the stack : *SP*=>" ;

		while (iterator != NULL) {
			cout << iterator->getData() << "==>>" ; 
			iterator = iterator->getNext();
		}
		cout << endl << "Count : " << counter << endl;
		cout << endl << endl;
		return;
	};

	int pop() {
		Node *tmp;
		int popedDigit ;

		if(isEmpty()){
			cout<< "List is empty, nothing to Pop";
			return NOT_FOUND;
		} else if(stackPointer->getNext() == NULL) {
			popedDigit = stackPointer->getData();
			delete(stackPointer);
			stackPointer = NULL;
			counter--;
			return popedDigit;
		}

		tmp = stackPointer;
		stackPointer = stackPointer->getNext();
		popedDigit = tmp->getData();
		counter--;
		delete(tmp);
		return popedDigit;
	}

	int seek() {

		if(isEmpty()){
			cout<< "List is empty, nothing to seek";
			return NOT_FOUND;
		
		} else if(stackPointer->getNext() == NULL) {
			return stackPointer->getData();
		}

		return stackPointer->getNext()->getData();
	}

};


int main(){
	
	Stack numberOfBalls;

	for (int i = 1; i <= 20; i++)
	{
		numberOfBalls.Push(i);
	}
	
	numberOfBalls.printStack();

	cout << endl << "Popping : " << endl << "Popped =>" << numberOfBalls.pop() << endl << "Popped =>" << numberOfBalls.pop() << endl << "Popped =>" << numberOfBalls.pop() << endl << endl ;
	numberOfBalls.printStack();
	cout << endl << "Seek : " << numberOfBalls.seek() << endl;
	cout << endl << "Pop : " << numberOfBalls.pop() << endl;
	cout << endl << "Seek : " << numberOfBalls.seek() << endl;
	numberOfBalls.printStack();

	system("pause");
	return 0; 
}
