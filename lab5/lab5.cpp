
Demo questions:

*We have 5 in class exercises.
*Only 1 late assignment is allowed without penalty. It it okay for 3 days. 
*If you miss a demo, you are penalized points.
*You have 7 days from the assignment due date to demo an assignment.
*If you do not pass your proficiency demo, then you get a '0' on half of the assignments. 


#include <iostream>
#include <string>

using namespace std;

void get_sentence(string &s){
	getline(cin, s);
}

int main(){

	string sentence;
	cout << "Enter a sentence: ";
	
	get_sentence(sentence);
	
	cout << sentence << endl;



}

