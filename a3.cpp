/*********************************************************************
 ** Program Filename: a3.cpp
 ** Author: Daniel Lee
 ** Date: 1/30/2016
 ** Description: Calculates a rover to travel from a starting point, to an end point.
 ** Input: Numbers.
 ** Output: A grid.
 *********************************************************************/ 
#include <iostream>

using namespace std;

//prototypes
int start_pos();
int end_pos();
int process_math(int& choicestart, int& choiceend);
void find_path(int choicestart, int choiceend, int amount);
int repeat();

/*********************************************************************
 ** Function: main
 ** Description: Runs the whole program, calling other functions as well.
 ** Parameters: None.
 ** Pre-Conditions: None. 
 ** Post-Conditions: None. 
 *********************************************************************/

int main(){

	cout << "Welcome to the rover program." << endl;


	//dummy variables for now.
	int choicestart=0;
	int choiceend=0;
	int amount=0;

	choicestart=start_pos(); //gets starting position of rover
	choiceend=end_pos(); //gets ending position of rover
	amount=process_math(choicestart, choiceend); //gets the amount it needs to move
	cout << endl << "The rover will have to move " << amount << " units." << endl;
	find_path(choicestart, choiceend, amount);
	repeat();
}

/*********************************************************************
 ** Function: start_pos
 ** Description: Gets input from the user on where to start the rover.
 ** Parameters: None. 
 ** Pre-Conditions: Can only be from 1-16 because that's how big the grid is. Value must be an integer.
 ** Post-Conditions: Stores the starting position in choicestart. Will be used in the grid later.
 *********************************************************************/

int start_pos(){
	cout << endl << "16|15|14|13\n 9|10|11|12\n 8| 7| 6| 5\n 1| 2| 3| 4";

	int choicestart;
	cout << endl << "Choose a value above to start with: ";
	cin >> choicestart;
	//cout << choicestart << endl;
	while(choicestart<=0 || choicestart>=17){
		cout << "Error, not valid. Try again: ";
		cin >> choicestart;
	}
	return(choicestart);
}

/*********************************************************************
 ** Function: end_pos
 ** Description: Gets input from the user on where to send/stop the rover.
 ** Parameters: None. 
 ** Pre-Conditions: Can only be from 1-16 because that's how big the grid is. Value must be an integer. 
 ** Post-Conditions: Stores the ending position in choiceend. Will be used in the grid later.
 *********************************************************************/

int end_pos(){
	cout << "16|15|14|13\n 9|10|11|12\n 8| 7| 6| 5\n 1| 2| 3| 4";

	int choiceend;
	cout << endl << "Choose a value above to end with: ";
	cin >> choiceend;
	//cout << choiceend;
	while(choiceend<=0 || choiceend>=17){
		cout << "Error, not valid. Try again: ";
		cin >> choiceend;
	}
	return(choiceend);
}

/*********************************************************************
 ** Function: process_math
 ** Description: This gets the amount of times the rover has to move.
 ** Parameters: choicestart and choiceend.
 ** Pre-Conditions: Must be numbers from 1-16. Value must be an integer.
 ** Post-Conditions: Stores the amount to move in 'amount'. 
 *********************************************************************/

int process_math(int& choicestart, int& choiceend){
	int amount;
	amount=choiceend-choicestart;
	return(amount);
}

/*********************************************************************
 ** Function: find_path
 ** Description: This has the loops and shows the rover moving. 
 ** Parameters: choicestart, choiceend, amount.
 ** Pre-Conditions: The other functions have to be true. All the values must be numbers.
 ** Post-Conditions: Spits out the grid, shows the rover moving.
 *********************************************************************/

void find_path(int choicestart, int choiceend, int amount){

char a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, a16;

	//These are all dummy variables, just to create them. They also serve as the '0's for the grid. To make it more concise, use a for-loop.
	a1='0';
	a2='0';
	a3='0';
	a4='0';
	a5='0';
	a6='0';
	a7='0';
	a8='0';
	a9='0';
	a10='0';
	a11='0';
	a12='0';
	a13='0';
	a14='0';
	a15='0';
	a16='0';

	if(choicestart==1){
		a1='S';
	}
	if(choicestart==2){
		a2='S';
	}
	if(choicestart==3){
		a3='S';
	}
	if(choicestart==4){
		a4='S';
	}
	if(choicestart==5){
		a5='S';
	}
	if(choicestart==6){
		a6='S';
	}
	if(choicestart==7){
		a7='S';
	}
	if(choicestart==8){
		a8='S';
	}
	if(choicestart==9){
		a9='S';
	}
	if(choicestart==10){
		a10='S';
	}
	if(choicestart==11){
		a11='S';
	}
	if(choicestart==12){
		a12='S';
	}
	if(choicestart==13){
		a13='S';
	}
	if(choicestart==14){
		a14='S';
	}
	if(choicestart==15){
		a15='S';
	}
	if(choicestart==16){
		a16='S';
	}

	if(choiceend==1){
			a1='E';
		}
	if(choiceend==2){
			a2='E';
		}
	if(choiceend==3){
			a3='E';
		}
	if(choiceend==4){
			a4='E';
		}
	if(choiceend==5){
			a5='E';
		}
	if(choiceend==6){
			a6='E';
		}
	if(choiceend==7){
			a7='E';
		}
	if(choiceend==8){
			a8='E';
		}
	if(choiceend==9){
			a9='E';
		}
	if(choiceend==10){
			a10='E';
		}
	if(choiceend==11){
			a11='E';
		}
	if(choiceend==12){
			a12='E';
		}
	if(choiceend==13){
			a13='E';
		}
	if(choiceend==14){
			a14='E';
		}
	if(choiceend==15){
			a15='E';
		}
	if(choiceend==16){
			a16='E';
		}

	cout << endl << a16 << "|" << a15 << "|" << a14 << "|" << a13 << endl << a9 << "|" << a10 << "|" << a11 << "|" << a12 << endl << a8 << "|" << a7 << "|" << a6 << "|" << a5 << endl << a1 << "|" << a2 << "|" << a3 << "|" << a4 << endl;
	cout << "Here are the starting(S) and ending(E) areas that the rover will go." << endl;

	if(amount>=1){
		for(int m=1; m<=amount; m++){
			choicestart=choicestart+1;
			if(choicestart==1){
				a1='X';
			}
			if(choicestart==2){
				a2='X';
			}
			if(choicestart==3){
				a3='X';
			}
			if(choicestart==4){
				a4='X';
			}
			if(choicestart==5){
				a5='X';
			}
			if(choicestart==6){
				a6='X';
			}
			if(choicestart==7){
				a7='X';
			}
			if(choicestart==8){
				a8='X';
			}
			if(choicestart==9){
				a9='X';
			}
			if(choicestart==10){
				a10='X';
			}
			if(choicestart==11){
				a11='X';
			}
			if(choicestart==12){
				a12='X';
			}
			if(choicestart==13){
				a13='X';
			}
			if(choicestart==14){
				a14='X';
			}
			if(choicestart==15){
				a15='X';
			}
			if(choicestart==16){
				a16='X';
			}
			cout << endl << a16 << "|" << a15 << "|" << a14 << "|" << a13 << endl << a9 << "|" << a10 << "|" << a11 << "|" << a12 << endl << a8 << "|" << a7 << "|" << a6 << "|" << a5 << endl << a1 << "|" << a2 << "|" << a3 << "|" << a4 << endl;
		}
	}
	if(amount<=-1){
		for(int m=0; m>=amount; m--){
			choicestart=choicestart-1;
			cout << endl << a16 << "|" << a15 << "|" << a14 << "|" << a13 << endl << a9 << "|" << a10 << "|" << a11 << "|" << a12 << endl << a8 << "|" << a7 << "|" << a6 << "|" << a5 << endl << a1 << "|" << a2 << "|" << a3 << "|" << a4 << endl;
			if(choicestart==1){
				a1='X';
			}
			if(choicestart==2){
				a2='X';
			}
			if(choicestart==3){
				a3='X';
			}
			if(choicestart==4){
				a4='X';
			}
			if(choicestart==5){
				a5='X';
			}
			if(choicestart==6){
				a6='X';
			}
			if(choicestart==7){
				a7='X';
			}
			if(choicestart==8){
				a8='X';
			}
			if(choicestart==9){
				a9='X';
			}
			if(choicestart==10){
				a10='X';
			}
			if(choicestart==11){
				a11='X';
			}
			if(choicestart==12){
				a12='X';
			}
			if(choicestart==13){
				a13='X';
			}
			if(choicestart==14){
				a14='X';
			}
			if(choicestart==15){
				a15='X';
			}
			if(choicestart==16){
				a16='X';
			}
		}
	}
}

/*********************************************************************
 ** Function: repeat
 ** Description: Asks the user if they want to repeat the whole program.
 ** Parameters: None.
 ** Pre-Conditions: Must be a value of '0' or '1'.
 ** Post-Conditions: Repeats the entire program.
 *********************************************************************/

int repeat(){
	int choice_repeat;
	cout << "Do you want to go repeat the program? (0) for no, (1) for yes: ";
	cin >> choice_repeat;
	while(choice_repeat<0 || choice_repeat>1){
		cout << "Error, not valid. Try again: ";
		cin >> choice_repeat;
	}
	if(choice_repeat==1){
		main();
	}
	else{
		cout << "Thanks for using my program! Cheers!" << endl;
	}
}