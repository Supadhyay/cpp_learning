#include <iostream>
#include <vector>
using namespace std;

//ToDo : Find out why use int vs void
// Do it for Arrays, trees, LL, vectors, dyn Arrays, graphs

int main(){
	
	int sizeOfIntVector = 10;
	int searchKey;
	vector <int> vectorOfNumbers(sizeOfIntVector);

	cout << "Creating Vecotr as an Array and printing the elements : " << endl ; 
	for(int i=0 ; i< sizeOfIntVector; ++i){
		vectorOfNumbers[i] = i ;
	}

	for(int i=0 ; i< sizeOfIntVector; ++i){
		cout << vectorOfNumbers[i] << endl ;
	}

	cout << endl << endl << "Creating Vecotr using pushback and printing the elements using iterator (appending to the same vector) : " << endl << endl<< endl ; 

	vector <int>::const_iterator iter;

	for(int i= 0 ; i < sizeOfIntVector; ++i){
		vectorOfNumbers.push_back(i * 20) ;
	}

	cout << "Updated Capacity : " << vectorOfNumbers.capacity() << endl << "Updaed Size : " << vectorOfNumbers.size() << endl << endl;		

	vectorOfNumbers.resize(20);

	cout << "New Capacity(after using resize) : " << vectorOfNumbers.capacity() << endl << "New Size (after using resize): " << vectorOfNumbers.size() << endl << endl;		

	for(iter = vectorOfNumbers.begin() ; iter != vectorOfNumbers.end(); ++iter){
		cout << *iter << endl ;
	}

	cout << endl << "Enter the value to search : " ;
	cin >> searchKey ;

	for(iter = vectorOfNumbers.begin() ; iter != vectorOfNumbers.end(); ++iter){
		if ( *iter == searchKey) {
			cout << "Found the element at : " << iter - vectorOfNumbers.begin() << endl;
			break; 
		}
	}

	system("pause");
	return 0; 

}