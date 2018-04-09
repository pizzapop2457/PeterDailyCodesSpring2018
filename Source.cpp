#include <iostream>
#include <ctime>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_acodec.h>
#include <allegro5\allegro_audio.h>


using namespace std;

int main() {
	/*al_init();
	al_init_acodec_addon();
	al_init_image_addon();
	al_install_audio();
	ALLEGRO_BITMAP *image1 = al_load_bitmap("red.jpg");
	ALLEGRO_DISPLAY *display = al_create_display(900,900);
	ALLEGRO_TIMER *timer = NULL;*/

	//al_flip_display();
	
	srand(time(NULL));
	string colors[9]{ "red","yellow","blue","pink","purple","green","orange","white","black" };
	string body[14]{ "head","toe","hand","foot","elbow","knee","finger","cock","bitch","hair","nose","face","ear","butt" };
		while (1) {
			int col = rand() % 9;
			int bod = rand() % 14;
			cout << colors[col] << " " << body[bod] << endl;
			system("pause");
		}
	//al_destroy_bitmap(bitmap);
	//al_destroy_bitmap(display);
	//al_destroy_bitmap(timer);
}