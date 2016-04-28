#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

int get_n(int);
void fib_iter(int);

int main(){
	int n;
	typedef struct timeval time;
	time stop, start;

	n=get_n(n);

	gettimeofday(&start, NULL);
	fib_iter(n);

	gettimeofday(&stop, NULL);

	if(stop.tv_sec>start.tv_sec)
		cout << "Seconds: " << stop.tv_sec-start.tv_sec << endl;
	else
		cout << "Micro: " << stop.tv_usec-start.tv_usec << endl;

	return 0;
}

int get_n(int n){
	cout << "How many times do you want to go?: ";
	cin >> n;
	return(n);
}

void fib_iter(int n){
	int fib, zeroth=0, first=1;

	if(n==1)
		cout << "Fib is " << zeroth << endl;
	if(n==2)
		cout << "Fib is " << first << endl;
	for(int i=0; i<n; i++){
		fib=zeroth;
		cout << fib << endl;
		fib=zeroth+first;
		zeroth=first;
		first=fib;
	}
}