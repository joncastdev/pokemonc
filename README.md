<h1 align="center">
  <br>
  <a href="https://sistemaspymesjc.blogspot.com/p/trabaja-con-nosotros.html">
    <img src="https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEj80lJ2YL2GVpJi0J9bSBGXtwbjx-JXLjA63ZLH5lRzxjuwxYHhXzsKpTU8rjLiAQPq07prlMOiW7c8XKh3Klv91Hf_CM9e8wpuHg7EiqZYNW6utWYKogRHdFTtUnsd4_CAKpMauAPWYMY5kzb18RZgrKzEUs4jgd7g4gJ807oqt5mGhaM2aSxw07wYV3w/s320/foroworkers_logo.png" alt="Foroworkers" width="150">
  </a>
  <br>
  Foroworkers
  <br>
</h1>

<a href="https://www.youtube.com/watch?v=r8JGzp6Sw28">
    <img class="flag-img" src="https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiWSy795FlYehw7LEY2lQJFSNPiHhqI2UuFIifVotedaJWTJJ8pH191WFWYSFZror7F7yx-EFJH0qDGvNcspCOeh7E3Y6a1PvoraqDlWkchS6d6JYQB4d7-jA4rJ2jXR1SVbUDbTl7_M8Xrxfrf4NJJKmwNN-33BShajZQ1oSJuIEQFgS5BiDk6OwBkkGk/s16000/foroworkers-featured.png" alt="Open Source Forum Laravel" width="100%">
</a>

## Introduction

The Foroworkers forum software is one of the open source projects using PHP and Laravel to manage self-hosted online communities on your server.

<p align="center">
  <img alt="GitHub" src="https://img.shields.io/github/license/foroworkers/foroworkers?style=for-the-badge">
  <img alt="GitHub release (latest by date)" src="https://img.shields.io/github/v/release/foroworkers/foroworkers?style=for-the-badge">
  <img alt="GitHub All Releases" src="https://img.shields.io/github/downloads/foroworkers/Foroworkers/total?style=for-the-badge">
  <a href="https://discord.gg/ntpz4aRHHy">
    <img alt="Chat On Discord" src="https://img.shields.io/badge/chat-on%20discord-7289da?style=for-the-badge&logo=discord&logoColor=white">
  </a>
</p>

<p align="center">
  <a href="#about">About</a> •
   <a href="#contributors">Contributors</a> •
  <a href="#features">Features</a> •
  <a href="#setup">Setup</a> •
  <a href="#installation">Installation</a> •
  <a href="#access"> Access</a> •
   <a href="#support"> Support</a> •
  <a href="#donations"> Donations</a> •
</p>

![screenshot](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEiNDC3xu3rZ4tvcYpn3oIfInzF_WIu-hjhN-0QXtTCMG8RxS2d1s2aTrx7E6pHpyigd07B55fxhiCHSHpviBF-yR86UrowIvdHwS6SckpM_geLwWOW39y1BO4nRAjxzGvCl-1-fxenX3R-QYz2NPUkdytXi7o-TI4zQjsba0pWmivt1PbAs7fMKpc1is6E/s16000/open-source-forum-laravel.png)

## About
A powerful Open Source Business Forum that can be installed on your server.Open source Laravel Forum

## Contributors
We thank everyone who contributes to this project.

* **Jonathan Castro** - *Software Engineer* - [jonathancastrodeveloper](https://github.com/jonathancastroccs)

## Starting

_These instructions will allow you to get a copy of the project running on your local machine for development and testing purposes._

## Demo  

* [Install Project ](https://www.udemy.com/course/laravel-13-desde-cero-con-html5-bootstrap-sql-javascript/?referralCode=934C989AB0AD8F563BC4)


## Setup

- PHP 8.3 >=
- PostgreSQL (Or MySQL)
- [Composer](https://getcomposer.org/)

## Additional details on dependencies

Assuming you're running Ubuntu, and then install all dependencies from the following list:

sudo apt-get install php8.3 php8.3-pgsql php8.3-mysql php8.3-intl php8.3-json php8.3-mbstring

## Installation

The following steps are meant to be used on a development server.

- Compilar proyecto

```bash
$ g++ pokemon.c -o pokemon $(pkg-config --cflags --libs allegro-5 allegro_main-5)
``` 


- Iniciar proyecto

```bash
$ ./pokemon
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



