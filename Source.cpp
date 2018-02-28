#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h> 
int main() {
	al_init();
	al_init_primitives_addon(); 
	ALLEGRO_DISPLAY *display = al_create_display(500, 500);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_filled_circle(400, 100, 70, al_map_rgb(255, 255, 0));
	al_draw_filled_rectangle(165, 350, 335, 500, al_map_rgb(255, 0, 0));
	al_draw_filled_rectangle(225, 430, 275, 500, al_map_rgb(165, 42, 42));
	al_draw_filled_rectangle(185, 370, 225, 410, al_map_rgb(173, 216, 230));
	al_draw_filled_rectangle(275, 370, 315, 410, al_map_rgb(173, 216, 230));
	al_draw_filled_triangle(250, 225, 165, 350, 335, 350, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(20, 100, 220, 160, al_map_rgb(135, 206, 250));
	al_draw_filled_circle(70, 100, 50, al_map_rgb(135, 206, 250));
	al_draw_filled_circle(170, 100, 50, al_map_rgb(135, 206, 250));
	al_draw_filled_circle(120, 70, 50, al_map_rgb(135, 206, 250));
	al_draw_rectangle(185, 370, 225, 410, al_map_rgb(0, 0, 0), 1);
	al_draw_rectangle(275, 370, 315, 410, al_map_rgb(0, 0, 0), 1);
	al_draw_rectangle(165, 350, 335, 500, al_map_rgb(0, 0, 0), 1);
	al_draw_rectangle(225, 430, 275, 500, al_map_rgb(0, 0, 0), 1);
	al_flip_display();
	al_rest(10);
	al_destroy_display(display);
}
