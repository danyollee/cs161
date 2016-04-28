/******************************************************************************
 ** File name: A2.cpp
 ** Author: Daniel Lee
 ** Date: 1/18/2016
 ** Description: A financial calculator
 ** Input: Values
 ** Output: end values
 *****************************************************************************/

#include<iostream>
#include<cmath>
#include<math.h>

using namespace std;

#define E 2.718281828459

/*****************************************************************************
 ** Function name: main
 ** Description: runs the entire program
 ** Parameters: none
 ** Pre-condition: values entered must be numbers
 ** Post-condition: calculated values
 ****************************************************************************/

int main(){
	cout << endl;
	cout << "Hello! This is a financial calculator. Here are three options that you may choose from." << endl;


	/*********************************************************************
	** Function name: startchoice
	** Description: chooses which path to go
	** Parameters: none
	** Pre-condition: must be an integer between 1 and 3
	** Post-condition: program keeps running
	**********************************************************************/


	int startchoice;
	cout << "1. Balance of a loan. " << endl;
	cout << "2. Continuously compounded interest. " << endl;
	cout << "3. Future value. " << endl;


	//This guides the program.
	

	cout << "Type in 1, 2, or 3, for what you want to solve: ";
	cin >> startchoice;


	if(startchoice==1){
		float init, interest, payment, telapsed;
		cout << "This will calculate the remaining balance of a loan. How much did you take out?: ";
		cin >> init;

		cout << "What's the annual interest rate? (As a whole number): ";
		cin >> interest;
		interest=((interest/12)/100);

		cout << "How much do you pay per payment?: ";
		cin >> payment;
	
		cout << "How many payments have you already made?: ";
		cin >> telapsed;

		float oneplusi;
		oneplusi = 1+interest;

		float balance;
		balance = (init*((pow((oneplusi), telapsed))))-((payment/interest)*((pow((oneplusi), telapsed)-1)));


		/************************************************************
		** Function name: goali
		** Description: inputs the goal that the user wants to achieve
		** Parameters: none
		** Pre-condition: must be a number
		** Post-condition: stores it in goali
		************************************************************/

	
		int goali;
		cout << "How much do you want your balance to be?: ";
		cin >> goali;
		
		float goall;
		goall=balance-goali;

		cout << "The balance of your loan is $" << balance << "." << endl;
	
		if(goall>0){
			cout << "You did not meet your goal. You are $" << goall << " over your goal. Try to pay more per period!" << endl;
		}
		else if(goall==0){
			cout << "You are exactly on track to your goal. Good job!" << endl;
		}
		else if(goall<0){
			cout << "You are ahead of your goal. Good job!" << endl;
		}
	


	}
	

	if(startchoice==2){
		float prin, interest, year;
		cout << "Okay. You chose to find the amount after you continuously compound. First, what is the principle? (Starting amount): " ;
		cin >> prin;

		cout << "Now, what is your annual interest rate? (As a decimal): ";
		cin >> interest;

		cout << "Finally, how many years do you want to calculate for?: ";
		cin >> year;


		/**************************************************************
		** Function name: goali
		** Description: inputs the goal that the user wants to achieve
		** Parameters: none
		** Pre-condition: must be a number
		** stores it in goali
		**************************************************************/


		int goali;
		cout << "How much money do you want to have after " << year << " years?: ";
		cin >> goali;

		float pErt;
		pErt = prin*(pow(E, (interest*year)));
		
		float goalcc;
		goalcc=pErt-goali;

		cout << "After " << year << " years, you will have a total of $" << pErt << "." << endl;
	
		if(goalcc<0){
			cout << "You will not meet your goal. You will be $" << goalcc << " under your goal." << endl;
		}
		else if(goalcc==0){
			cout << "You are exactly on track for you goal!" << endl;
		}
		else if(goalcc>0){
			cout << "You will have more than your goal!" << endl;
		}

	}

	if(startchoice==3){
		cout << "You chose to calculate the future value of your moneys." << endl;

		float prin, ror, period;
		cout << "What's the initial cash flow?: ";
		cin >> prin;

		cout << "What's the rate of return?(As a percentage): ";
		cin >> ror;
		ror=(ror/100);

		cout << "How many months are you calculating for?: ";
		cin >> period;
	
		int goali;
		cout << "What do you hope the value of your moneys to be?: ";
		cin >> goali;

		float value;
		value = prin*(pow((1+ror), period));

		float goalfv;
		goalfv=value-goali;

		cout << "The value of your moneys will be $" << value << " after " << period << " months." << endl;

		if(goalfv>0){
			cout << "Your moneys will be $" << goalfv << " greater than your goal." << endl;
		}
		else if(goalfv==0){
			cout << "Your moneys will be exactly what your goal is." << endl;
		}
		else if(goalfv<0){
			cout << "Your moneys will not reach your goal." << endl;
		}
	}

	

	return 0;
}
