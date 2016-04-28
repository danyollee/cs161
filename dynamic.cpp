#include <iostream>

using namespace std;

int main(){
	int size, *array;
	cout << "Enter the amount of elements: ";
	cin >> size;

	array=new int[size];
	for(int i=0; i<size; i++){
		array[i]=1;
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}