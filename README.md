## Installation

The following steps are meant to be used on a development server.

- Compilar proyecto

```bash
$ g++ pokemon.c -o pokemon $(pkg-config --cflags --libs allegro-5 allegro_main-5)
``` 
- Enlazar bien las librerias

```bash
 g++ pokemon.c -o pokemon $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5)
``` 

```bash
 g++ pokemon.c -o pokemon $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5)
``` 

```bash
 g++ pokemon.c -o pokemon $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5  allegro_font-5)
``` 

```bash
 g++ -o conexion conexion.c $(mysql_config --cflags --libs)
``` 

```bash
 g++  http.c -o http -lcurl
``` 

```bash
 g++ -I/usr/include/jsoncpp jsoncpp.cpp -ljsoncpp
```

```bash
 g++ -I/usr/include/jsoncpp jsoncpp.c -ljsoncpp
```  

```bash
 g++ http.c -o http $(pkg-config --cflags --libs -lcurl)

```bash
 g++ pokemondb.c -o pokemondb $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 mysqlclient)
``` 

```bash
 g++ pokemondb.c -o pokemondb $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 libcurl)
``` 

- Compilar proyecto en lenguaje c jsonc #include <json-c/json.h>
```bash
gcc json.c -o json $(pkg-config --cflags --libs json-c)
``` 
- Forma directa, aqui la diferencia es la letra l y luego nombre libreria 
```bash
 gcc json.c -o json -ljson-c
``` 

- Compilar proyecto en lenguaje cpp jsonc #include #include <json/json.h>
```bash
g++ jsoncpp.c -o jsoncpp $(pkg-config --cflags --libs jsoncpp)
``` 
- Forma directa, aqui la diferencia es la letra l y luego nombre libreria 
```bash
 g++ jsoncpp.c -o jsoncpp -ljsoncpp 

- Iniciar proyecto

```bash
$ ./pokemon
``` 

- Funciona con varias librerias #include <json/json.h>
```bash
g++ jsonapi.c -o jsonapi $(pkg-config --cflags --libs jsoncpp libcurl)
``` 

```bash
 g++ best.c -o o $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 jsoncpp libcurl)
``` 

```bash
 g++ display2.c -o o $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5 jsoncpp libcurl)
``` 

```bash
 g++ ex_disable_screensaver.c -o o $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5 jsoncpp libcurl)
``` 

```bash
 g++ ex_bitmap.c -o o $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5 jsoncpp libcurl)
``` 

```bash
 g++ ex_mouse_events.c -o o $(pkg-config --cflags --libs allegro-5 allegro_main-5 allegro_primitives-5 allegro_image-5 allegro_font-5 jsoncpp libcurl)
``` 





