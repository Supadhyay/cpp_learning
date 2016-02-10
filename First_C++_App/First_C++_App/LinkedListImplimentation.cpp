/*
Implimenting various Linked List operations :
1. Add Node 
2. Delete Node 
3. GetNth
4. Inset Nth
5. Pop
6. Search Node

Some more cleanup might be needed but just wanted to get the code going so implimented quick code. 

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
	
	Node *listHeader;

public: 
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
			cout << "==>" << iterator->getData();
			iterator = iterator->getNext();	
		}
		iterator->setNext(nodeToAdd);
		cout << "==>" << nodeToAdd->getData()<< endl << endl;
		return;
	};

	bool isEmpty () {
		if (listHeader) {
			return false;
		} else {
			return true;
		}

	}
	void PrintList() {

		int listCount = 0; 
		if (isEmpty()) {
			cout << endl <<"list is empty !" << endl << endl;
			return;
		}

		Node *iterator;
		iterator = listHeader;

		cout << endl << " Values in the list :   " ;

		while (iterator != NULL) {
			cout << iterator->getData() << "==>>" ; 
			iterator = iterator->getNext();
			listCount++;
		}
		
		cout << endl << endl << "Length of the list : " << listCount << endl ;
		cout << endl;
		return;

	};

	void SearchNode(int adata) {
		
		Node *iterator = listHeader;
		
		while (iterator->getNext() != NULL) {
			if(iterator->getData() == adata) {
				cout<< endl << "Found the data !! " << endl << endl; 
				return;
			}
			iterator = iterator->getNext();	
		}

		cout << "Data not found on the list!";
		return;
	};

	void DeleteNode(int adata) {
		//Add the case for head being deleted
		Node *iterator = listHeader;
		Node *tmp;

		while (iterator->getNext() != NULL) {
	
			if(iterator->getNext()->getData() == adata) {
				cout<< endl << "Found the data and deleting it ! " << endl;
				
				tmp = iterator->getNext();
				iterator->setNext(tmp->getNext());
				delete(tmp);

				PrintList();
				return;
			}

			iterator = iterator->getNext();	
		}

		cout << "Data not found on the list!";
		return;
	};

	void getNth(int Nposition){
		
		Node *iterator = listHeader;
		int nodeCounter = 1;

		if (listHeader == NULL) {
			cout << endl <<"list is empty !" << endl;
			return;
		}

		while (iterator->getNext() != NULL) {
			if(nodeCounter == Nposition) {
				cout << endl << " Found the " << Nposition << " element  ==> " << iterator->getData() <<endl;
				return; 
			} 
			nodeCounter++;
			iterator = iterator->getNext();	
		}
		
		cout << "Data not found on the list!";
		return;
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
		PrintList();
		return;
	
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

	void insertNth(int location, int aData){
		Node *tmp;
		Node *iterator = listHeader;
		int counter = 0;

		if(listHeader == NULL){
			cout<< "List is empty, nothing to delete" << endl;
			return;
		} else if(location == 1) {
			tmp = new Node;
			tmp->setData(aData);
			tmp->setNext(listHeader->getNext());
			listHeader = tmp;
			cout <<  "First Data added" << endl;
			return;
		}
		cout << "Location : " << location;
		while(iterator->getNext() != NULL) {
			
			if(counter == location-1) {
				tmp = new Node;
				tmp->setData(aData);
				tmp->setNext(iterator->getNext());
				iterator->setNext(tmp);
				cout<< endl <<"Added : " << aData << endl << endl ;
				//PrintList();
				return;
			} 

			counter++;
			iterator = iterator->getNext();
		}

		cout << endl << endl<< " Out Of Bounds " << endl;
	}

};


int main(){
	
	SinglyLinkedList employeeList;
	int searchKey; 
	for (int i = 1; i <= 20; i++)
	{
		employeeList.AddNode(i);
	}
	
	employeeList.PrintList();
	
	system("pause");
	
	cout << endl << "Enter the number to find : ";
	cin >> searchKey;
	employeeList.SearchNode(searchKey);
	
	system("pause");
	
	cout << endl << "Enter the number to Delete : ";
	cin >> searchKey; 
	employeeList.DeleteNode(searchKey);
	
	system("pause");
	
	cout << endl << "Enter the poisition to find : ";
	cin >> searchKey;
	employeeList.getNth(searchKey);

	

	//Not sure why the pops work from right to left .. TO Find out !! 
	cout << "Popping Elements from the list : " << endl << employeeList.pop() << endl << employeeList.pop() << endl << employeeList.pop() << endl << employeeList.pop() ;

	cout << endl <<endl << "Insterting 5 at location 3 " << endl << endl ;
	employeeList.insertNth(3,5);
	employeeList.PrintList();	
	cout << endl <<endl << "Insterting 17 at location 123 " << endl << endl ;
	employeeList.insertNth(14,123);

	employeeList.PrintList();																																
	system("pause");
	
	return 0; 

}
