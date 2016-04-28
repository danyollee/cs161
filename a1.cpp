#include<iostream>
#include<cmath>
#include<math.h>
#include<climits>

#define PI 3.14


using namespace std;


int main(){
	
	cout << "Part 1" << endl;
	cout << endl;	

	cout << "The answer of cos(2π/3) is " << cos(( 2 * PI ) / 3 ) << endl;
	cout << "The answer of 2sin(2π/3) is " << ( 2 * sin ( 2 * PI / 3 ) ) << endl;
	cout << "The answer of tan(-3π/4) is " << ( tan ( -3 * PI ) / 4 ) << endl;
	cout << "The answer of log base10 of 55 is " << ( log10 ( 55 ) ) << endl;
	cout << "The natural log of 60 is " << ( log ( 60 ) ) << endl;

	cout << "The log base 2 of 15 can be solved by log(15)/log(2). Which is " << ( ( log ( 15 ) ) / ( log ( 2 ) ) ) << endl;
	cout << "The log base 4 of 40 can be solved by log(40)/log(4). Which is " << ( ( log ( 40 ) ) / ( log ( 4 ) ) ) << endl;

	int x1, x2 , x3;
	x1 = 1;
	x2 = 10;
	x3 = 100;
	
	cout << "3 to the power of sin(1) is " << pow ( 3, ( sin ( x1 ) ) ) << endl;
	cout << "3 to the power of sin(10) is  " << pow ( 3, ( sin ( x2 ) ) ) << endl;
	cout << "3 to the power of sin(100) is " << pow ( 3, ( sin( x3 ) ) ) << endl;
	cout << "Log base 2 of 1 squared + 1 is " << log ( pow ( x1 , 2 ) + 1 ) / log ( 2 ) << endl;
	cout << "Log base 2 of 10 squared + 1 is " << log ( pow ( x2 , 2 ) + 1 ) / log ( 2 ) << endl;
	cout << "Log base 2 of 100 squared + 1 is " << log ( pow ( x3 , 2 ) + 1 ) / log ( 2 ) << endl;
	
	cout << "Part 2" << endl;
	cout << endl;

	double intmin, intmax, uintmax, longmin, longmax, ulongmax, llongmin, llongmax, ullongmax;
	intmin = ( pow ( -2, 15 ) + 1 );
	intmax = ( pow ( 2, 15 ) - 1 );
	uintmax = ( pow ( 2, 16 ) - 1 );
	longmin = ( pow ( -2, 31 ) + 1 );
	longmax = ( pow ( 2, 31 ) - 1 );
	ulongmax = ( pow ( 2, 32 ) - 1 );
	llongmin = ( pow ( -2, 63 ) + 1 );
	llongmax = ( pow ( 2, 63 ) - 1 );
	ullongmax = ( pow ( 2, 64 ) -1 );
	cout << "The minimum value for an integer is " << intmin << endl;
	cout << "The maximum value for an integer is " << intmax << endl;
	cout << "The minimum value for an unsigned integer is " << uintmax << ". The nature of unsigned integers only allows it to be positive. " << endl;
	cout << "The minimum value for a long int is " << longmin << endl;
	cout << "The maximum value for a long int is " << longmax << endl;
	cout << "The max value for an unsigned long int is " << ulongmax << endl;
	cout << "The minimum value for a long long int is " << llongmin << endl;
	cout << "The max value for a long long int is " << llongmax << endl;
	cout << "The max value for an unsinged long long int is " << ullongmax << endl;

	cout << endl;

	cout << "The size of the minimum integer is " << pow ( 2, sizeof(intmin) + 1 ) << " bytes " << endl;
	cout << "The size of the maximum integer is " << pow ( 2, sizeof(intmax) -1 ) << " bytes " << endl;
	cout << "The size of an unsigned integer is " << pow ( 2, sizeof(uintmax) - 1 ) << " bytes " << endl;
	cout << "The size of a minimum long int is " << pow ( 2,  sizeof(longmin) + 1 ) << " bytes " << endl;
	cout << "The size of a maximum long int is " << pow ( 2, sizeof(longmax) - 1 ) << " bytes " << endl;
	cout << "The size of an unsigned long int is " << pow ( 2, sizeof(ulongmax) - 1 ) << " bytes " << endl;
	cout << "The size of a minimum long long int is " << pow ( 2, sizeof(llongmin) + 1 ) << " bytes " << endl;
	cout << "The size of a maximim long long int is " << pow ( 2, sizeof(llongmax) - 1 ) << " bytes " << endl;
	cout << "The size of an unsinged long long int is " << pow ( 2, sizeof(ullongmax) - 1 ) << " bytes " << endl;

	return 0;
}
