/*
 * THERE ARE BUGS IN THE FOLLOWING CODE.
 * */
#include <iostream>

using namespace std;

int main(){

	int x=3, y;
	char myAnswer;

	y = x;
	cout << "y is set to: " << y << endl;

	cout << "Please input a number: ";
	cin >> y;
	bool again;
	again = true;

	while(again==true){
		if(x > y){
			cout << "X is greater than Y\n";
			cout << "would you like to input another number? " << endl;
			cin >> again;
		}
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number? y or n: " >> endl;
			cin >> again;
		}
	}
	for(x = 0; x < 10; x+1){
		cout << x << endl;
	}
	
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num
	for(int x = num; x > 0; x--)
		x = x * x;

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myAnswer;
	if(myanswer = y){
		cout << "YAY" << endl;
	}
	else{
		cout << "YOU WILL SOON!" << endl;
	}
	return 0;
}
