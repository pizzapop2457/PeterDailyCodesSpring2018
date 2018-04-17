#include<iostream> //library: prewritten code
using namespace std; //cheat code to help iostream be easier
int main() { //starting point of your program
	int x; //creates an empty variable that holds numbers
	cin >> x; //gets a number from the keyboard

					  //create three variables that hold numbers and sets them to 0 and 1
	int pt = 0;
	int ct = 1;
	int sum = 0;

	for (int i = 0; i < x - 2; i++) { //loops the next 3 lines x-2 number of times
		sum = pt + ct; //new sum
		pt = ct; //move current into previous
		ct = sum; //moves the sum into the current
	}
	cout << sum << endl; //prints, endl skips a line
	system("pause"); //stops console from closing

}
