#include <iostream>

#define PROMPT "Please enter a whole number:"
#define NOT_PRIME "The number is not a prime number.\n"
#define PRIME "The number is a prime number.\n"

/* new thing */ using namespace std;

void is_prime(int);

int main(){
    int number; /* number provided by user */

    cout << PROMPT;  /* promt user */
    cin >> number;  /* wait for user input */
    is_prime(number);  /*determine if number prime or not*/

    return 0;     /* exit program */
}
/* Prime numbers are defined as any number greater
* than one that is only divisible by one and itself.
* Dividing the number by two shortens the time it 
* takes to complete. */
void is_prime(int number){
    for(int i = 2; i < (number/2); i++){
       if( number%i == 0 ){    /* if divisible */
          cout << NOT_PRIME << number; /* not prime */
          return;        /* exit program */
       }
     }
    /* if number is not divisible by anything
     * than it must be prime */
    cout << PRIME << endl;
}