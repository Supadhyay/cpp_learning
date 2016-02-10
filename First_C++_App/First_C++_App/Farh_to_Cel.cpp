#include <iostream>
using namespace std;


int getIntegerLimitValue () {
	int limitValue;
	cin >> limitValue;

	while (cin.fail()) {
		cout << "You entered the wrong type, the limits can only be intigers !" << endl;
		cin.clear();
		//Don't know what this line means, find out ? 
		cin.ignore(std::numeric_limits<int>::max(),'\n');
		cout << "Please enter and integer : ";
		cin >> limitValue ;

	}
	return limitValue;
}

int main() {
	int lower_limit = 0, upper_limit = 0 ;
	
	cout << " Enter the lower Limit for the calc :" ;
	lower_limit = getIntegerLimitValue(); 
	while (lower_limit >= upper_limit ) {
		cout << " Enter the upper Limit for the calc (make sure it is greater than the lower limit):" ;
		upper_limit = getIntegerLimitValue(); 
	}
	cout << " the values are : " << lower_limit << " " << upper_limit << endl;

	for(int i = lower_limit ; i <= upper_limit ; i ++ ) { 
		cout << i << " Celecious ==> " << (i* 9/5) + 32 << " Farhenites" << endl ; 
	} 

	system ("pause");

	return 0;

}
