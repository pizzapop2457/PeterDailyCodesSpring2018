#include <iostream>
#include <ctime>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5/allegro_image.h>

using namespace std;

const float FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 1000;

int main() {
	srand(time(NULL));
	int level[10][10] = {
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,	rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,rand() % 4 + 1,
	};

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << level[i][j];
		}
		cout << endl;
	}

	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *Christian = NULL;
	ALLEGRO_BITMAP *Matt = NULL;
	ALLEGRO_BITMAP *Moe = NULL;
	ALLEGRO_BITMAP *Wade = NULL;

	bool redraw = true;
	bool doexit = false;

	al_init();

	al_init_image_addon();
	al_init_primitives_addon();

	timer = al_create_timer(1.0 / FPS);
	display = al_create_display(SCREEN_W, SCREEN_H);

	Christian = al_load_bitmap("Christian2.jpg");
	al_set_target_bitmap(Christian);
	al_convert_mask_to_alpha(Christian, al_map_rgb(255, 255, 255));

	Matt = al_load_bitmap("Matt2.jpg");
	al_set_target_bitmap(Matt);
	al_convert_mask_to_alpha(Matt, al_map_rgb(255, 255, 255));

	Moe = al_load_bitmap("Moe2.jpg");
	al_set_target_bitmap(Moe);
	al_convert_mask_to_alpha(Moe, al_map_rgb(255, 255, 255));

	Wade = al_load_bitmap("Wade2.jpg");
	al_set_target_bitmap(Wade);
	al_convert_mask_to_alpha(Wade, al_map_rgb(255, 255, 255));

	al_set_target_bitmap(al_get_backbuffer(display));
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (level[i][j] == 1)
						al_draw_bitmap(Christian, i * 100, j * 100, 0);
					else if (level[i][j] == 2)
						al_draw_bitmap(Matt, i * 100, j * 100, 0);
					else if (level[i][j] == 3)
						al_draw_bitmap(Moe, i * 100, j * 100, 0);
					else if (level[i][j] == 4)
						al_draw_bitmap(Wade, i * 100, j * 100, 0);
				}
			}
			al_flip_display();
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}