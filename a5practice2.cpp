#include <iostream>

using namespace std;

//prototypes
int welcome_screen(int, char*);
void get_eng_phase(char*);
int get_actual_length(char*, int);
void translate_Eng2morse(char*);
void letters_b_g_check(char*);
void letters_h_m_check(char*);
void letters_n_s_check(char*);
void letters_t_z_check(char*);
void check_for_space(char*);
void vowel_check(char*);

int main(){
	int choice;
	char user_input[20];

	choice=welcome_screen(choice, user_input);
	cout << user_input << endl;

	return 0;
}

int welcome_screen(int choice, char user_input[]){
	cout << "Welcome. Do you want to\n(1) Translate from English to Morse code?\n(2) Translate from Morse code to English\n";
	cin >> choice;

	if(choice==1){
		get_eng_phase(user_input);
	}
}

void get_eng_phase(char user_input[]){
	int actual_length;
	cout << "Enter a phrase in English that you want to translate: ";
	cin.ignore();
	cin.getline(user_input, 20);

	translate_Eng2morse(user_input);
}

void translate_Eng2morse(char user_input[]){
	letters_b_g_check(user_input);
	letters_h_m_check(user_input);
	letters_n_s_check(user_input);
	letters_t_z_check(user_input);
	check_for_space(user_input);
	vowel_check(user_input);
}

void letters_b_g_check(char user_input[]){
	for(int i=0; i<20; i++){
		if(user_input[i]=='b'){
			cout << "-...   ";
		}
		if(user_input[i]=='c'){
			cout << "-.-.   ";
		}
		if(user_input[i]=='d'){
			cout << "-..   ";
		}
		if(user_input[i]=='f'){
			cout << "..-.   ";
		}
		if(user_input[i]=='g'){
			cout << "--.   ";
		}
	}
}

void letters_h_m_check(char user_input[]){
	for(int i=0; i<20; i++){
		if(user_input[i]=='h'){
			cout << "....   ";
		}
		if(user_input[i]=='j'){
			cout << ".---   ";
		}
		if(user_input[i]=='k'){
			cout << "-.-   ";
		}
		if(user_input[i]=='l'){
			cout << ".-..   ";
		}
		if(user_input[i]=='m'){
			cout << "--";
		}
	}
}

void letters_n_s_check(char user_input[]){
	for(int i=0; i<20; i++){
		if(user_input[i]=='n'){
			cout << "-.   ";
		}
		if(user_input[i]=='p'){
			cout << ".--.   ";
		}
		if(user_input[i]=='q'){
			cout << "--.-   ";
		}
		if(user_input[i]=='r'){
			cout << ".-.   ";
		}
		if(user_input[i]=='s'){
			cout << "...   ";
		}
	}
}

void letters_t_z_check(char user_input[]){
	for(int i=0; i<30; i++){
		if(user_input[i]=='t'){
			cout << "-   ";
		}
		if(user_input[i]=='v'){
			cout << "...-   ";
		}
		if(user_input[i]=='w'){
			cout << ".--   ";
		}
		if(user_input[i]=='x'){
			cout << "-..-   ";
		}
		if(user_input[i]=='z'){
			cout << "--..   ";
		}
	}
}

void check_for_space(char user_input[]){
	for(int i=0; i<20; i++){
		if(user_input[i]==' '){
			cout << "       ";
		}
	}
}

void vowel_check(char user_input[]){
	for(int i=0; i<20; i++){
		if(user_input[i]=='a'){
			cout << ".-   ";
		}
		if(user_input[i]=='e'){
			cout << ".   ";
		}
		if(user_input[i]=='i'){
			cout << "..   ";
		}
		if(user_input[i]=='o'){
			cout << "---   ";
		}
		if(user_input[i]=='u'){
			cout << "..-   ";
		}
	}
}