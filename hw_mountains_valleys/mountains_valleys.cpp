#include <iostream>
#include "functions.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
    int a=0;
	int b=0;
	// TODO(student): print prompt for input
    do{ 
		cout << "Enter numbers 10 <= a <= b < 10000: " ;
	    cin >> a >> b; 	
	// TODO(student): read the numbers from standard input
	} while (!is_valid_range( a, b ));
	  cout<<" Invalid Input" << endl;
	// TODO(student): validate input (and reprompt on invalid input)
	

	// TODO(student): compute and display solution
	count_valid_mv_numbers( a, b );
	//cout<< count_valid_mv_numbers <<endl;
	
	return 0;
}