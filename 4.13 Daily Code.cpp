Turn off for: English
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <ctime>
using namespace std;

const float FPS = 60;
const int SCREEN_W = 900;
const int SCREEN_H = 900;
const int BOUNCER_SIZE = 425;
class shelter
{
public:
	void initroom(int x, int y, ALLEGRO_BITMAP*image);
	void drawroom();
private:
	int xpos;
	int ypos;
	ALLEGRO_BITMAP*image;
	ALLEGRO_BITMAP*image2;
	ALLEGRO_BITMAP*image3;
	ALLEGRO_BITMAP*image4;
};

int main(int argc, char **argv)
{


	srand(time(NULL));
	al_init();
	al_init_primitives_addon();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	ALLEGRO_FONT *font = NULL;
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *bouncer = NULL;
	font = al_load_ttf_font("cubic.ttf", 20, 0);
	float bouncer_x = SCREEN_W / 2.0 - BOUNCER_SIZE / 2.0;
	float bouncer_y = SCREEN_H / 2.0 - BOUNCER_SIZE / 2.0;
	bool redraw = true;

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}

	if (!al_install_mouse()) {
		fprintf(stderr, "failed to initialize the mouse!\n");
		return -1;
	}

	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}

	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}

	bouncer = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE);
	if (!bouncer) {
		fprintf(stderr, "failed to create bouncer bitmap!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_bitmap(bouncer);
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_mouse_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	shelter b1;
	shelter b2;
	shelter b3;
	shelter b4;

	b1.initroom(10, 10, al_load_bitmap("nuke.jpg"));
	b2.initroom(10, 450, al_load_bitmap("power.png"));
	b3.initroom(450, 10, al_load_bitmap("res.jpg"));
	b4.initroom(450, 450, al_load_bitmap("water2.png"));

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_MOUSE_AXES ||
			ev.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {

			bouncer_x = ev.mouse.x;
			bouncer_y = ev.mouse.y;
		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			//top left
			if (ev.mouse.x < 410 && ev.mouse.x > 10 && ev.mouse.y < 310 && ev.mouse.y > 10) {
				al_draw_text(font, al_map_rgb(0, 250, 0), 225, 325, ALLEGRO_ALIGN_CENTER, "Nuka Cola plant");
				al_draw_rectangle(10, 10, 410, 310, al_map_rgb(0, 255, 0), 5);
				//bottom right
			}
			else if (ev.mouse.x < 850 && ev.mouse.x > 450 && ev.mouse.y < 675 && ev.mouse.y > 450) {
				al_draw_text(font, al_map_rgb(0, 250, 0), 675, 700, ALLEGRO_ALIGN_CENTER, "Water Treatment Station");
				al_draw_rectangle(450, 450, 850, 675, al_map_rgb(0, 255, 0), 5);
				//bottom left
			}
			else if (ev.mouse.x < 410 && ev.mouse.x > 10 && ev.mouse.y < 675 && ev.mouse.y > 450) {
				al_draw_text(font, al_map_rgb(0, 250, 0), 225, 700, ALLEGRO_ALIGN_CENTER, "Power Station");
				al_draw_rectangle(10, 450, 410, 675, al_map_rgb(0, 255, 0), 5);
				//top right
			}
			else if (ev.mouse.x < 850 && ev.mouse.x > 450 && ev.mouse.y < 310 && ev.mouse.y > 10) {
				al_draw_text(font, al_map_rgb(0, 250, 0), 675, 325, ALLEGRO_ALIGN_CENTER, "Residence");
				al_draw_rectangle(450, 10, 850, 310, al_map_rgb(0, 255, 0), 5);
			}

		}

		else if (ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
			//top left
			if (ev.mouse.x < 410 && ev.mouse.x > 10 && ev.mouse.y < 310 && ev.mouse.y > 10) {
				al_draw_text(font, al_map_rgb(0, 0, 0), 225, 325, ALLEGRO_ALIGN_CENTER, "Nuka Cola plant");
				al_draw_rectangle(10, 10, 410, 310, al_map_rgb(0, 0, 0), 5);
				//bottom right
			}
			else if (ev.mouse.x < 850 && ev.mouse.x > 450 && ev.mouse.y < 675 && ev.mouse.y > 450) {
				al_draw_text(font, al_map_rgb(0, 0, 0), 675, 700, ALLEGRO_ALIGN_CENTER, "Water Treatment Station");
				al_draw_rectangle(450, 450, 850, 675, al_map_rgb(0, 0, 0), 5);
				//bottom left
			}
			else if (ev.mouse.x < 410 && ev.mouse.x > 10 && ev.mouse.y < 675 && ev.mouse.y > 450) {
				al_draw_text(font, al_map_rgb(0, 0, 0), 225, 700, ALLEGRO_ALIGN_CENTER, "Power Station");
				al_draw_rectangle(10, 450, 410, 675, al_map_rgb(0, 0, 0), 5);
				//top right
			}
			else if (ev.mouse.x < 850 && ev.mouse.x > 450 && ev.mouse.y < 310 && ev.mouse.y > 10) {
				al_draw_text(font, al_map_rgb(0, 0, 0), 675, 325, ALLEGRO_ALIGN_CENTER, "Residence");
				al_draw_rectangle(450, 10, 850, 310, al_map_rgb(0, 0, 0), 5);
			}

		}
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;
			b1.drawroom();
			b2.drawroom();
			b3.drawroom();
			b4.drawroom();

			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}
void shelter::initroom(int x, int y, ALLEGRO_BITMAP*bitmap) {

	xpos = x;
	ypos = y;
	image = bitmap;

	//image 1
	//image 2

}
void shelter::drawroom() {
	al_draw_bitmap(image, xpos, ypos, 0);
}
