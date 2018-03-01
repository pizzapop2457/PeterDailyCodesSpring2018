#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h> 
int main() {
	al_init();
	al_init_primitives_addon(); 
	ALLEGRO_DISPLAY *display = al_create_display(800, 500);
	al_clear_to_color(al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(50, 150, 400, 400, al_map_rgb(255, 182, 193));
	al_draw_rectangle(50, 150, 400, 400, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(350, 100, 650, 370, al_map_rgb(255, 182, 193));
	al_draw_rectangle(350, 100, 650, 370, al_map_rgb(0,0,0), 1);
	al_draw_filled_rectangle(350, 175, 400, 225, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(400, 175, 450, 225, al_map_rgb(255, 255, 255));
	al_draw_rectangle(350, 175, 450, 225, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(550, 175, 600, 225, al_map_rgb(255, 255, 255));
	al_draw_filled_rectangle(600, 175, 650, 225, al_map_rgb(0, 0, 0));
	al_draw_rectangle(550, 175, 650, 225, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(420, 250, 580, 320, al_map_rgb(255, 192, 203));
	al_draw_filled_rectangle(420, 270, 450, 300, al_map_rgb(255, 105, 180));
	al_draw_filled_rectangle(550, 270, 580, 300, al_map_rgb(255, 105, 180));	
	al_draw_rectangle(420, 250, 580, 320, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(50, 400, 100, 475, al_map_rgb(255, 182, 193));
	al_draw_rectangle(50, 400, 100, 475, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(52, 450, 72, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(78, 450, 97, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(120, 400, 170, 475, al_map_rgb(255, 182, 193));
	al_draw_rectangle(120, 400, 170, 475, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(122, 450, 142, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(147, 450, 167, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(400, 400, 350, 475, al_map_rgb(255, 182, 193));
	al_draw_rectangle(400, 400, 350, 475, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(352, 450, 372, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(377, 450, 397, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(330, 400, 280, 475, al_map_rgb(255, 182, 193));
	al_draw_rectangle(330, 400, 280, 475, al_map_rgb(0, 0, 0), 1);
	al_draw_filled_rectangle(282, 450, 302, 475, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(307, 450, 327, 475, al_map_rgb(0, 0, 0));
	
	al_flip_display();
	al_rest(20);
	al_destroy_display(display);
}
