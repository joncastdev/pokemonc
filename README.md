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

- Pull Project Dev Branch

```bash
$ git pull dev
``` 
- Navigate to the root of the Laravel project

```bash
$ cd hudemyx
``` 
- Setup vendor libraries 

```bash
$ composer install
```

- Setup .env file, myconfig.php and create database
- Avoid changing the author data as this may cause problems when running the project.

- Copy .env.example config and generate Key project 

```bash
$ cp .env.example .env
``` 
```bash
$ php artisan key:generate
``` 

```bash
$ First Step Create New Database in myconfig.php file Example: foroworkers
  define('CDB_DATABASE_HOST', '');
  define('CDB_DATABASE_USERNAME', '');
  define('CDB_DATABASE_PASSWORD', '');
  define('CDB_DATABASE', '');
``` 

```bash
Second step Create New Database Example: foroworkers

APP_LOCALE=en
PAYPAL_EMAIL=yourpaypalemail
APP_ENDPOINT=https://sistemaspymesjc.online
APP_ENDPOINT_LOCAL=
APP_AUTHOR=jonathancastro
APP_EMAIL=sistemaspymesjc@gmail.com
APP_COPYRIGHT=sistemaspymesjc
APP_DONATE=https://www.paypal.com/paypalme/programadorjonathan
APP_PHONE=5804241666224

database connection

DB_DATABASE=your_database
DB_USERNAME=your_username
DB_PASSWORD=your_password

for sending emails example sandbox mailtrap

MAIL_MAILER=smtp
MAIL_HOST=sandbox.smtp.mailtrap.io
MAIL_PORT=2525
MAIL_USERNAME=yourusername
MAIL_PASSWORD=yourpass
MAIL_ENCRYPTION=tls
MAIL_FROM_ADDRESS="youremail@gmail.com"
MAIL_FROM_NAME="${APP_NAME}"
```

```bash
$ php spark db:create 
```
```bash
$ php spark migrate -all
```
```bash
$ php spark db:seed LoadSeeder
```
```bash
$ php artisan config:clear
``` 
- Run server

```bash
$ php artisan serve
```


## Access:

_Admin: admin@gmail.com
_Pass: Test1234

_User: user@gmail.com
_Pass: Test1234

## Technologies 🛠️

* [Laravel 13](https://laravel.com/docs/13.x)
* [Email Tool](https://mailtrap.io?ref=jonathan61)  
* [Hosting Tool](https://namecheap.pxf.io/rnOVB5) 


## Courses :movie_camera: 

* [Udemy](https://www.udemy.com/user/jonathan-castro-33/)    

## Author ✒️

* **Jonathan Castro** - *Web Developer* - [jonathancastrodeveloper](https://github.com/jonathancastroccs)


## Support

_foroworkers@istemaspymesjc.online_

* If you would like a business forum with many extra features, please contact us with your requirements and budget. Thank you.

## Donations

* [Paypal](https://www.paypal.com/paypalme/programadorjonathan) - Thank you very much for your contribution.

* [Ko-Fi](https://ko-fi.com/foroworkers) - Thank you very much for your contribution.

* [Patreon](https://www.patreon.com/c/foroworkers) - Thank you very much for your contribution.



