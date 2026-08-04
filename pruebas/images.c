/* Image conversion example */

#include <stdio.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

// #include "common.c"


int main()
{
   ALLEGRO_BITMAP *bitmap;


   al_init();

   // siempre inicializamos el complemento a usar
   al_init_image_addon();

   // primero cargar el display si no no carga lo demas
   ALLEGRO_DISPLAY *display = al_create_display(640, 480);

   // al_load_bitmap("j.jpeg")

   // ALLEGRO_BITMAP *bitmap =  al_load_bitmap("j.jpeg");

   // bitmap = al_load_bitmap_flags("images/11.png", ALLEGRO_NO_PREMULTIPLIED_ALPHA);
   bitmap = al_load_bitmap_flags("images/11.png", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

   // siempre es x y la posicion en la pantalla
   // al_draw_bitmap(bitmap, x, y, 0);
   al_draw_bitmap(bitmap, 255, 100, 0);


   al_flip_display();
   al_destroy_bitmap(bitmap);
   al_destroy_display(display);


   

   return 0;
}
