#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	string line;
	ifstream myfile("Prob01.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << endl;
			cout << line << endl;
		}
		myfile.close();
	}
	else
		cout << "Unable to open file";
	system("pause");
}
