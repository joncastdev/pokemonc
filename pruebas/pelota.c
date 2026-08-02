// funciona

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int main() {
    al_init();
    al_install_keyboard();
    al_init_primitives_addon();

    ALLEGRO_DISPLAY *display = al_create_display(640, 480);
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    
    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_keyboard_event_source());

    bool running = true;
    while (running) {
        ALLEGRO_EVENT event;
        al_wait_for_event(queue, &event);

        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE || 
            (event.type == ALLEGRO_EVENT_KEY_DOWN && event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)) {
            running = false;
        }

        al_clear_to_color(al_map_rgb(0, 0, 0));
        al_draw_filled_circle(320, 240, 50, al_map_rgb(255, 0, 0));
        al_flip_display();
    }

    al_destroy_event_queue(queue);
    al_destroy_display(display);
    return 0;
}