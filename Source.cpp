#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 720;
const int SCREEN_H = 500;
const int BOUNCER_SIZE = 20;

enum MYKEYS {
	KEY_LEFT, KEY_RIGHT
};

bool PixelCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

class brick {
private:
	int xPos;
	int yPos;
public:
	void initBrick(int x, int y);
	void drawBrick();
};

int main()
{
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *paddle1 = NULL;
	float bouncer_x = 350;
	float bouncer_y = 400;
	float paddle1_x = 200;
	float paddle1_y = 200;
	float paddle1_dx = -4.0, paddle1_dy = 4.0;
	bool key[4] = { false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
	timer = al_create_timer(1.0 / FPS);

	display = al_create_display(SCREEN_W, SCREEN_H);

	bouncer = al_create_bitmap(BOUNCER_SIZE+80, BOUNCER_SIZE);

	paddle1 = al_create_bitmap(32, 32);

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 255, 0));

	al_set_target_bitmap(paddle1);

	al_clear_to_color(al_map_rgb(rand() % 255, rand() % 255, rand() % 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	brick b1;
	brick b2;
	brick b3;
	brick b4;
	brick b5;
	brick b6;
	brick b7;
	brick b8;
	brick b9;
	brick b10;
	brick b11;
	brick b12;
	brick b13;
	brick b14;
	brick b15;
	brick b16;
	brick b17;
	brick b18;
	/*brick b19;
	brick b20;*/

	b1.initBrick(10, 10);
	b2.initBrick(130, 10);
	b3.initBrick(250, 10);
	b4.initBrick(370, 10);
	b5.initBrick(490, 10);
	b6.initBrick(610, 10);

	b7.initBrick(10, 80);
	b8.initBrick(130, 80);
	b9.initBrick(250, 80);
	b10.initBrick(370, 80);
	b11.initBrick(490, 80);
	b12.initBrick(610, 80);

	b13.initBrick(10, 150);
	b14.initBrick(130, 150);
	b15.initBrick(250, 150);
	b16.initBrick(370, 150);
	b17.initBrick(490, 150);
	b18.initBrick(610, 150);

	/*b19.initBrick(370, 80);
	b20.initBrick(370, 80);*/




	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {

			if (key[KEY_LEFT] && bouncer_x >= 4.0) {
				bouncer_x -= 4.0;
			}

			if (key[KEY_RIGHT] && bouncer_x <= SCREEN_W - 100 - 4.0) {
				bouncer_x += 4.0;
			}

			if (paddle1_x < 0 || paddle1_x > 700 - 32) {
				paddle1_dx = -paddle1_dx;
			}
			if (paddle1_y < 0 || paddle1_y > 500 - 32) {
				paddle1_dy = -paddle1_dy;
			}
			paddle1_x += paddle1_dx;
			paddle1_y += paddle1_dy;

			//call ball vs paddle1
			if (PixelCollision(paddle1_x, paddle1_y, 32, 32, bouncer_x, bouncer_y, 20, 100) == true) {
				//flip direction
				paddle1_dx = -paddle1_dx;
				paddle1_dy = -paddle1_dy;
				//play sound
				//increase score?
			}

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

			}
		}

		//RENDER SECTION!
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			b1.drawBrick();
			b2.drawBrick();
			b3.drawBrick();
			b4.drawBrick();
			b5.drawBrick();
			b6.drawBrick();
			b7.drawBrick();
			b8.drawBrick();
			b9.drawBrick();
			b10.drawBrick();
			b11.drawBrick();
			b12.drawBrick();
			b13.drawBrick();
			b14.drawBrick();
			b15.drawBrick();
			b16.drawBrick();
			b17.drawBrick();
			b18.drawBrick();
			/*b19.drawBrick();
			b20.drawBrick();*/
			al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			al_draw_bitmap(paddle1, paddle1_x, paddle1_y, 0);

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(paddle1);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}

//function definition
bool PixelCollision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if ((x1 + w1 > x2) && (x1 < x2 + w2) && (y1 + h1 > y2) && (y1 < h2 + y2))
		return true;
	else
		return false;
}

void brick::initBrick(int x, int y) {
	xPos = x;
	yPos = y;
}

void brick::drawBrick() {
	al_draw_filled_rectangle(xPos, yPos, xPos + 100,  yPos + 50, al_map_rgb(165, 42, 42));
}