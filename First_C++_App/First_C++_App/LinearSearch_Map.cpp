#include <iostream>
#include <string>
#include <map>
using namespace std;

//ToDo : Find out why use int vs void
// Do it for Arrays, trees, LL, vectors, dyn Arrays, graphs

int main(){
	
	string searchKey ; 

	map<string, int> mapOfInts ; 

	mapOfInts.insert(make_pair("Mon" , 1));
	mapOfInts.insert(make_pair("Tue" , 2));
	mapOfInts.insert(make_pair("Wed" , 3));
	mapOfInts.insert(make_pair("Thu" , 4));
	mapOfInts.insert(make_pair("Fri" , 5));
	mapOfInts.insert(make_pair("Sat" , 6));
	mapOfInts.insert(make_pair("Sun" , 7));

	map<string, int>::iterator it = mapOfInts.begin();

	cout << "Key value pairs for newly created map" << endl; 

	while(it != mapOfInts.end()) {
		cout << " Key : " << it->first << " --- > value : " << it->second << endl; 
		it++; 
	}

	cout << "Enter the day you want to find : " ; 
	cin >> searchKey ; 

	auto searchResult = mapOfInts.find(searchKey); 
	if ( searchResult != mapOfInts.end()) {
		cout << endl << "Search key found, key value: " << searchResult->second << endl << endl; 
	} else {
		cout << endl <<  "Couldn't find the key in the map"; 
	} 

	 

	system("pause");
	return 0; 

}