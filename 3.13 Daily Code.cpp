#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int input = 64;
	int temp;
	vector <int> numbers;
	vector <int> ::iterator i;


	//get unput from users until they press 0
	while (input != 0) {
		cin >> input;
		numbers.push_back(input);
	}


	//sort it!
	sort(numbers.begin(), numbers.end());


	//print it back out!
	for (i = numbers.begin(); i < numbers.end(); i++) {
		cout << "the numbers in order are:";
		cout << *i << endl;
	}
	system("pause");

}
