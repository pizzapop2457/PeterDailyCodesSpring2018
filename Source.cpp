#include <iostream>
#include <string>
using namespace std;

class Smash {
private:
	int lives;
	int damage;
	string name;
public:
	void initPlayer(int x, int y, string z);
	void printinfo();
	void takeDamage(int x);
};

//declare
int knockback(int D, int w, int p, double s, int b, double r);

int main() {
	Smash Pikachu;

	Pikachu.initPlayer(2, 0, "Pikachu");

	Pikachu.printinfo();
	//call damage function
	Pikachu.takeDamage(knockback(30, 75, 20, 1.5, 20, 1.2));
	Pikachu.printinfo();



}
//define
int knockback(int D, int w, int p, double s, int b, double r) {

	int num;
	num = ((((7 * (D + 2) * (D + p)) / (w + 100) + 9) * 2 * s) + b) * r;
	cout << "damage calculated is " << num << endl;
	return num;
}
void Smash::printinfo() {
	cout << name << " percentage damage is " << damage << " lives are " << lives << endl;
}
void Smash::takeDamage(int x) {
	damage += x;


}
void Smash::initPlayer(int x, int y, string z) {
	lives = x;
	damage = y;
	name = z;
}