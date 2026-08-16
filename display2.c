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
	ALLEGRO_COLOR color, black, red, blue;
	int score = 150;
	bool active = true;
	bool running = true;

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

    // al_register_event_source(queue, al_get_display_event_source(display));
    // al_register_event_source(queue, al_get_keyboard_event_source());


	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));

	 // Initializes and displays a log window for debugging purposes.
	open_log();

	// al_draw_textf(font, al_map_rgb(255, 255, 255), 255, 100, 0, "Puntuaje: %s", "h");



	// hay que crear un ciclo para que la pantalla no se salga
	while (running) {

		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		switch (event.type) {
		case ALLEGRO_EVENT_MOUSE_AXES:
            // mx = event.mouse.x;
            // my = event.mouse.y;
            // mz = event.mouse.z;
            // mw = event.mouse.w;
            // mmx = event.mouse.dx;
            // mmy = event.mouse.dy;
            // mmz = event.mouse.dz;
            // mmw = event.mouse.dw;
            // p = event.mouse.pressure;
			std::cout << event.mouse.x << std::endl;
			break;

         // case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
         //    if (event.mouse.button-1 < NUM_BUTTONS) {
         //       buttons[event.mouse.button-1] = true;
         //    }
         //    p = event.mouse.pressure;
         //    break;



		case ALLEGRO_EVENT_DISPLAY_CLOSE:
			goto done;
		}



		// std::cout << event.mouse.button << std::endl;
		// std::cout << event.mouse.pressure << std::endl;



		// event.keyboard.keycode
		// event.mouse.button
		// event.mouse.pressure

		// if (event.keyboard.keycode == 84)
		// {
		// 	al_draw_filled_circle(320, 240, 50, al_map_rgb(255, 0, 0));
		// }

		al_draw_filled_circle(event.mouse.x, event.mouse.y, 10, al_map_rgb(0,255, 0));

		// aqui seria para pintar se mueve por toda la pantalla
		// bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		// al_draw_bitmap(bitmap, event.mouse.x, event.mouse.y, 0);

		//Superior izquierda:
		// al_draw_bitmap(bitmap, 0, 0, 0);

		// bitmap = al_load_bitmap_flags("images/bulbasaur.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		// //Superior derecha
		// al_draw_bitmap(bitmap, 639, 0, 0);

		// bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);		
		// //Inferior izquierda:
		// al_draw_bitmap(bitmap, 0, 767, 0);

		// bitmap = al_load_bitmap_flags("images/bulbasaur.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		// //Inferior derecha
		// al_draw_bitmap(bitmap, 1365, 767, 0);


		// al_draw_textf(font, blue, 8, 8, 0, "Display events (newest on top)");

		// al_clear_to_color(al_map_rgb(0, 0, 0));
		// al_draw_textf(font, al_map_rgb_f(1, 1, 1), 0, 0, 0,
		// 	"Screen saver: %s", active ? "Normal" : "Inhibited");

		// al_draw_textf(font, al_map_rgb(255, 255, 255), 10, 10, 0, "Puntuaje: %d", 1);

		// al_draw_textf(font, al_map_rgb(255, 255, 255), 255, 90, ALLEGRO_ALIGN_CENTRE, "Puntuaje: %d", score);

		// al_clear_to_color(al_map_rgb(0, 0, 0));

		// bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);		

		// al_draw_bitmap(bitmap, 255, 100, 0);



		// // esto borra lo que se crea antes
		// al_clear_to_color(al_map_rgb(0, 0, 0));

		// bitmap = al_load_bitmap_flags("images/bulbasaur.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		// al_draw_bitmap(bitmap, 355, 100, 0);

		// al_clear_to_color(al_map_rgb(0, 0, 0));  

		// si se usa fuera del ciclo se queda pegado
		al_flip_display();
	}
	done:


	
	al_destroy_event_queue(queue);
	return 0;
}