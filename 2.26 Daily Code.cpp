#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <iostream>
#include <ctime>
using namespace std;
int main() {
	srand(time(NULL));
	ALLEGRO_DISPLAY *gamewindow = NULL;
	al_init();
	al_init_primitives_addon();
	gamewindow = al_create_display(800, 800);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	while (1) {
	al_draw_circle(rand()%790, rand()%790, rand()%790, al_map_rgb(rand(), rand(), rand()), rand()%50);
	al_draw_filled_circle(rand()%790, rand()%790, rand()%300, al_map_rgb(rand(), rand(), rand()));
	al_draw_triangle(rand() % 790, rand() % 790, rand() % 790, rand() % 790, rand() % 790, rand() % 790, al_map_rgb(rand(), rand(), rand()), rand() % 50);
	al_draw_rectangle(rand() % 790, rand() % 790, rand() % 790, rand() % 790, al_map_rgb(rand(), rand(), rand()), rand() % 50);
	al_draw_filled_rectangle(rand() % 790, rand() % 790, rand() % 790, rand() % 790, al_map_rgb(rand(), rand(), rand()));
	al_flip_display();
	al_rest(.001);
	}
	al_destroy_display(gamewindow);
}