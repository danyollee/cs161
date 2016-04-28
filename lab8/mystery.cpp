//Author: Jennifer Parham-Mocello
//Date: 2/20/16
//Description: For you to determine as Lab #8
#include <iostream>
#include <cstring>

using namespace std;

int main(){
	char x[10]="23489", y[10]="99";
	int *z;
	int c=0;
	int n=strlen(x);
	int n2=strlen(y);
	z = new int[n+1];

	if(n>=n2) {

	for(int i=1; i<=n2;i++) {
		if((x[n-i]-48)+(y[n2-i]-48)>=10) {
			z[n+1-i]=((x[n-i]-48)+(y[n2-i]-48)+c)%10;
			c=1;
		}
	else {
		z[n+1-i]=(x[n-i]-48)+(y[n2-i]-48)+c;
		c=0;
		if(z[n+1-i]>=10) {
			z[n+1-i]%=10;
			c = 1;
			}
		}
	}
	if(n==n2) {
		z[0]=c;
		}
	else {
		z[n-n2]=(x[n-n2-1]-48)+c;
		c=0;
		if(z[n-n2]>=10) {
			z[n-n2]%=10;
			c = 1;
			}
	for(int i=1; i<n-n2; i++) {
		z[n-n2-i]=(x[n-n2-1-i]-48)+c;
		c=0;
		}
		z[0]+=c;
		}
	for(int i=0; i<n+1; i++)
		cout << z[i] << endl;
		}
	}