#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class invader {
private:
	int health;
	int xPos;
	int yPos;
public:
	void initHp(int num);
	void initSpaceship(int x, int y);
	void drawSpaceship(ALLEGRO_BITMAP *spaceship);
	void printInfo();
};

int main() {
	al_init();
	al_init_image_addon();
	ALLEGRO_BITMAP	*spaceship = al_load_bitmap("spaceship.png");
	al_convert_mask_to_alpha(spaceship, al_map_rgb(255, 255, 255));
	ALLEGRO_DISPLAY *display = al_create_display(500, 500);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	
	invader b1;
	b1.initSpaceship(0, 10);
	b1.drawSpaceship(spaceship);
	invader b2;
	b2.initSpaceship(100, 10);
	b2.drawSpaceship(spaceship);
	invader b3;
	b3.initSpaceship(200, 10);
	b3.drawSpaceship(spaceship);
	invader b4;
	b4.initSpaceship(300, 10);
	b4.drawSpaceship(spaceship);
	invader b5;
	b5.initSpaceship(400, 10);
	b5.drawSpaceship(spaceship);

	invader b6;
	b6.initSpaceship(0, 100);
	b6.drawSpaceship(spaceship);
	invader b7;
	b7.initSpaceship(100, 100);
	b7.drawSpaceship(spaceship);
	invader b8;
	b8.initSpaceship(200, 100);
	b8.drawSpaceship(spaceship);
	invader b9;
	b9.initSpaceship(300, 100);
	b9.drawSpaceship(spaceship);
	invader b10;
	b10.initSpaceship(400, 100);
	b10.drawSpaceship(spaceship);


	al_flip_display();
	
	invader qwerty;
	qwerty.initHp(3);
	qwerty.printInfo();

	system("pause");
	al_destroy_display(display);
}

void invader::initHp(int num) {
	health = num;
}

void invader::initSpaceship(int x, int y) {
	xPos = x;
	yPos = y;
}

void invader::drawSpaceship(ALLEGRO_BITMAP *spaceship) {
	al_draw_bitmap(spaceship, xPos, yPos, 0);
}

void invader::printInfo() {
	cout << "Your health is " << health << "." <<endl;
}