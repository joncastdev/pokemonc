// funciona

#include <stdio.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_font.h"

int main() {
	ALLEGRO_BITMAP *bitmap;
	ALLEGRO_FONT *font;
	bool done = false;
	bool active = true;
	bool fullscreen = false;

	al_init();
	al_install_keyboard();
	al_init_primitives_addon();
     // siempre inicializamos el complemento a usar
	al_init_image_addon();

	al_init_font_addon();

	

	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

	// para dibujar cualquier vaina primero crear el display
	al_clear_to_color(al_map_rgb(0, 0, 0));
	// siempre hay que cargar algo antes de dibujar
	font = al_load_font("fonts/DejaVuSans.ttf", 24, 0);
	al_draw_textf(font, al_map_rgb_f(1, 1, 1), 0, 0, 0,
		"Screen saver: %s", active ? "Normal" : "Inhibited");
	al_flip_display();
	// return 0;

 // bitmap = al_load_bitmap_flags("images/11.png", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_keyboard_event_source());

  // bitmap = al_load_bitmap_flags("images/charmander.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);
  //  al_draw_bitmap(bitmap, 255, 100, 0); 

	bool running = true;
	while (running) {
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

        // puntero espacio de memoria
        // printf("%p\n", &event);

        // printf("Tecla presionada: %d\n", event.keyboard.keycode); 

		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || 
			(event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
			running = false;
	}



        // se necesita esto para pintar el circulo
    // si no crea muchos circulos
	al_clear_to_color(al_map_rgb(0, 0, 0));

    // if (event.keyboard.keycode == 84)
    // {
    //     al_draw_filled_circle(320, 240, 50, al_map_rgb(255, 0, 0));
    // }

    // if (event.keyboard.keycode == 85)
    // {
    //     al_draw_filled_circle(420, 240, 50, al_map_rgb(255, 0, 0));
    // }

	switch (event.keyboard.keycode) {
	case 82:
        // printf("Tecla presionada: %d\n", event.keyboard.keycode);

   // printf("Pikachu yo te elijo");
               // al_clear_to_color(al_map_rgb(0, 0, 0));
   // al_draw_filled_circle(320, 240, 50, al_map_rgb(255, 255, 0));

		bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		al_draw_bitmap(bitmap, 255, 100, 0); 
		break;
	case 83:
       // printf("Tecla presionada: %d\n", event.keyboard.keycode);

   // printf("Bulbasaur yo te elijo");
               // al_clear_to_color(al_map_rgb(0, 0, 0));
   // al_draw_filled_circle(420, 240, 50, al_map_rgb(0, 255, 0)); 

		bitmap = al_load_bitmap_flags("images/bulbasaur.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		al_draw_bitmap(bitmap, 255, 100, 0); 
		break;
	case 84:
        // printf("Tecla presionada: %d\n", event.keyboard.keycode);
  // printf("Charizard yo te elijo");
  // al_draw_filled_circle(520, 440, 50, al_map_rgb(255, 0, 0));

		bitmap = al_load_bitmap_flags("images/charmander.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		al_draw_bitmap(bitmap, 255, 100, 0);  
		break;
	case 85:
       // printf("Tecla presionada: %d\n", event.keyboard.keycode);
  // printf("Squiertle yo te elijo");
  // al_draw_filled_circle(620, 340, 50, al_map_rgb(0, 0, 255));

		bitmap = al_load_bitmap_flags("images/squirtle.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		al_draw_bitmap(bitmap, 255, 100, 0);  
		break;
	default:
		printf("Esperando");
	}




        // al_clear_to_color(al_map_rgb(0, 0, 0));
        // al_draw_filled_circle(320, 240, 50, al_map_rgb(255, 0, 0));
	al_flip_display();
}

al_destroy_event_queue(queue);
al_destroy_bitmap(bitmap);
al_destroy_display(display);
return 0;
}