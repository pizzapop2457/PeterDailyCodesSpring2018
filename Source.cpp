#include<iostream>
#include<Windows.h>
#include <ctime>
using namespace std;

//class definition
class pokemon
{
private:
	int health;
public:
	void eat(char c);
	void initPoke(int num);
	void printInfo();

};

//function declaration
char foodDrop(char location);



int main() {

	srand(time(NULL));
	while (1) {
		pokemon charizard;
		charizard.initPoke(5);
		charizard.printInfo();
		//charizard.eat('b'); //testing without food dropper
		charizard.eat(foodDrop('f')); //testing with food dropper
		charizard.printInfo();


		system("pause");
	}


}//end main

 //function declarations
char foodDrop(char location) {

	int num = rand() % 100 + 1;

	if (location == 'f') {
		if (num <= 50) {
			cout << "you got a berry!" << endl;
			return 'b';
		}
		else {
			cout << "you got a mushroom!" << endl;
			return 'm';

		}
	}
	else if (location == 'd') {
		if (num <= 20) {
			cout << "You got a berry!" << endl;
			return 'b';
		}
		else if (num <= 40) {
			cout << "You got a fruit!" << endl;
			return 'f';
		}
		else if (num < 40) {
			cout << "You found some cheese?" << endl;
			return 'c';
		}
	}


	else
		cout << "invalid location" << endl;

}


void pokemon::initPoke(int num) {
	health = num;
}
void pokemon::printInfo() {
	cout << "your charizard's health is " << health << endl;
}

void pokemon::eat(char food) {

	if (food == 'b')
		health += 3;
	else if (food == 'c')
		health += 4;
	else if (food == 'm')
		health += 5;
	else if (food == 'p')
		health += 6;
	else if (food == 'f')
		health += 7;

}