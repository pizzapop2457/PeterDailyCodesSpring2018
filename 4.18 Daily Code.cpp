#include <allegro5/allegro.h> //helper libraries
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_audio.h>
#include <iostream>
#include <fstream>

using namespace std;

const float FPS = 60;
const int SCREEN_W = 700; //display size
const int SCREEN_H = 500;
const int BOUNCER_SIZE = 20;
const int BOUNCER2_SIZE = 20;
enum MYKEYS { //key inputs
	KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
enum MYKEYS2 {
	KEY_W, KEY_S, KEY_A, KEY_D
};

//function declaration
bool Collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);

int main()
{ //starting main
	int player1 = 0; //declare
	int player2 = 0;
	ALLEGRO_DISPLAY *display = NULL; //creates variables
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	ALLEGRO_TIMER *timer = NULL;
	ALLEGRO_BITMAP *paddle1 = NULL;
	ALLEGRO_BITMAP *paddle2 = NULL;
	ALLEGRO_BITMAP *ball = NULL;
	ALLEGRO_FONT *font = NULL;
	ALLEGRO_SAMPLE *sample = NULL;
	ALLEGRO_SAMPLE *sample2 = NULL;

	float paddle1_x = 600; //position of paddles
	float paddle1_y = 250;
	float paddle2_x = 80;
	float paddle2_y = 250;
	float ball_x = 200; //position of the ball
	float ball_y = 200;
	float ball_dx = -4.0, ball_dy = 4.0;
	bool key[4] = { false, false, false, false };
	bool key2[4] = { false, false, false, false };
	bool redraw = true;
	bool doexit = false;

	al_init();
	al_init_acodec_addon(); //initalize helper libraries
	al_init_font_addon();
	al_init_image_addon();
	al_init_ttf_addon();
	al_install_audio();
	al_install_keyboard();
	al_set_window_title(display, "PONG"); //window title
	timer = al_create_timer(1.0 / FPS);
	font = al_load_ttf_font("Pokemon Hollow.ttf", 50, 0);
	display = al_create_display(SCREEN_W, SCREEN_H); //size of display

	paddle1 = al_create_bitmap(BOUNCER_SIZE, BOUNCER_SIZE + 80); //size of paddle

	paddle2 = al_create_bitmap(BOUNCER2_SIZE, BOUNCER2_SIZE + 80);

	ball = al_load_bitmap("Pokeball.png");
	al_convert_mask_to_alpha(ball, al_map_rgb(255, 255, 255)); //clears background to transparent

	al_set_target_bitmap(paddle1);

	al_clear_to_color(al_map_rgb(255, 255, 0)); //this changes the color of the paddles/ball

	al_set_target_bitmap(paddle2);

	al_clear_to_color(al_map_rgb(0, 255, 255));
	//al_clear_to_color(al_map_rgb(178, 34, 34));

	al_set_target_bitmap(al_get_backbuffer(display));

	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_display_event_source(display));

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(0, 0, 0));

	al_flip_display();

	al_start_timer(timer);

	ifstream inFile;
	int topScores[5];
	inFile.open("save.txt");
	for (int i = 0; i < 5; i++)
		inFile >> topScores[i];

	for (int i = 0; i < 5; i++)
		cout << topScores[i] << endl;

	al_draw_text(font, al_map_rgb(250, 250, 255), 350, 10, ALLEGRO_ALIGN_CENTER, "TOP SCORES");
	for (int i = 0; i < 5; i++)
	al_draw_textf(font, al_map_rgb(255, 255, 255), 350, 75 + i * 65, ALLEGRO_ALIGN_CENTER, "%d", topScores[i]);
	al_flip_display();
	al_rest(5);

	al_reserve_samples(2);

	sample = al_load_sample("sound.wav"); //loading in the sound files
	sample2 = al_load_sample("sound2.wav");
	while (!doexit)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			if (key[KEY_UP] && paddle1_y >= 4.0) { //stops the paddle from going out of the display
				paddle1_y -= 4.0; //speed of the paddle
			}

			if (key[KEY_DOWN] && paddle1_y <= SCREEN_H - 100 - 4.0) {
				paddle1_y += 4.0;
			}

			//if (key[KEY_LEFT] && paddle1_x >= 4.0) {
			//	paddle1_x -= 4.0;
			//}

			//if (key[KEY_RIGHT] && paddle1_x <= SCREEN_W - BOUNCER_SIZE - 4.0) {
			//	paddle1_x += 4.0;
			//}
			if (key2[KEY_W] && paddle2_y >= 4.0) {
				paddle2_y -= 4.0;
			}

			if (key2[KEY_S] && paddle2_y <= SCREEN_H - 100 - 4.0) {
				paddle2_y += 4.0;
			}

			//if (key2[KEY_A] && paddle2_x >= 4.0) {
			//	paddle2_x -= 4.0;
			//}

			//if (key2[KEY_D] && paddle2_x <= SCREEN_W - BOUNCER2_SIZE - 4.0) {
			//	paddle2_x += 4.0;
			//}

			if (ball_x <= 0 || ball_x >= 700 - 32) {
				ball_dx = -ball_dx;

			}
			if (ball_x <= 0) {
				player2++;
				al_play_sample(sample, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
			if (ball_x >= 700 - 32) {
				player1++;
				al_play_sample(sample, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
			}
			//repeat for above two lines

			if (ball_y < 0 || ball_y > 500 - 32) {
				ball_dy = -ball_dy;

			}
			if (ball_y <= 500)

				ball_x += ball_dx;
			ball_y += ball_dy;

			//call ball vs paddle1
			if (Collision(ball_x, ball_y, 32, 32, paddle1_x, paddle1_y, 20, 100) == true) {
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				al_play_sample(sample2, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
			}

			//call ball vs paddle2
			if (Collision(ball_x, ball_y, 32, 32, paddle2_x, paddle2_y, 20, 100) == true) {
				ball_dx = -ball_dx;
				ball_dy = -ball_dy;
				al_play_sample(sample2, 1.0, 0.0, 1, ALLEGRO_PLAYMODE_ONCE, NULL);
			}

			redraw = true;
		}
		else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = true;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = true; //same as writing key[1] = true;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = true;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = true;
				break;

			case ALLEGRO_KEY_W:
				key2[KEY_W] = true;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = true;
				break;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = true;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = true;
				break;
			}
		}
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_UP:
				key[KEY_UP] = false;
				break;

			case ALLEGRO_KEY_DOWN:
				key[KEY_DOWN] = false;
				break;

			case ALLEGRO_KEY_LEFT:
				key[KEY_LEFT] = false;
				break;

			case ALLEGRO_KEY_RIGHT:
				key[KEY_RIGHT] = false;
				break;

			case ALLEGRO_KEY_ESCAPE:
				doexit = true;
				break;

			case ALLEGRO_KEY_W:
				key2[KEY_W] = false;
				break;

			case ALLEGRO_KEY_S:
				key2[KEY_S] = false;
				break;

			case ALLEGRO_KEY_A:
				key2[KEY_A] = false;
				break;

			case ALLEGRO_KEY_D:
				key2[KEY_D] = false;
				break;


			}
		}




		if (redraw && al_is_event_queue_empty(event_queue)) { //if statement
			redraw = false;
			//render section
			al_clear_to_color(al_map_rgb(0, 0, 0));
			al_draw_bitmap(paddle1, paddle1_x, paddle1_y, 0);
			al_draw_bitmap(paddle2, paddle2_x, paddle2_y, 0);
			al_draw_bitmap(ball, ball_x, ball_y, 0);
			al_draw_textf(font, al_map_rgb(255, 255, 255), 160, 10, ALLEGRO_ALIGN_CENTRE, "%d", player1);
			al_draw_textf(font, al_map_rgb(255, 255, 255), 560, 10, ALLEGRO_ALIGN_CENTRE, "%d", player2);
			al_flip_display();
		} //end of if statement
	} //end of while loop



	al_destroy_bitmap(paddle1);
	al_destroy_bitmap(paddle2);
	al_destroy_bitmap(ball);
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
} //end of main

//function definition
bool Collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2) {
	if ((x1 + w1 > x2) && (x1 < x2 + w2) && (y1 + h1 > y2) && (y1 < h2 + y2))
		return true;
	else
		return false;
}
