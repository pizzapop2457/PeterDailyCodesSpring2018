#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class vegetable {
private:
	int xPos1;
	int yPos1;
	int xPos2;
	int yPos2;
public:
	void initchip(int x1, int y1);
	void initchip2(int x2, int y2);
	void drawchip(ALLEGRO_BITMAP *potato);
	void drawchip2(ALLEGRO_BITMAP *potato2);
};

int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_BITMAP	*potato = al_load_bitmap("potato.png");
	al_convert_mask_to_alpha(potato, al_map_rgb(255, 255, 255));
	ALLEGRO_BITMAP	*potato2 = al_load_bitmap("potato2.png");
	al_convert_mask_to_alpha(potato2, al_map_rgb(255, 255, 255));
	ALLEGRO_DISPLAY *display = al_create_display(1000, 1000);
	al_clear_to_color(al_map_rgb(255, 255, 255));

	while (1) {
		vegetable b1;
		b1.initchip(rand() % 1000, rand() % 1000);
		b1.drawchip(potato);
		vegetable b2;
		b2.initchip2(rand() % 1000, rand() % 1000);
		b2.drawchip2(potato2);
		al_flip_display();
	}
	system("pause");
	al_destroy_display(display);
}


void vegetable::initchip(int x, int y) {
	xPos1 = x;
	yPos1 = y;
}

void vegetable::initchip2(int x2, int y2) {
	xPos2 = x2;
	yPos2 = y2;
}

void vegetable::drawchip(ALLEGRO_BITMAP *potato) {
	al_draw_rotated_bitmap(potato, 10, 10, xPos1, yPos1, rand(), 0);
}

void vegetable::drawchip2(ALLEGRO_BITMAP *potato2) {
	al_draw_rotated_bitmap(potato2, 10, 10, xPos2, yPos2, rand(), 0);
}