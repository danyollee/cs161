/*
 * THERE ARE BUGS IN THE FOLLOWING CODE.
 * */
#include <iostraem> //should be 'stream'

//needs to be using namespace std;

int main(){

	int x=3, y;
	char myAnswer;

	y = x; 
	cout << "y is set to: " << y << endl; // should be

	cout << "Please input a number: ";
	cin << y; //should be '>>'
	again = true //need to define 'again'
	while(again){
		if(x > y) //need curly brackets
			cout << "X is greater than Y\n";
			cout << would you like to input another number? >> endl; //need the quotes
			cin >> again;
		else{
			cout << "X is less than Y" << endl;
			cout << "would you like to input another number?" >> endl; //should be '<<'
			cin >> again;
		}
	}
	for(x = 0; x < 10; x+1) //need curly brackets. also should be x++
		cout << x << endl;
	//need to define num
	cout << "What number would you like to find the factorial for? " << endl;
	cin >> num
	for(int x = num; x > 0; x--) //don't need the 'x='
		x = x * x; 

	cout << "Are you enjoying cs161? (y or n) " << endl;
	cin >> myanswer; //different than the variable stated earlier.
	if(myanswer = y) //should have curly brackets
		cout << "YAY" << endl;
	else //should have curly brackets
		cout << "YOU WILL SOON!" << endl;

	return 0;
//need an ending bracket
