#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>
#include <iostream>
using namespace std;


//class definition
class enemy {
private:
	int xpos1;
	int ypos1;
	int xpos2;
	int ypos2;
	bool isdead1;
	bool isdead2;
	ALLEGRO_BITMAP *image1;
	ALLEGRO_BITMAP *image2;
	ALLEGRO_BITMAP *image3;
	ALLEGRO_BITMAP *image4;
public:
	void initgoomba(int x1, int y1, bool dead1, ALLEGRO_BITMAP*pic1, ALLEGRO_BITMAP*pic2);
	void drawgoomba();
	void initkoopa(int x2, int y2, bool dead2, ALLEGRO_BITMAP*pic3, ALLEGRO_BITMAP *pic4);
	void drawkoopa();
};


int main() {
	
	al_init();
	al_init_image_addon();
	ALLEGRO_BITMAP *image1 = al_load_bitmap("Goomba.png");
	ALLEGRO_BITMAP *image2 = al_load_bitmap("Dead Goomba.png");
	ALLEGRO_BITMAP *image3 = al_load_bitmap("Green Koopa.png");
	ALLEGRO_BITMAP *image4 = al_load_bitmap("Red Koopa.png");
	al_convert_mask_to_alpha(image1, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(image2, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(image3, al_map_rgb(255, 255, 255));
	al_convert_mask_to_alpha(image4, al_map_rgb(255, 255, 255));
	ALLEGRO_DISPLAY *display = al_create_display(800, 800);
	al_clear_to_color(al_map_rgb(0, 0, 0));
	//instantiate (create) the objects
	enemy g1;
	enemy g2;
	enemy g3;
	enemy k1;
	enemy k2;
	enemy k3;

	//initialize (give data)
	while (1) {
		g1.initgoomba(rand()%800, rand()%800, true, image1, image2);
		g2.initgoomba(rand()%800, rand()%800, false, image1, image2);
		g3.initgoomba(rand()%800, rand()%800, true, image1, image2);

		k1.initkoopa(rand()%800, rand()%800, false, image3, image4);
		k2.initkoopa(rand()%800, rand()%800, true, image3, image4);
		k3.initkoopa(rand()%800, rand()%800, false, image3, image4);

		g1.drawgoomba();
		g2.drawgoomba();
		g3.drawgoomba();

		k1.drawkoopa();
		k2.drawkoopa();
		k3.drawkoopa();

		al_flip_display();
	}
	system("pause");
}
//function definitions
void enemy::initgoomba(int x1, int y1, bool dead1, ALLEGRO_BITMAP*pic1, ALLEGRO_BITMAP*pic2) {

	xpos1 = x1;
	ypos1 = y1;
	isdead1 = dead1;
	image1 = pic1;
	image2 = pic2;
}

void enemy::initkoopa(int x2, int y2, bool dead2, ALLEGRO_BITMAP*pic3, ALLEGRO_BITMAP*pic4) {

	xpos2 = x2;
	ypos2 = y2;
	isdead2 = dead2;
	image3 = pic3;
	image4 = pic4;
}

void enemy::drawgoomba() {
	if (isdead1 == true)
		al_draw_bitmap(image1, xpos1, ypos1, 0);
	else
		al_draw_bitmap(image2, xpos1, ypos1, 0);
}

void enemy::drawkoopa() {
	if (isdead2 == true)
		al_draw_bitmap(image3, xpos2, ypos2, 0);
	else
		al_draw_bitmap(image4, xpos2, ypos2 , 0);
}