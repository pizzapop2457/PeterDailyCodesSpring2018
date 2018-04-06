#include <iostream>
#include <string>
#include <vector>
using namespace std;


//class definition
class student {
private:
	int id;
	int age;
	string gender;
	string lastname;
public:
	void initstudent(int i, int a, string g, string l);
	void printinfo();

};

int main() {
	vector<student>info;
	vector<student>::iterator iter;
	student bob;
	student trevin;
	student rook;
	student tao;
	bob.initstudent(863845, 12, "male", "Vance");
	trevin.initstudent(568794, 17, "male", "Padilla");
	rook.initstudent(976345, 28, "male", "Main");
	tao.initstudent(127856, 5, "female", "Nguyen");
	info.push_back(bob);
	info.push_back(trevin);
	info.push_back(rook);
	info.push_back(tao);
	for (iter = info.begin(); iter != info.end(); iter++)
		iter->printinfo();
	system("pause");


}
//function definitions
void student::initstudent(int i, int a, string g, string l) {

	id = i;
	age = a;
	gender = g;
	lastname = l;


}
void student::printinfo() {
	cout << lastname << endl;
	cout << "ID#:" << id << endl;
	cout << "Age:" << age << endl;
	cout << "Gender:" << gender << endl;
}
