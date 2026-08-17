// #include <mysql.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"

#include "common.c"




int main() {

	// ALLEGRO_DISPLAY *display;
	ALLEGRO_BITMAP *bitmap;
	ALLEGRO_FONT *font;
	// ALLEGRO_COLOR color, black, red, blue, green;
	// por defecto toma el color rojo
	// ALLEGRO_COLOR red;
	ALLEGRO_COLOR blackClean;
	// se declaran para usarlas
	ALLEGRO_COLOR black;
	ALLEGRO_COLOR yellow;
	ALLEGRO_COLOR green;
	// para obtener posicion mouse
	ALLEGRO_MOUSE_STATE state;

	int score = 150;
	bool active = true;
	bool running = true;

	//usamos negro para limpiar la pantalla
	blackClean = al_map_rgb(0, 0, 0);
	black = al_map_rgb(0, 0, 0);
	yellow = al_map_rgb(255, 255, 0);
	green = al_map_rgb(0, 255, 0);

	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_init_font_addon();
	al_init_image_addon();
	al_init_primitives_addon();
	// al_install_mouse();
	// al_install_keyboard();
	// al_init_font_addon();


	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
	// ALLEGRO_DISPLAY *display = al_create_display(1366, 768);
	// al_destroy_display(display);
	// ALLEGRO_DISPLAY *display2 = al_create_display(740, 580);

	// std::cout << font << std::endl;

	// return 1;

	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());

	
	

	 // Initializes and displays a log window for debugging purposes.
	open_log();

	// al_draw_textf(font, al_map_rgb(255, 255, 255), 255, 100, 0, "Puntuaje: %s", "h");



	// hay que crear un ciclo para que la pantalla no se salga
	while (running) {

		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		al_get_mouse_state(&state);

		if (state.buttons & 1) {
    // El botón izquierdo está presionado
			printf("Posicion X: %d, Y: %d\n", state.x, state.y);
		}

		switch (event.type) {
		case ALLEGRO_EVENT_KEY_UP:

			// std::cout << event.keyboard.keycode << std::endl;
			// std::cout << event.keyboard.unichar << std::endl;
			// std::cout << event.keyboard.modifiers << std::endl;
			break;         


		// esto se activa cuando cierras la ventana	
		case ALLEGRO_EVENT_DISPLAY_CLOSE:
		// case ALLEGRO_EVENT_KEY_CHAR:
			goto done;
		}

		// bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		//  al_draw_bitmap(bitmap, 255, 100, 0);

		// std::cout << bitmap << std::endl;

		al_clear_to_color(blackClean);

		al_draw_filled_rectangle(2000,200, 10,10, yellow);

		// al_draw_rectangle(x + 0.5, y + 0.5, x + 26.5, y + 41.5, black, 0);

		// al_clear_to_color(blackClean);

		al_draw_filled_circle(event.mouse.x, event.mouse.y, 10, green);

		if (event.mouse.x == 628)
		{
			std::cout << "posicion:" + event.mouse.x << std::endl;
			al_clear_to_color(blackClean);
		}

		// con el mouse se mueve es raro
		// al_draw_filled_circle(event.keyboard.keycode, 0, 10, green);

		// al_clear_to_color(blackClean);
		

		// si se usa fuera del ciclo se queda pegado
		al_flip_display();
	}
	done:


	
	al_destroy_event_queue(queue);
	return 0;
}