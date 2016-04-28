#include <iostream>

using namespace std;

void reference(int&);

int main(){
	int yolo=69;

	cout << "The value of 'yolo' is " << yolo << "." << endl;

	reference(yolo);

	cout << "The new value of 'yolo' is " << yolo << endl;

	return 0;
}

void reference(int& yolo){
	cout << "Enter a new value for 'yolo': ";
	cin >> yolo;
}
