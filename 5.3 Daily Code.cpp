#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//function declarations
void read_file();
int list_min(vector<int>list1);
int list_max(vector<int>list2);

int main() {
	read_file();
}//end main

void read_file() {
	ifstream file("read_file.txt");
	int input;
	vector <int> numbers;

	file.is_open();

	//main loop
	while (file >> input) {
		numbers.push_back(input);
		cout << input << endl; //testing purposes
	}
	file.close();
	cout << "the smallest is " << list_min(numbers) << endl;
	cout << "the largest is " << list_max(numbers) << endl;

}


int list_min(vector<int>list1) {

	vector <int >::iterator i;
	int smallest = *list1.begin();
	for (i = list1.begin(); i != list1.end(); i++) {
		if (*i < smallest)
			smallest = *i;
	}
	return smallest;


}

int list_max(vector<int>list2) {

	vector <int >::iterator i;
	int largest = *list2.begin();
	for (i = list2.begin(); i != list2.end(); i++) {
		if (*i > largest)
			largest = *i;
	}
	return largest;

}

