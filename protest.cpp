#include <iostream>
#include <cstdlib>

using namespace std;

void fill_in_arrays(int[], int[]);
void compare(int[], int[]);

int main(){
	srand(time(NULL));
	int array1[5], array2[5];

	fill_in_arrays(array1, array2);
	compare(array1, array2);
	
	return 0;
}

void fill_in_arrays(int array1[], int array2[]){
	for(int i=0; i<5; i++){
		array1[i]=(rand()%6);
		array2[i]=(rand()%6);
	}
}

void compare(int array1[], int array2[]){
	int counter=0;
	for(int i=0; i<5; i++){
		cout << "Element " << i << " of array 1 is " << array1[i] << ", and " << array2[i] << " for array 2. ";
	}
	for(int i=0; i<5; i++){
		if(array1[i]==array2[i]){
			counter++;
		}
	}
	cout << "There are " << counter << " matching elements." << endl;
}