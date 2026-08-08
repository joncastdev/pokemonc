// #include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"



int main() {

	// ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *bitmap;
	bool running = true;

	al_init();
	al_init_image_addon();


	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	// al_create_display(640, 480);

	// aquui hacemos a la estructura
	// printf("%p\n", &display);

	// printf("Tecla presionada: %d\n", ALLEGRO_DISPLAY);

	// hay que crear un ciclo para que la pantalla no se salga
	while (running) {

		bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);		

		al_draw_bitmap(bitmap, 255, 100, 0);

		// esto borra lo que se crea antes
		al_clear_to_color(al_map_rgb(0, 0, 0));

		bitmap = al_load_bitmap_flags("images/bulbasaur.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		al_draw_bitmap(bitmap, 355, 100, 0);

		// al_clear_to_color(al_map_rgb(0, 0, 0));  

		// si se usa fuera del ciclo se queda pegado
		al_flip_display();
	}



	

	return 0;
}