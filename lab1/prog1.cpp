#include<iostream>
using namespace std;

int main(){
	int var1;
	var1 = 10;
	cout << "The first number is " << var1 << "." << endl;
	
	int var2;
	var2 = 2;
	cout << "The second number is " << var2 << "." << endl;

	cout << "Adding these makes " << var1+var2 << endl;
	cout << "Subracting " << var2 << " from " << var1 << " is " << var1-var2 << endl;
	cout << "Multiplying " << var1 << " and " << var2 << " together equals " << var1*var2 << endl;
	cout << "Dividing " << var1 << " by " << var2 << " is " << var1/var2 << endl;
	return 0;
}
