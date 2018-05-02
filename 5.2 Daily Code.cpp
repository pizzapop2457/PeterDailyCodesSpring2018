#include <iostream>
using namespace std;
void print_menu();
void religion(int x);
double celsius(double f);
int c = 2;
double d;
char input = 'a';

int main() {
	print_menu();
	while (input != 'q') {
		cout << "Command:";
		cin >> input;
		if (input == 'h') {
			print_menu();
		}
		else if (input == 'q') {
			return 0;
		}
		else if (input == 'r') {
			cout << "Which religion?" << endl;
			cin >> c;
			religion(c);
		}
		else if (input == 't') {
			cout << "Give me Fahrenheit." << endl;
			cin >> d;
			cout << celsius(d) << " Celsius" << endl;
		}
	}
}

void print_menu() {
	cout << "q: quit" << endl;
	cout << "h: help" << endl;
	cout << "r: info about a religion" << endl;
	cout << "t: temperature conversion" << endl;
}
void religion(int x) {
	switch (x) {
	case 1:
		cout << "Christianity: 31.2%" << endl;
		break;
	case 2:
		cout << "Islam: 24.1%" << endl;
		break;
	case 3:
		cout << "Secular/Nonreligious/Agnostic/Atheist: 16%" << endl;
		break;
	case 4:
		cout << "Hinduism: 15.1%" << endl;
		break;
	case 5:
		cout << "Buddhism: 6.9%" << endl;
		break;
	case 6:
		cout << "Chinese traditional religion: 5.50%" << endl;
		break;
	case 7:
		cout << "Ethnic religions: 4.19%" << endl;
		break;
	case 8:
		cout << "African traditional religions: 1.40%" << endl;
		break;
	case 9:
		cout << "Sikhism: 0.32%" << endl;
		break;
	case 10:
		cout << "Spiritism: 0.21%" << endl;
		break;
	default:
		cout << "Don't know anything about religion " << x << endl;
	}

}

double celsius(double f) {

	return ((f - 32) * 5 / 9);

}
