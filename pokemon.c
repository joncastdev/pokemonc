#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

// esta libreria es de c mas mas
#include <iostream>

int main() {
    // 1. Inicializar Allegro
	if (!al_init()) {
		return -1;
	}

    // 2. Crear la ventana (ancho, alto)
	ALLEGRO_DISPLAY *display = al_create_display(640, 480);
	if (!display) {
		return -1;
	}

    // 3. Inicializar el módulo de entrada de eventos
	al_install_keyboard();
	ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(display));

    // 4. Bucle principal del juego
	bool salir = false;
	while (!salir) {
        // Pintar el fondo de color azul
		al_clear_to_color(al_map_rgb(0, 0, 255));

        // Actualizar la pantalla
		al_flip_display();

        // Manejar eventos (como cerrar la ventana o presionar una tecla)
		ALLEGRO_EVENT evento;

		

		  // printf("Id: %d\n", evento);

		// if (al_wait_event_timed(queue, &evento, 0.06)) {
		// if (al_wait_for_event(queue, &evento)) {
		// 		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		// 			salir = true;
		// 		}
		// 	}
		}

    // 5. Destruir componentes y salir
		al_destroy_display(display);
		al_destroy_event_queue(queue);

		getchar();
		return 0;
	}