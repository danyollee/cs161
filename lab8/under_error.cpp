
#include <iostream>
using namespace std;

bool is_equal(char **str1, char **str2) {
	int i;
	for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++)
		if(str1[i]!=str2[i])
			return false;

		if(str1[i]!='\0' || str2[i]!='\0')
			return false;

		return true;
	}

		int main(){
			char *str1=NULL, *str2=NULL;
			str1=new char[256];
			str2=new char[256];

			cout << "enter string 1: ";
			cin >> str1;
			cout << "enter string 2: ";
			cin >> str2;
			cout << is_equal(&str1, &str2) << endl;

			return 0;
		}
