#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

/*
 * Name: is_pos_int(strin)
 * Description: 
 */
bool is_pos_int(string s){
	for(int i=0; i<s.length(); i++){
		if(s[i] < 48 || s[i] > 57)
			return false;
			}
		return true;
		}

int main(){

	cout << "This is a password generator." << endl;

	string password;

	srand(time(NULL));

	int length, let, letlen, letcombo, uplet, lowlet, spec, specperc, num, numperc;

	//string length, let, letlen, letcombo, uplet, lowlet, spec, specperc, num, numperc;

	cout << "How many characters/numbers do you want your password to be?: ";
	cin >> length;
	is_pos_int(string length);
	while(!is_pos_int(length)){
		cout << "Error, try again :";
		cin >> length;
	}

	cout << "How many letters do you want?: ";
	cin >> let;
	while(!is_pos_int(let)){
		cout << "Error, not valid. Try again: ";
		cin >> let;
	}
	
	if(let==0){
		letlen=0;
	}

	if(let>0){

		cout << "Do you want only uppercase(1), only lowecase(2), or a mix of uppercase and lowecase(3)?: ";
		cin >> letcombo;
		while(!is_pos_int(letcombo) && letcombo<=0 && letcombo>=4){
			cout << "Error, not valid. Try again: ";
			cin >> letcombo;
			}

		if(letcombo==1){
			int i = 0;
			char upper[i];
			for(i=0; i<let; i++){
				upper[i]=(rand()%26)+65;
				cout << upper[i] << endl;
			}
			for(int p=0; p<let; p++){
				password += upper[i];
			}
		}
		if(letcombo==2){
			int i = 0;
			char lower[i];
			for(i=0; i<let; i++){
				lower[i]=(rand()%26)+97;
				cout << lower[i] << endl;
			}
		}
		if(letcombo==3){
			cout << "You chose a mix of uppercase and lowercase." << endl;
			
			int upmix, lowmix;
			
			cout << "How many uppercase letters do you want?: ";
			cin >> upmix;
			cout << "How many lowercase letters do you want?: ";
			cin >> lowmix;
			while(upmix>0){
				int i = 0;
				char upper[i];
				for(i=0; i<upmix; i++){
					upper[i]=(rand()%26)+65;
					cout << upper[i] << endl;
				}
			}
		
			while(lowmix>0){
				int i = 0;
				char lower[i];
				for(i=0; i>lowmix; i++){
					lower[i]=(rand()%26)+97;
					cout << lower[i] << endl;
			}
			}
		}
	}

	if((length-let)>0){
	cout << "How many special characters do you want?: ";
	cin >> spec;
	while(!is_pos_int(spec)){
		cout << "Error, not valid. Try again: ";
		cin >> spec;
	}

	if(spec==0){
		specperc=0;
	}

	while(specperc>(length-let)){
		cout << "Error, amount of special characters greater than the length. Try again: ";
		cin >> specperc;
	}
		int i=0;
		char special[i];
		for(i=0; i<specperc; i++){
			special[i]=(rand()%15)+33;
			cout << special[i] << endl;
		}
	}

	int letspec = let+spec;
	if(letspec<length){
	cout << "How many numbers do you want in your password?: ";
	cin >> num;
	while(!is_pos_int(num)){
		cout << "Error, not valid. Try again: ";
		cin >> num;
	}
	}

	if(num==0){
		numperc=0;
	}

	if(num>length){
		cout << "Error. Amount of numbers is greater than the length of the password. Try again: ";
		cin >> numperc;
	}
	int i=0;
	int num[i];
	for(i=0; i<numperc; i++){
		num[i]=(rand()%48)+10;
		cout << num[i] << endl;
	}

	if(num==0){
		numperc=0;
	}


	cout << "Your password is " << password << endl;
}

