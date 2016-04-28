#include <iostream>
#include <cstdlib>

using namespace std;

//prototypes
int welcome_screen(int, char*);
void get_eng_phrase(char*);
int get_actual_length(char*, int);
void translate_Eng2morse(char*, int);
bool is_constanant(char);
void check_for_space(char*);
void vowel_check(char);
void constanants(char);
void get_morse_phrase(char*);
int get_morse_length(char*, int);
void copy_morse_phrase(char*, int);
void start_translation_morse_english(char [][7], int);
int morse_counter(char [][7], char*, int, int);
void morse_copy_over(char morse_letter_phrase[][7], char dyn[], int i, int length_counter);
int str_compare(char*, int, int, char*);
void morse_translation_constanats(char*, int);
void is_vowel(char*, int);

int main(){
	int choice;
	char user_input[255];

	choice=welcome_screen(choice, user_input);

	return 0;
}

int welcome_screen(int choice, char user_input[]){
	cout << "Welcome. Do you want to\n(1) Translate from English to Morse code?\n(2) Translate from Morse code to English\n";
	cin >> choice;

	if(choice==1){
		get_eng_phrase(user_input);
	}
	if(choice==2){
		get_morse_phrase(user_input);
	}
}

void get_eng_phrase(char user_input[]){
	int actual_length;
	cout << "Enter a phrase in English that you want to translate: ";
	cin.ignore();
	cin.get(user_input, 255);

	actual_length=get_actual_length(user_input, actual_length);

	translate_Eng2morse(user_input, actual_length);
}

void translate_Eng2morse(char user_input[], int length){
	bool consty;
	char letter;
	cout << "\"" << user_input << "\"" << " in Morse code is ";
	for(int i=0; i<length; i++){
		letter=user_input[i];
		consty=is_constanant(letter);
		if(consty==true){
			constanants(letter);
		}
		if(consty==false){
			vowel_check(letter);
		}
		if(letter==' '){
			cout << "       ";
		}
	} cout << endl;
}

bool is_constanant(char letter){
	if(letter=='b' || letter=='c' || letter=='d' || letter=='f' || letter=='g' || letter=='h' || letter=='j' || letter=='k' || letter=='l' || letter=='m' || letter=='n' || letter=='p' || letter=='q' || letter=='r' || letter=='s' || letter=='t' || letter=='v' || letter=='w' || letter=='x' || letter=='z'){
		return true;
	}
	else
		return false;
}

int get_actual_length(char* user_input, int length){
	int i=0;
	while(user_input[i]!='\0'){
		length++;
		i++;
	}
	return length;
}

void constanants(char letter){
	if(letter=='b') cout << "-...   ";
	if(letter=='c') cout << "-.-.   ";
	if(letter=='d') cout << "-..   ";
	if(letter=='f') cout << "..-.   ";
	if(letter=='g') cout << "--.   ";
	if(letter=='h') cout << "....   ";
	if(letter=='j') cout << ".---   ";
	if(letter=='k') cout << "-.-   ";
	if(letter=='l') cout << ".-..   ";
	if(letter=='m') cout << "--   ";
	if(letter=='n') cout << "-.   ";
	if(letter=='p') cout << ".--.   ";
	if(letter=='q') cout << "--.-   ";
	if(letter=='r') cout << ".-.   ";
	if(letter=='s') cout << "...   ";
	if(letter=='t') cout << "-   ";
	if(letter=='v') cout << "...-   ";
	if(letter=='w') cout << ".--   ";
	if(letter=='x') cout << "-..-   ";
	if(letter=='z') cout << "--..   ";
}


void check_for_space(char user_input[]){
	for(int i=0; i<255; i++){
		if(user_input[i]==' '){
			cout << "       ";
		}
	}
}

void vowel_check(char letter){
	if(letter=='a') cout << ".-   ";
	if(letter=='e') cout << ".   ";
	if(letter=='i') cout << "..   ";
	if(letter=='o') cout << "---   ";
	if(letter=='u') cout << "..-   ";
	if(letter=='y') cout << "-.--";
}

void get_morse_phrase(char user_input[]){
	int actual_length;
	cout << "Here is the Morse code alphabet. \na= .-   f= ..-.   k= -.-   p= .--.   u= ..-   z= --..\nb= -... g= --.    l= .-..  q= --.-   v= ...-\nc= -.-. h= ....   m= --    r= .-.    w= .--\nd= -..  i= ..     n= -.    s= ...    x= -..-\ne= .    j= .---   o= ---   t= -      y= -.--\nEnter a Morse code phrase that you want to translate to English: ";
	cin.ignore();
	cin.get(user_input, 255);
	actual_length=get_morse_length(user_input, actual_length);
	copy_morse_phrase(user_input, actual_length);
}

int get_morse_length(char* user_input, int length){
	int i=0;
	while(user_input[i]!='\0'){
		length++;
		i++;
	}
	return length;
}

void copy_morse_phrase(char user_input[], int actual_length){
	char morse_phrase_copy[255], morse_letter_phrase[255][7];
	int how_many_arrays=1, i=0, j=0, k=0;
	while(i<actual_length){
		if(user_input[i] != ' '){
			morse_letter_phrase[j][k]=user_input[i];
			k++;
		} if(user_input[i]==' '){
			j++;
			how_many_arrays=how_many_arrays+1;
			k=0;
		} i++;
	}
	start_translation_morse_english(morse_letter_phrase, how_many_arrays);
}

void start_translation_morse_english(char morse_letter_phrase[][7], int how_many_arrays){
	int volly;
	char morse_copy[7];
	int length_counter=0;

	for(int i=0; i<how_many_arrays; i++){
		length_counter=morse_counter(morse_letter_phrase, morse_copy, i, length_counter);
		char *dyn = new char [length_counter];
		morse_copy_over(morse_letter_phrase, dyn, i, length_counter);
		is_vowel(dyn, length_counter);
		morse_translation_constanats(dyn, length_counter);
		delete [] dyn;
		length_counter=0;
	}
}

int morse_counter(char morse_letter_phrase[][7], char morse_copy[], int i, int length_counter){
	for(int k=0; k<7; k++){
		if(morse_letter_phrase[i][k]=='.' || morse_letter_phrase[i][k]=='-'){
			morse_copy[k]=morse_letter_phrase[i][k];
			length_counter++;
		}
	}
	return length_counter;
}

void morse_copy_over(char morse_letter_phrase[][7], char dyn[], int i, int length_counter){
	for(int k=0; k<length_counter; k++){
		dyn[k]=morse_letter_phrase[i][k];
	}
}

void is_vowel(char dyn[], int length_counter){
	char a[3]=".-", e[2]=".", i[3]="..", o[4]="---", u[4]="..-", y[5]="-.--";

	if(str_compare(dyn, 2, length_counter, a) == 1) cout << "a ";
	if(str_compare(dyn, 1, length_counter, e) == 1) cout << "e ";
	if(str_compare(dyn, 2, length_counter, i) == 1) cout << "i ";
	if(str_compare(dyn, 3, length_counter, o) == 1) cout << "o ";
	if(str_compare(dyn, 3, length_counter, u) == 1) cout << "u ";
	if(str_compare(dyn, 4, length_counter, y) == 1) cout << "y ";
}

int str_compare(char dyn[], int len, int length_counter, char vowel[]){
	if(len>length_counter){
		length_counter = len;
	}
	for(int i = 0; i < length_counter; i++){
		if(dyn[i] != vowel[i]){
			return 0;
		}
	}
	return 1;
}

void morse_translation_constanats(char dyn[], int length_counter){
	char b[5]="-...", c[5]="-.-.", d[4]="-..", f[5]="..-.", g[4]="--.", h[5]="....", j[5]=".---", k[4]="-.-", l[5]=".-..", m[3]="--", n[3]="-.", p[5]=".--.", q[5]="--.-", r[4]=".-.", s[4]="...", t[2]="-", v[5]="...-", w[4]=".--", x[5]="-..-", z[5]="--..";

	if(str_compare(dyn, 5, length_counter, b) == 1) cout << "b ";
	if(str_compare(dyn, 5, length_counter, c) == 1) cout << "c ";
	if(str_compare(dyn, 4, length_counter, d) == 1) cout << "d ";
	if(str_compare(dyn, 5, length_counter, f) == 1) cout << "f ";
	if(str_compare(dyn, 4, length_counter, g) == 1) cout << "g ";
	if(str_compare(dyn, 5, length_counter, h) == 1) cout << "h ";
	if(str_compare(dyn, 5, length_counter, j) == 1) cout << "j ";
	if(str_compare(dyn, 4, length_counter, k) == 1) cout << "k ";
	if(str_compare(dyn, 5, length_counter, l) == 1) cout << "l ";
	if(str_compare(dyn, 3, length_counter, m) == 1) cout << "m ";
	if(str_compare(dyn, 3, length_counter, n) == 1) cout << "n ";
	if(str_compare(dyn, 5, length_counter, p) == 1) cout << "p ";
	if(str_compare(dyn, 5, length_counter, q) == 1) cout << "q ";
	if(str_compare(dyn, 4, length_counter, r) == 1) cout << "r ";
	if(str_compare(dyn, 4, length_counter, s) == 1) cout << "s ";
	if(str_compare(dyn, 2, length_counter, t) == 1) cout << "t ";
	if(str_compare(dyn, 5, length_counter, v) == 1) cout << "v ";
	if(str_compare(dyn, 4, length_counter, w) == 1) cout << "w ";
	if(str_compare(dyn, 5, length_counter, x) == 1) cout << "x ";
	if(str_compare(dyn, 5, length_counter, z) == 1) cout << "z ";

}