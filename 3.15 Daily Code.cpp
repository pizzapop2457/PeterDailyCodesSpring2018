#include <iostream>
#include <string>

using namespace std;
string  inventory[3];

int main() {

	cout << "What is your favorite food?" << endl;
	for (int i = 0; i < 3; i++) {
		getline(cin, inventory[i]);
		if (inventory[i].compare("taco") == 0)
			cout << "You are cool." << endl;
		else
			cout << "You suck." << endl;
	}
	for (int i = 0; i < 3; i++)
		cout << inventory[i] << endl;

}
