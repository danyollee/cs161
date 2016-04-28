#include<iostream>
#include<cmath>
using namespace std;

#define PI 3.14

int main(){

	int r;
	cout << "What is the radius of your circle in inches?: ";
	cin >> r;

	int area;
	area = PI * ( pow ( r , 2 ));

	cout << "The area of your circle is " << area << " inches squared." << endl;
	
	return 0;
}
