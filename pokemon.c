#include <stdio.h>


// #include <allegro.h>

// biblioteca principal
#include <allegro5/allegro.h>

// estos son archivos de complementos
// hay complementos que no necesitas la cabezera
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_video.h>




// esta libreria es de c mas mas
#include <iostream>

int main() {
    // 1. Inicializar Allegro
	if (!al_init()) {
		return -1;
	}

    // 2. Crear la ventana (ancho, alto)
    // ALLEGRO_DISPLAY es un objetvo que devuelve esta funcion
    // *se declara una estructura
	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	if (!display) {
		return -1;
	}

	// inicializar eventos de mouse 
	al_install_mouse();

	// al_install_keyboard();

	// al_install_joystick();

	// inicializar imagenes, no me deja compilar
	 // al_init_image_addon();

	// printf("%s", *display);

	

	// return 0;




    // 3. Inicializar el módulo de entrada de eventos
al_install_keyboard();
ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();

// puntero
 // printf("%p", *queue);
 // return 0;

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
	// ALLEGRO_EVENT evento;

		// p es para punteros
	// printf("%p", &evento);

	// return 0;



		  // printf("Id: %d\n", evento);

// 		if (al_wait_event_timed(queue, &evento, 0.06)) {
// 		if (al_wait_for_event(queue, &evento)) {
// 				if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
// 					salir = true;
// 				}
// 			}
// }

    // 5. Destruir componentes y salir
al_destroy_display(display);
al_destroy_event_queue(queue);

getchar();
return 0;
}

}

