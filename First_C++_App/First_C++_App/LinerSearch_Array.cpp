#include <iostream>
using namespace std;

//ToDo : Find out why use int vs void
// Do it for Arrays, trees, LL, vectors, dyn Arrays, graphs

int main(){

	int listOfNumber[10] = {2,435,66,33,77,343,3,5,11,32};
	int searchKey;

	cout << "Below is the array to be searched : " << endl; 
	for (int i = 0 ; i < sizeof(listOfNumber)/sizeof(listOfNumber[0]); i++) {
		cout << listOfNumber[i] << endl;
	}

	cout << endl << "Please enter the search key  : " ;
	cin >> searchKey;

	for (int i = 0 ; i < sizeof(listOfNumber)/sizeof(listOfNumber[0]); i++) {
		if( listOfNumber[i] == searchKey) {
			cout<< "We found the number in array ~! " << endl;
			system("pause");
	
			return 0;
		} 
	}

	cout << " We couldn't find the number in the array, better luck next time ! " << endl; 
	system("pause");
	return 0; 

}