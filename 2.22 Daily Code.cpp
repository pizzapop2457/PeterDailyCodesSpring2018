#include <iostream>

using namespace std;

int main() {

	int biNum[5];

	cout << "Please put in the didgets of your binary number from biggest to smallest (left to right)." << endl;


	for (int d = 5; d >= 1; d--) {
		cin >> biNum[d];
	}
	biNum[5] = biNum[5] * 16;
	biNum[4] = biNum[4] * 8;
	biNum[3] = biNum[3] * 4;
	biNum[2] = biNum[2] * 2;
	biNum[1] = biNum[1] * 1;

	cout << "Your decimal number is: " << biNum[5] + biNum[4] + biNum[3] + biNum[2] + biNum[1] << endl;
	system("pause");


}