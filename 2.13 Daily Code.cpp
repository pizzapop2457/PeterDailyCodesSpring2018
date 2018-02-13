#include <allegro5/allegro.h>
#include<allegro5/allegro_primitives.h>

//constants
const float FPS = 60;


int main() {
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL; //clock for your game
	ALLEGRO_BITMAP *bouncer = NULL;
	ALLEGRO_BITMAP *bouncer2 = NULL;

	//bouncer position
	float bouncer_x = 200;
	float bouncer_y = 200;
	float bouncer2_x = 100;
	float bouncer2_y = 400;

	//bouncer speed
	float bouncer_dx = -4.0, bouncer_dy = 4.0;
	float bouncer2_dx = -10.0, bouncer2_dy = 10.0;

	bool redraw = true;

	al_init();
	al_init_primitives_addon();

	timer = al_create_timer(1.0 / FPS);     //mess with this for more or less lag ;)

	display = al_create_display(640, 480);

	bouncer = al_create_bitmap(32, 32); //use al_load_bitmap here for a pciture
	bouncer2 = al_create_bitmap(15, 15);

	//the next two lines go together
	al_set_target_bitmap(bouncer);

	al_clear_to_color(al_map_rgb(255, 0, 255)); //this sets the BOUNCER's color!

	al_set_target_bitmap(bouncer2);

	al_clear_to_color(al_map_rgb(255, 215, 0));

	al_set_target_bitmap(al_get_backbuffer(display));

	//the event queue is like a bucket where stuff that happens in your game goes
	event_queue = al_create_event_queue();

	//you need to tell the event queue what kinds of stuff to look out for
	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_clear_to_color(al_map_rgb(0, 0, 0)); //wipe screen

	al_flip_display();

	al_start_timer(timer); //start timer!

	while (1)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if (ev.type == ALLEGRO_EVENT_TIMER) {
			//bounce the square against the sides of the game window
			if (bouncer_x < 0 || bouncer_x > 640 - 32) {
				bouncer_dx = -bouncer_dx;
			}

			if (bouncer_y < 0 || bouncer_y > 480 - 32) {
				bouncer_dy = -bouncer_dy;
			}

			//add the x velocity to the x position, 
			//and the y velocity to the y position
			bouncer_x += bouncer_dx;
			bouncer_y += bouncer_dy;
			
			if (bouncer2_x < 0 || bouncer2_x > 640 - 32) {
				bouncer2_dx = -bouncer2_dx;
			}

			if (bouncer2_y < 0 || bouncer2_y > 480 - 32) {
				bouncer2_dy = -bouncer2_dy;
			}
			bouncer2_x += bouncer2_dx;
			bouncer2_y += bouncer2_dy;

			redraw = true;
		}
		//I/O section: close game window if x is pressed//////////////////////
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}

		//render section/////////////////////////////////////////////////////
		if (redraw && al_is_event_queue_empty(event_queue)) {
			redraw = false;

			//al_clear_to_color(al_map_rgb(0, 0, 0)); //wipes background clean

			//al_draw_bitmap(bouncer, bouncer_x, bouncer_y, 0);
			//al_draw_bitmap(bouncer2, bouncer2_x, bouncer2_y, 0);
			al_draw_filled_circle(bouncer_x, bouncer_y, 50, al_map_rgb(rand(), 50, 80));
			al_draw_filled_circle(bouncer2_x, bouncer2_y, 10, al_map_rgb(100, 50, rand()));
			al_draw_filled_circle(bouncer_x, bouncer2_y, 25, al_map_rgb(rand(), 50, rand()));

			al_draw_filled_circle(bouncer2_x, bouncer_y, 20, al_map_rgb(rand(), rand(), rand()));
			al_flip_display();
		}
	}

	al_destroy_bitmap(bouncer);
	al_destroy_bitmap(bouncer2);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}