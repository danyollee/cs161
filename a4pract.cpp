/*********************************************************************
 ** Program Filename: a4pract.cpp
 ** Author: Daniel Lee
 ** Date: 2.17.2016
 ** Description: Runs a wheel of fortune game.
 ** Input: None.
 ** Output: None.
 *********************************************************************/ 

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <sstream>

using namespace std;

//prototypes

void welcome_screen(); //prompts the player and welcomes them to the game. 
int player_count(int); //gets the amount of players in the game.
int round_amount(int);
void secret_phrase(string*); //takes the secret phrase of the game.
string phrase_dashes(string, string);
void print_dashes(string, string);
int player_choice(int, int, string, string*); //
int wheel_spin();
int choose_char(string, string**, int, int);
int check_guess(char, string, string***, int);
bool amount_correct(int, bool);
int round_money(int, int, int, int, int*, int*, int*);
char buy_vowel(string, string**, int, int, int, int*, int*, int*);
int money_bank(int, int, int**, int**, int**);
bool check_solved(string, string**, bool);
bool check_money(int, int*, int*, int*, bool);
string enter_guess(string, string**, string);
void check_winner(int, int, int);
int option_3_check(string, string***, string);

/*********************************************************************
 ** Function: main
 ** Description: Runs the entire program.
 ** Parameters: None. 
 ** Pre-Conditions: None. 
 ** Post-Conditions: None. 
 *********************************************************************/ 
int main(){
	int i, rounds;
	int players;

	string secretPhrase, phraseDashes;

	srand(time(NULL));

	welcome_screen();
	players=player_count(players);
	i=players;
	secret_phrase(&secretPhrase);
	phraseDashes=phrase_dashes(phraseDashes, secretPhrase);
	rounds=round_amount(rounds);
	player_choice(i, rounds, secretPhrase, &phraseDashes);

	return 0;
}

/*********************************************************************
 ** Function: welcome_screen
 ** Description: Just prints out a phrase. Doesn't really do anything.
 ** Parameters: None. 
 ** Pre-Conditions: None. 
 ** Post-Conditions: None.
 *********************************************************************/ 
void welcome_screen(){
	cout << "Welcome to Wheel of Fortune!" << endl;
}

/*********************************************************************
 ** Function: player_count
 ** Description: Takes in input on how many players there are.
 ** Parameters: players. from main.
 ** Pre-Conditions: None.
 ** Post-Conditions: Returns an int.
 *********************************************************************/ 
int player_count(int players){
	cout << "How many players do you have? (You can only have between 1-3): ";
	cin >> players;
	while(players<=0 || players>=4){
		cout << "Error, not a valid input. Try again: ";
		cin >> players;
	}
	return(players);
}

/*********************************************************************
 ** Function: round_amount
 ** Description: Takes in input on how many rounds the user wants to play.
 ** Parameters: r. from main.
 ** Pre-Conditions: None.
 ** Post-Conditions: Returns an int.
 *********************************************************************/ 
int round_amount(int r){
	cout << "How many rounds do you want to play?: ";
	cin >> r;
	return(r);
}

/*********************************************************************
 ** Function: secret_phrase
 ** Description: Takes in input from the user on what the phrase should be.
 ** Parameters: secretPhrase. As a pointer from main.
 ** Pre-Conditions: None.
 ** Post-Conditions: Returns a string pointer.
 *********************************************************************/ 
void secret_phrase(string* secretPhrase){
	cout << "What do you want your secret phrase to be?: ";
	cin.ignore();
	getline(cin, *secretPhrase);
}

/*********************************************************************
 ** Function: phrase_dashes
 ** Description: Converts the string into a hidden message.
 ** Parameters: secretPhrase, and phraseDashes. From main.
 ** Pre-Conditions: secretPhrase had to be a string.
 ** Post-Conditions: Returns a duplicate string.
 *********************************************************************/ 
string phrase_dashes(string phraseDashes, string secretPhrase){
	phraseDashes=secretPhrase;
	for(int a=0; a<secretPhrase.length(); a++){
		if(secretPhrase.at(a)!=' '){
			phraseDashes.at(a)='_';
		}else{
		phraseDashes.at(a)=' ';
		}
	}
	return(phraseDashes);
}

/*********************************************************************
 ** Function: player_choice
 ** Description: Essentially runs the game.
 ** Parameters: player amount, round amount, the secretphrase and phrasedashes.
 ** Pre-Conditions: Player amount and round amount had to be ints. the rest, strings and string pointers.
 ** Post-Conditions: Runs correctly.
 *********************************************************************/ 
int player_choice(int i, int rounds, string secretPhrase, string* phraseDashes){
	int a=1, player_choices, spin, correct_amount, earnings, moneybank1=0, moneybank2=0, moneybank3=0;
	bool solved=false, enough=true;
	for(int b=0; b<rounds; b++){
		while(solved==false){
			for(int a=1; a<=i; a++){
					spin=wheel_spin();
					cout << "\nPlayer " << a << ", you spun " << spin << ".\nPlayer 1 has $" << moneybank1 << ", player 2 has $" << moneybank2 << ", player 3 has $" << moneybank3 << ".\nThe secret phrase is " << *phraseDashes << "\nDo you want to \n(1) guess a letter?\n(2) buy a vowel?\n(3) solve the puzzle?" << endl;
					cin >> player_choices;
					if(player_choices==1){
						correct_amount=choose_char(secretPhrase, &phraseDashes, spin, correct_amount);
						earnings=round_money(correct_amount, earnings, spin, a, &moneybank1, &moneybank2, &moneybank3);
						solved=check_solved(secretPhrase, &phraseDashes, solved);
					}
					if(player_choices==2){
						if(enough==true){
							enough=check_money(a, &moneybank1, &moneybank2, &moneybank3, enough);
							correct_amount=buy_vowel(secretPhrase, &phraseDashes, spin, correct_amount, earnings, &moneybank1, &moneybank2, &moneybank3);
							earnings=round_money(correct_amount, earnings, spin, a, &moneybank1, &moneybank2, &moneybank3);
							solved=check_solved(secretPhrase, &phraseDashes, solved);
						}
					}
					if(player_choices==3){
						string guesse;
						enter_guess(secretPhrase, &phraseDashes, guesse);
						earnings=round_money(correct_amount, earnings, spin, a, &moneybank1, &moneybank2, &moneybank3);

					}
			}
			if(solved==true){
				check_winner(moneybank1, moneybank2, moneybank3);
			}
		}
		b++;
	}
}

/*********************************************************************
 ** Function: wheel_spin
 ** Description: Gets a spin for the user.
 ** Parameters: None
 ** Pre-Conditions: None. 
 ** Post-Conditions: Returns an int.
 *********************************************************************/ 
int wheel_spin(){
	int spin;
	spin=(rand()%22);
	if(wheel_spin==0){
		cout << "You lose a turn. ";
	}
	return(spin);
}

/*********************************************************************
 ** Function: choose_char
 ** Description: Takes in a guess from the user to compare to the secret phrase.
 ** Parameters: string secrePhrase, string pointer phraseDashes, int spin and int correct_amount, initialized in main.
 ** Pre-Conditions: secrePhrase and phraseDashes need to be strings/string pointer. The rest are ints.
 ** Post-Conditions: Returns correct_amount.
 *********************************************************************/ 
int choose_char(string secretPhrase, string** phraseDashes, int spin, int correct_amount){
	char guess; 
	cout << "Enter a letter to guess. (Can't be a vowel): ";
	cin >> guess;
	while(guess==97 || guess==101 || guess==105 || guess==111 || guess==117){
		cout << "Error, that's a vowel. Try again: ";
		cin >> guess;
	}
	correct_amount=check_guess(guess, secretPhrase, &phraseDashes, spin);
	return(correct_amount);
}

/*********************************************************************
 ** Function: check_guess
 ** Description: Checks the guess from the user to the string.
 ** Parameters: guess, secretPhrase, phraseDashes, spin
 ** Pre-Conditions: guess needs to be a valid char that's not a vowel. The rest are strings and ints.
 ** Post-Conditions: Returns correct_amount. An int. And changes the dashes.
 *********************************************************************/ 
int check_guess(char guess, string secretPhrase, string*** phraseDashes, int spin){
	int correct_amount=0;
	for(int a=0; a<secretPhrase.length(); a++){
		if(secretPhrase.at(a)==guess){
			(**phraseDashes)->at(a)=guess;
			correct_amount=correct_amount+1;
		}
	}
	return(correct_amount);
}

/*********************************************************************
 ** Function: round_money
 ** Description: calculates the money for each user.
 ** Parameters: correct_amount, earnings, spin, a, moneybank1, moneybank2, moneybank3
 ** Pre-Conditions: all must be ints, with some pointers.
 ** Post-Conditions: correctly calculates how much money a user made.
 *********************************************************************/ 
int round_money(int correct_amount, int earnings, int spin, int a, int* moneybank1, int* moneybank2, int* moneybank3){
	earnings=correct_amount*spin;
	cout << "You earned $" << earnings << " that round!" << endl;
	money_bank(earnings, a, &moneybank1, &moneybank2, &moneybank3);

}

/*********************************************************************
 ** Function:money_bank
 ** Description: Stores the money in the bank.
 ** Parameters: earnings, a, moneybank1, moneybank2, moneybank3
 ** Pre-Conditions: all must be ints or int pointers.
 ** Post-Conditions: stores the money into a money bank.
 *********************************************************************/ 
int money_bank(int earnings, int a, int** moneybank1, int** moneybank2, int** moneybank3){
	int total_earnings;
	if(a==1){
		**moneybank1=earnings+**moneybank1;
	}
	else if(a==2){
		**moneybank2=earnings+**moneybank2;
	}
	else if(a==3){
		**moneybank3=earnings+**moneybank3;
	}
	total_earnings=total_earnings+earnings;
	return(total_earnings);
}

/*********************************************************************
 ** Function: check_money
 ** Description: If user wants a vowel, checks to see if they are eligable.
 ** Parameters: a, moneybank1, moneybank2, moneybank3, enough
 ** Pre-Conditions: must all be ints and bools.
 ** Post-Conditions: Returns a boolean to see if they have enough money
 *********************************************************************/ 
bool check_money(int a, int* moneybank1, int* moneybank2, int* moneybank3, bool enough){
	if(a==1){
		while(*moneybank1<10){
			cout << "Error, you do not have enough money." << endl;
			return enough=false;
		}while(*moneybank1>=10){
			*moneybank1=*moneybank1-10;
			return enough=true;
		}
	}
	if(a==2){	
		while(*moneybank2<10){
			cout << "Error, you do not have enough money." << endl;
			return enough=false;
		}while(*moneybank2>=10){
			*moneybank2=*moneybank2-10;
			return enough=true;
		}
	}
	if(a==3){
		while(*moneybank3<10){
			cout << "Error, you do not have enough money." << endl;
			return enough=false;
		}while(*moneybank3>=10){
			*moneybank3=*moneybank3-10;
			return enough=true;
		}
	}
}

/*********************************************************************
 ** Function: buy_vowel
 ** Description: Checks the vowel guess to the secret phrase
 ** Parameters: secretPhrase, phraseDashes, spin, correct_amount, earnings, moneybank1, moneybank2, moneybank3
 ** Pre-Conditions: must be legit strings, ints, and pointers of each.
 ** Post-Conditions: changes the dashes and returns the correct_amount.
 *********************************************************************/ 
char buy_vowel(string secretPhrase, string** phraseDashes, int spin, int correct_amount, int earnings, int* moneybank1, int* moneybank2, int* moneybank3){
	char vowel;
	correct_amount=0;

	cout << "Enter a vowel to guess: ";
	cin >> vowel;
	for(int a=0; a<secretPhrase.length(); a++){
		if(secretPhrase.at(a)==vowel){
			(*phraseDashes)->at(a)=vowel;
			correct_amount=correct_amount+1;
		}
	}
	return(correct_amount);
}

/*********************************************************************
 ** Function: check_solved
 ** Description: checks to see if the game is ended.
 ** Parameters: secretPhrase, phraseDashes, solved
 ** Pre-Conditions: needs to be legit strings, and not solved yet. 
 ** Post-Conditions: returns a boolean to either continue or disrupt the loop.
 *********************************************************************/ 
bool check_solved(string secretPhrase, string** phraseDashes, bool solved){
	int a=0;
	if(secretPhrase==**phraseDashes){
		return solved=true; 
	}
}

/*********************************************************************
 ** Function: enter_guess
 ** Description: Takes input to guess the whole thing.
 ** Parameters: secretPhrase, phraseDashes, guesse
 ** Pre-Conditions: need to be legit, and the puzzle must not be solved yet.
 ** Post-Conditions: sends the guess to option_3_check.
 *********************************************************************/ 
string enter_guess(string secretPhrase, string **phraseDashes, string guesse){
	cout << "Enter a guess!" << endl;
	cin.ignore();
	getline(cin, guesse);
	option_3_check(secretPhrase, &phraseDashes, guesse);
}

/*********************************************************************
 ** Function: option_3_check
 ** Description: used to see if the user guess is correct.
 ** Parameters: secretPhrase, phraseDashes, guesse
 ** Pre-Conditions: must not be solved yet, guesse must be a string.
 ** Post-Conditions: returns the correct amount.
 *********************************************************************/ 
int option_3_check(string secretPhrase, string*** phraseDashes, string guesse){
	int correct_amount=0;

	for(int a=0; a<secretPhrase.length(); a++){
		if(secretPhrase.at(a)==guesse.at(a)){
			(**phraseDashes)->at(a)=guesse.at(a);
			correct_amount=correct_amount+1;
		}
	}
	return(correct_amount);
}

/*********************************************************************
 ** Function: check_winner
 ** Description: checks the winner of the whole game by comparing money values.
 ** Parameters: moneybank1, moneybank2, moneybank3
 ** Pre-Conditions: must all be valid ints.
 ** Post-Conditions: prints out the winner of the game.
 *********************************************************************/ 
void check_winner(int moneybank1, int moneybank2, int moneybank3){
	cout << "Player 1 had $" << moneybank1 << ", player 2 had $" << moneybank2 << ", player 3 had $" << moneybank3 << endl;
	if(moneybank1>moneybank2 && moneybank1>moneybank3){
		cout << "Player 1 won!" << endl;
	}
	if(moneybank2>moneybank1 && moneybank2>moneybank3){
		cout << "Player 2 won!" << endl;
	}
	if(moneybank3>moneybank1 && moneybank3>moneybank2){
		cout << "Player 3 won!" << endl;
	}
}