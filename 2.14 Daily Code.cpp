#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	int input;
	string adjectives[] = { "adorable", "beautiful","clean", "handsome", "glamorous", "clean", "drab", "sparkling", "ugliest", "plain", "fancy", "elegant", "long", "magnificent", "victorious", "brave", "calm", "repulsive", "hard-core", "stupid" };
	string nouns[] = { "slave", "person", "fam", "teacher", "meat", "computer", "dog", "food", "idiot", "assassin","player", "soup", "wade", "president","student","cookie","duck","apple","sakura","trash" };
	
	while (1) {
		int adj = rand() % 20;
		int noun = rand() % 20;
		cout << "Press y 4 your rapper name." << endl;
		cin >> input;
		cout << adjectives[adj] << " " << nouns[noun] << endl << endl;
		system("pause");
	}
}