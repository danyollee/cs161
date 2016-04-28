#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main(){	

	cout << "This is a password generator." << endl;

	srand(time(NULL));

	int length, let, letlen, letcombo, uplet, lowlet, spec, specperc, num, numperc;

	cout << "How many characters/numbers do you want your password to be?: ";
	cin >> length;

	cout << "Do you want letters in your password? '1' for yes and '0' for no: ";
	cout << "How many letters do you want?: ";
	cin >> let;
	while(let>=2 || let <=0){
		cout << "Error. Not a valid input. Try again: ";
		cin >> let;
	}
	
	if(let==0){
		letlen=0;
	}
	if(let==1){
		cout << "How many letters do you want?: ";
		cin >> letlen;
		if(letlen>length){
			cout << "Error, amount of letters is greater than the length. Try again: ";
			cin >> letlen;
		}

	if(let>0){

		cout << "Do you want only uppercase(1), only lowecase(2), or a mix of uppercase and lowecase(3)?: ";
		cin >> letcombo;

		while(letcombo<=0 || letcombo>=4){
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
	//cout << "Do you want special characters in your password? '1' for yes and '0' for no: ";
	cout << "How many special characters do you want?: ";
	cin >> spec;
	}

	if(spec==0){
		specperc=0;
	}
	if(spec==1){

	if(specperc>(length-let)){
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
	if(spec==0){
		specperc=0;
	}

	int letspec = let+spec;
	if(letspec<length){
	//cout << "Do you want numbers in your password? '1' for yes and '0' for no: ";
	cout << "How many numbers do you want in your password?: ";
	cin >> num;
	}

	if(num==0){
		numperc=0;
	}

	if(num==1){
		//cout << "How many numbers do you want?: ";
		//cin >> numperc;
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
	}
	if(num==0){
		numperc=0;
	}

	
	cout << "Combine all the printed values for you password!" << endl;
}
}
