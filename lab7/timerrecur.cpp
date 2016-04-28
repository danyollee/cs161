#include <iostream>
#include <sys/time.h>
#include <cstdlib>

using namespace std;

int get_n(int);
int fib(int);

int main(){
	int n;
	typedef struct timeval time;
	time stop, start;

	n=get_n(n);

	gettimeofday(&start, NULL);
	for(int i=0; i<n; i++){
		cout << fib(i) << endl;		
	}

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

int fib(int n){
	 
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	else
		return fib(n-1)+fib(n-2);
}