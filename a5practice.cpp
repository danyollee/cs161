#include <iostream>
#include <cstring>

using namespace std;

//prototypes
int user_choice(char*, int);
void get_input(char*, int);
void get_morse_input(char*, int);
int get_length_of_input(char*, int);
void translate_eng_to_morse(char*, int);
void vowel_check(char*, int);

int main(){
	char user_input[20];

	user_choice(user_input, 20);

	return 0;
}

int user_choice(char* user_input, int size){
	int choice_of_user;
	cout << "Welcome to the translator! Do you want to\n1. Translate from English to Morse Code?\n2. Translate from Morse Code to English?\n";
	cin >> choice_of_user;

	if(choice_of_user==1){
		get_input(user_input, 20);
	}
	if(choice_of_user==2){
		get_morse_input(user_input, 20);
	}
}

void get_input(char* user_input, int size){
	cout << "Enter a phrase you want to translate to Morse Code: ";
	cin.ignore();
	cin.getline(user_input, 20);

	translate_eng_to_morse(user_input, 20);
}

void translate_eng_to_morse(char* user_input, int size){
	//for(int i=0; i<4; i++){
		vowel_check(user_input, 20);
	//}
}

void vowel_check(char* user_input, int size){
	char a[]=".-   ";
	char e[]=".   ";
	char i[]="..   ";
	char o[]="---   ";
	char u[]="..-   ";

	cout<<a<<e<<i<<o<<u<<endl;
	/*for(int i=0; i<20; i++){
		if(user_input[i]=='a'){
			user_input[i]='.-   ';
		}
		if(user_input[i]=='e'){
			user_input[i]='.   ';
		}
		if(user_input[i]=='i'){
			user_input[i]='..   ';
		}
		if(user_input[i]=='o'){
			user_input[i]='---   ';
		}
		if(user_input[i]=='u'){
			user_input[i]='..-   ';
		}
	}*/
}

void get_morse_input(char* user_input, int size){
	cout << "Enter a morse code that you want to translate: ";
	cin.ignore();
	cin.getline(user_input, 20);
}