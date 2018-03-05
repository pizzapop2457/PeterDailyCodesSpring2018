#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class spot {
private:
	int xPos;
	int yPos;

public:
	void initSpot(int x, int y);
	void drawSpot();
};

int main() {
	al_init();
	al_init_primitives_addon(); //initialize helper library
	ALLEGRO_DISPLAY *display = al_create_display(500, 500);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_circle(250, 250, 240, al_map_rgb(255, 255, 0), 10);

	spot b1;
	spot b2;
	spot b3;
	spot b4;
	spot b5;
	spot b6;
	spot b7;
	spot b8;
	spot b9;
	spot b10;
	spot b11;
	spot b12;
	spot b13;
	spot b14;
	spot b15;
	spot b16;
	spot b17;
	spot b18;
	spot b19;
	spot b20;
	spot b21;
	spot b22;
	spot b23;
	spot b24;

	b1.initSpot(125, 125);
	b2.initSpot(375, 125);

	b3.initSpot(90, 250);
	b4.initSpot(120, 250);
	b5.initSpot(150, 250);
	b6.initSpot(180, 250);
	b7.initSpot(210, 250);
	b8.initSpot(240, 250);
	b9.initSpot(270, 250);
	b10.initSpot(300, 250);
	b11.initSpot(330, 250);
	b12.initSpot(360, 250);
	b13.initSpot(390, 250);

	b14.initSpot(105, 280);
	b15.initSpot(135, 310);
	b16.initSpot(165, 340);
	b17.initSpot(195, 370);
	b18.initSpot(215, 400);

	b19.initSpot(375, 280);
	b20.initSpot(345, 310);
	b21.initSpot(315, 340);
	b22.initSpot(295, 370);
	b23.initSpot(265, 400);

	b24.initSpot(240, 420);

	b1.drawSpot();
	b2.drawSpot();
	b3.drawSpot();
	b4.drawSpot();
	b5.drawSpot();
	b6.drawSpot();
	b7.drawSpot();
	b8.drawSpot();
	b9.drawSpot();
	b10.drawSpot();
	b11.drawSpot();
	b12.drawSpot();
	b13.drawSpot();
	b14.drawSpot();
	b15.drawSpot();
	b16.drawSpot();
	b17.drawSpot();
	b18.drawSpot();
	b19.drawSpot();
	b20.drawSpot();
	b21.drawSpot();
	b22.drawSpot();
	b23.drawSpot();
	b24.drawSpot();

	al_flip_display();
	al_rest(20);
	al_destroy_display(display);
}

void spot::initSpot(int x, int y) {
	xPos = x;
	yPos = y;
}
 
void spot::drawSpot() {
	al_draw_filled_circle(xPos, yPos, 25, al_map_rgb(rand(), rand(), rand()));
}
