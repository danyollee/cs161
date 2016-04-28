#include<iostream>

using namespace std;

int main()
{

	int l;
	cout << "What is the length of your object?: " << endl;
	cin >> l;

	int w;
	cout << "What is the width of your object?: " << endl;
	cin >> w;

	int h;
	cout << "What is the height of your object?: " << endl;
	cin >> h;

	int area;
	area = l * w;

	int volume;
	volume = l * w * h;

	int calc;
	cout << "Would you like to find the area(1) or the volume(2)?: " << endl;
	cin >> calc;


	if (calc == 1) {
		cout << "The area of your object is " << area << " square feet." << endl;
	}

	else if (calc == 2) {
		cout << "The volume of your object is " << volume << " feet cubed." << endl;
	}

	return 0;
}
