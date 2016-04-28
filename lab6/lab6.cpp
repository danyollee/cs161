#include <iostream>
#include <string>

using namespace std;

//prototypes
void get_sentence(string*);
bool determine_palindrome(string);
void get_search_replace_strings(string*, string*, string*);
void new_string(string*);

int main(){
	int choice;
	string startingString="start", searchString="start", replaceString="start";
	
	get_sentence(&startingString);
	
	cout << "Do you want to determine if it's a palindrome(1), if you want to replace the string(2), enter a new string(3), or quit(0)?: ";
	cin >> choice;
	if(choice==1){
		determine_palindrome(startingString);
		if(determine_palindrome(startingString)==true){
			cout << "The string is a palindrome!" << endl;
		}
		if(determine_palindrome(startingString)==false){
			cout << "The string is not a palindrome :(" << endl;
		}
	}
	if(choice==2){
		get_search_replace_strings(&startingString, &searchString, &replaceString);
	}
	if(choice==3){
		new_string(&startingString);
	}

	return 0;
}

//definitions

void get_sentence(string *s){
	cout << "Enter a sting to start with: " << endl;
	getline(cin, *s);
}

bool determine_palindrome(string s){
	int a, z;
	a=0;
	z=(s.length())-1;
	while(a<z){
		if(s.at(a)!=s.at(z)){
			return false;
		}
		return true;
		a++, z--;
	}
}

void get_search_replace_strings(string *startingString, string *searchString, string *replaceString){
	cout << "Enter a string that you want to search for: ";
	cin >> *searchString;
	cout << "Enter a string that you want to replace with: ";
	cin >> *replaceString;
}

void new_string(string *s){
	cout << "Enter a new string: " << endl;
	cin >> *s;
}