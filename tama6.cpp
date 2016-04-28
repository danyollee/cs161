
#include <iostream> 

using namespace std;

bool inbetweenMorse(int i, char *morse) {
	if (morse[i] == ' ' && morse[i + 1] == ' ' && morse[i + 2] == ' ' && morse[i + 3] != ' ') return true;
	else return false;
}

bool spaceMorse(int i, char *morse) {
	if (morse[i] == ' ' && morse[i + 1] == ' ' && morse[i + 2] == ' '  && morse[i + 3] == ' ' 
		&& morse[i + 4] == ' ' && morse[i + 5] == ' ' && morse[i + 6] == ' ' && morse[i + 7] != ' ') return true;
	else return false;
}


int strlen(char* str) {
	int n = 0;
	for (int i = 0; str[i] != '\0'; i++) n++; 
	str[n + 1] = '\0';
	return n;
}

bool arrMatch(char * checker) {
	for (int i = 0; checker[i] != '\0'; i++) {
		if (checker[i] != 'x') return false;
	}
	return true;
}

void textToMorse(char* usrTxt, int len, char *alphabet, char morseAlphabet[][6]) {
	for (int i = 0; i < len; i++) {
		if (usrTxt[i] == ' ') cout << "       ";
		else for (int j = 0; j < 25; j++)
			if (usrTxt[i] == alphabet[j]) cout << morseAlphabet[j] << "   ";
	}
}

bool strLenComparison(char* str1, char str2[][6], int j) {
	int n = 0, m = 0;
	for (int i = 0; str1[i] != '\0'; i++) n++;
	for (int i = 0; str2[j][i] != '\0'; i++) m++;
	if (n != m) return false;
	else return true;
}

void printMorse(char* temp, char morseAlphabet[][6], char* alphabet) {
	//LINES 49-57: creating a checker to see if all of the characters in the user's morse is matching with the morseAlphabet's
	char * checker = new char[0]; 
	for (int i = 0; morseAlphabet[i][0] != '\0'; i++) {
		bool tempDone = false, alphaDone = false; int checkerEnd;
		for (int l = 0; temp[l] != '\0'; l++) {
			checker[l] = 'o';
			checkerEnd = l;
		} 
		checker[checkerEnd + 1] = '\0';
		if (strLenComparison(temp, morseAlphabet, i)) { //if the user's individual morse letter is matching with the alphabet's, then check to see if the contents are correct
			for (int j = 0; (tempDone == false) && (alphaDone == false); j++) {
				if (temp[j] == morseAlphabet[i][j]) {
					checker[j] = 'x'; //if the individual character is correct ('.' or '-'), then mark 'x' in the checker
				}
				else
					break; //if it's not correct, then break out of the 'for' loop and go to the next index in the alphabet to see if they match
				if (temp[j] == '\0') tempDone = true;
				if (morseAlphabet[i][j] == '\0') alphaDone = true;
			}
			if (arrMatch(checker)) { //once all of the indexes in 'checker' is marked 'x', then print out the letter correlated to this position (i)
				cout << alphabet[i];
				break; //break and then go to the next morse letter
			}
		}
	} 
}

void morseToText(char* usrMrs, int len, char *alphabet, char morseAlphabet[][6]) {
	int i = 0;
	while (i != len) {
		char * temp = new char[256];
		if (spaceMorse(i, usrMrs)) { //spaceMorse checks to see if the user entered 7 spaces
			cout << " "; //print out space if the user entered space
			i += 7; //i increments 7 indexes to the letter
		}
		else if (inbetweenMorse(i, usrMrs)) { //inbetweenMorse checks to see if the user entered 3 spaces to differentiate the morse letters
			i += 3; //i increments 3 indexes to the letter
		}
		int k = 0;
		while (usrMrs[i] != ' ' && i != len)
			temp[k++] = usrMrs[i++]; //for all of the characters in that section that doesn't have any spaces, import the '-' and '.'s into this temporary array. This array contains that individual morse letter
		temp[k] = '\0'; 
		printMorse(temp, morseAlphabet, alphabet); //printMorse finds the morseAlphabet that is the same as what the user has entered.
		delete[] temp;
		}
	cout << endl;
}

void startConvert(int choice, char *alphabet, char morseAlphabet[][6]) {
	int n;
	if (choice == 1) {
		char * usrTxt = new char[0];
		cout << "Enter Text Message: ";
		cin.getline(usrTxt, 256, '\n');
		n = strlen(usrTxt);
		textToMorse(usrTxt, n, alphabet, morseAlphabet);
		delete[] usrTxt;
	}
	else {
		char * usrMrs = new char[0];
		cout << "Enter Morse Code: ";
		cin.getline(usrMrs, 256, '\n');
		n = strlen(usrMrs);
		morseToText(usrMrs, n, alphabet, morseAlphabet);
		delete[] usrMrs;
	}
}

int main() {
	int choice; 
	char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
	char morseAlphabet[26][6] = { ".-", "-...", "-.-.", "-..", ".", "..-.", 
								  "--.", "....", "..", ".---", "-.-", ".-..", 
								  "--", "-.", "---", ".--.", "--.-", ".-.", 
								  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
	cout << "Do you want to translate text to Morse code (1) or translate Morse code to text (2)? ";
	cin >> choice;
	cin.ignore();
	startConvert(choice, alphabet, morseAlphabet);
}