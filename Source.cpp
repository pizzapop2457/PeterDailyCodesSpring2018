#include <iostream>
#include <string>
#include <vector>

using namespace std;

class car {
private:
	int fuel;
	string brand;
	string color;
	bool wheel;
public:
	void initvehicle(int f, string b, string c, bool w);
	void printinfo();
};




int main() {
	vector <car> garage;
	vector <car>::iterator iter;

	//stamping
	car Ford;
	car Honda;
	car Jeep;
	car Subaru;
	car Toyota;

	//initializing 
	Ford.initvehicle(21, "Ford", "Orchid", true);
	Honda.initvehicle(96, "Honda", "Dark Slate Blue", false);
	Jeep.initvehicle(98, "Jeep", "Plum", true);
	Subaru.initvehicle(9, "Subaru", "Goldenrod", false);
	Toyota.initvehicle(66, "Toyota", "Black", true);

	garage.push_back(Ford);
	garage.push_back(Honda);
	garage.push_back(Jeep);
	garage.push_back(Subaru);
	garage.push_back(Toyota);
	
	for (iter = garage.begin(); iter != garage.end(); iter++)
		iter->printinfo();

}


void car::printinfo() {
	cout << "The " << brand << " car is " << color << " color and fuel amount is " << fuel << " %." << endl;
	if (wheel != true) 
		cout << "It's a four wheel drive." << endl;
	else
		cout << "It's not a four wheel drive." << endl;
	
}

void car::initvehicle(int f, string b, string c, bool w) {
	fuel = f;
	brand = b;
	color = c;
	wheel = w;
}