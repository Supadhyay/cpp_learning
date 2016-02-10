/*
Impliementing some more Algos on Linked List :
1. AppendList 
2.frontBackList
3.InserSort
4 RemoveDuplicate

*/
#include <iostream>
#include <string>
#include <map>
using namespace std;

//ToDo : Find out why use int vs void
// Do it for Arrays, trees, LL, vectors, dyn Arrays, graphs

class Node {

	int Data; 
	Node* next; 

public: 
	Node(){};
	
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

class SinglyLinkedList {
	
	

public:
	Node *listHeader;
	SinglyLinkedList(){ listHeader = NULL ;};
	
	void AddNode(int aData) {
		
		Node *nodeToAdd = new Node;
		nodeToAdd->setData(aData);
		nodeToAdd->setNext(NULL);
		
		if (listHeader == NULL) {
			listHeader = nodeToAdd;
			return;
		} 

		Node *iterator = listHeader; 
	
		while (iterator->getNext() != NULL) {
			iterator = iterator->getNext();	
		}
		iterator->setNext(nodeToAdd);
	};

	void PrintList() {

		int listCount = 0; 
		if (isEmpty()) {
			cout << endl <<"list is empty !" << endl << endl;
			return;
		}

		Node *iterator;
		iterator = listHeader;

		cout << endl << "Values in the list : " << endl;

		while (iterator != NULL) {
			cout << iterator->getData() << "==>>" ; 
			iterator = iterator->getNext();
			listCount++;
		}
		
		cout << endl << "Length of the list : " << listCount << endl ;
		cout << endl;
		return;

	};

	void DeleteNode(int adata) {
		//Add the case for head being deleted
		Node *iterator = listHeader;
		Node *tmp;

		while (iterator->getNext() != NULL) {
	
			if(iterator->getNext()->getData() == adata) {
				cout<< endl << "Lucky You !! Found the data." << endl;
				
				tmp = iterator->getNext();
				iterator->setNext(tmp->getNext());
				delete(tmp);

				PrintList();
				return;
			}

			iterator = iterator->getNext();	
		}
	};

	void deleteList(){
		
		Node *iterator = listHeader;
		Node *tmp;

		if(listHeader == NULL){
			cout<< "List is empty, nothing to delete";
			return;
		} else if(iterator->getNext() == NULL) {
			listHeader = NULL;
			delete(iterator);
			return;
		}
		
		while (iterator->getNext() != NULL) {
			tmp = iterator;
			iterator = iterator->getNext();
			delete(tmp);
		}

		listHeader = NULL;		
	
	};

	int pop() {

		Node *tmp;
		int popedDigit ;

		if(listHeader == NULL){
			cout<< "List is empty, nothing to delete";
			return NULL;
		} else if(listHeader->getNext() == NULL) {
			popedDigit = listHeader->getData();
			delete(listHeader);
			listHeader = NULL;
			return popedDigit;
		}

		tmp = listHeader;
		listHeader = listHeader->getNext();
		popedDigit = tmp->getData();
		delete(tmp);
		return popedDigit;
	}

	bool isEmpty () {
		if (listHeader) {
			return false;
		} else {
			return true;
		}

	};
	
	int leanthOfList() {

		int listCount = 0;

		if (listHeader == NULL) {
			return 0;
		} else if (listHeader->getNext() == NULL) {
			return 1;
		}

		Node *iterator = listHeader;

		while (iterator != NULL) {
			iterator = iterator->getNext();
			listCount++;
		}
		
		return listCount;

	}
};

void AppendLists (SinglyLinkedList *employeeListOne, SinglyLinkedList *employeeListTwo ) {
	
	Node* listOneHeader = employeeListOne->listHeader;
	Node* listTwoHeader = employeeListTwo->listHeader;

	if (listOneHeader->getNext() == NULL) {
		listOneHeader->setNext(listTwoHeader);
		free(listTwoHeader);
		employeeListOne->PrintList();
		return;
	} 

	Node* iterator = listOneHeader;

	while (iterator->getNext() != NULL) {
		iterator = iterator->getNext();	
	}

	iterator->setNext(listTwoHeader);
	employeeListOne->PrintList();
	employeeListTwo->listHeader = NULL;
	employeeListTwo->PrintList();
	return;
}


void frontBackSplit ( SinglyLinkedList *employListOne, SinglyLinkedList *employListTwo) {
	
	Node* iteratorFast = employListOne->listHeader;
	Node* iteratorSlow = employListOne->listHeader; 
	int listOneLength = employListOne->leanthOfList();

	if(employListOne->isEmpty() || listOneLength == 1) {
		cout << "List too short !! " ;
		return;
	} else if (listOneLength == 2) {
		employListTwo->listHeader = iteratorFast->getNext();
		iteratorFast->setNext(NULL);
		return;
	} else if (listOneLength == 3) {
		iteratorFast = iteratorFast->getNext();
		employListTwo->listHeader = iteratorFast->getNext();
		iteratorFast->setNext(NULL);
		return;
	}

	while (iteratorFast->getNext() != NULL && iteratorFast->getNext()->getNext() != NULL) {
		iteratorFast = iteratorFast->getNext()->getNext();
		iteratorSlow = iteratorSlow->getNext();
	}

	if(iteratorFast->getNext() != NULL) {
		iteratorFast = iteratorFast->getNext();
	}
	
	employListTwo->listHeader = iteratorSlow->getNext();
	iteratorSlow->setNext(NULL);
	return;

}

void insertSort(SinglyLinkedList *employList){
	Node* iteratorMain = employList->listHeader;
	Node* iteratorSecondary = employList->listHeader;
	int tmpData;

	while(iteratorMain != NULL) {
		iteratorSecondary = iteratorMain;
		while(iteratorSecondary != NULL ) {
			if(iteratorMain->getData() >= iteratorSecondary->getData()) {
				tmpData = iteratorMain->getData();
				iteratorMain->setData(iteratorSecondary->getData());
				iteratorSecondary->setData(tmpData);
			}
			iteratorSecondary = iteratorSecondary->getNext();
		}
		iteratorMain = iteratorMain->getNext();
	}

	employList->PrintList();
} 

void removeDuplicates(SinglyLinkedList *employList){
	Node *iterator = employList->listHeader;
	map<int, int> uniqueDataCount;
	Node *tmp;

	uniqueDataCount.insert(make_pair(iterator->getData(), 1));

	while(iterator->getNext() != NULL) {
		if(uniqueDataCount.find(iterator->getNext()->getData()) == uniqueDataCount.end()) {
			uniqueDataCount.insert(make_pair(iterator->getNext()->getData(), 1));
		} else {
			cout << endl << " Found duplicate(removing it): " << iterator->getNext()->getData() << endl;
			tmp = iterator->getNext();
			iterator->setNext(tmp->getNext());
			delete(tmp);
			if(iterator->getNext() == NULL) {
				employList->PrintList();
				return;
			} else {
				continue;
			}
		}
		iterator = iterator->getNext();
	}
	employList->PrintList();
	return;
}

int main(){
	
	SinglyLinkedList employeeList;
	SinglyLinkedList newEmployeeList;

	//int searchKey; 
	cout << " Creating Employee List One " << endl ;
	for (int i = 1; i <= 20; i++)
	{
		employeeList.AddNode(i);
	}
	
	employeeList.PrintList();

	cout << " Creating Employee List Two " << endl ;

	for (int i = 21; i <= 25; i++)
	{
		newEmployeeList.AddNode(i);
	}

	newEmployeeList.PrintList();

	cout << endl << endl << "============================== Appending List 2 to List 1 =================================" << endl << endl ;
	
	AppendLists(&employeeList, &newEmployeeList);

	
	cout << endl << endl << "============================== Front Back Split List 2 to List 1 =================================" << endl << endl ;
	
	frontBackSplit(&employeeList, &newEmployeeList);

	employeeList.PrintList();
	newEmployeeList.PrintList();

	
	cout << endl << endl << "==============================  Front Back List 2 to List 1 =================================" << endl << endl ;
	
	employeeList.deleteList();

	employeeList.AddNode(3);
	employeeList.AddNode(4);
	employeeList.AddNode(5);
	employeeList.AddNode(6);
	employeeList.AddNode(7);
	employeeList.AddNode(8);
	employeeList.AddNode(9);

	employeeList.PrintList();
	frontBackSplit(&employeeList, &newEmployeeList);


	employeeList.PrintList();
	newEmployeeList.PrintList();
	cout << "Deleting Employ List" ;
	employeeList.deleteList();

	cout << endl << endl << "=========================================== Removing Duplicates =========================================" << endl << endl;
	cout << "Creating New Employ List" ;
	employeeList.AddNode(3);
	employeeList.AddNode(10);
	employeeList.AddNode(5);
	employeeList.AddNode(6);
	employeeList.AddNode(2);
	employeeList.AddNode(2);
	employeeList.AddNode(6);
	employeeList.AddNode(91);
	employeeList.AddNode(8);
	employeeList.AddNode(91);
	employeeList.AddNode(6);
	employeeList.PrintList();
	cout <<endl <<endl;
	removeDuplicates(&employeeList);

	cout << endl << endl << "=========================================== Insert Sort =========================================" << endl << endl;
	
	insertSort(&employeeList);


	system("pause");

}*/