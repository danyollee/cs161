#include <iostream>

using namespace std;

int main(){

	int choice;
	cout << "Do you like vim? '1' for yes and '0' for no: ";
	cin >> choice;

	if(choice==0){
		cout << "You have vim!" << endl;
	}

	if(choice==1){
		cout << "You love vim!" << endl;
	}

}
