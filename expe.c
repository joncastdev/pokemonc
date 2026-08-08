// cuando empieza por s es librerias de c
#include <stdio.h>
#include  <stdlib.h>
#include <string.h>

// para usar malloc
// pero esto es para c mas mas
// #include <cstdlib>

// esta es para usar ""
// pero esto es para c mas mas
// #include <cstring>

#include <curl/curl.h>

struct Cadena
{
	size_t longitud;
	char *datos;
	char data[50];
};

void iniciarCadena(struct Cadena *cadena)
{
	cadena->longitud = 0;
	cadena->datos = malloc(1);
	cadena->datos[cadena->longitud] = '\0';
}

void concatenar(struct Cadena *cadena, char *otraCadena)
{
	size_t longitudDeOtraCadena = strlen(otraCadena);
	size_t nuevaLongitud = cadena->longitud + longitudDeOtraCadena;
	size_t nuevaLongitudConByteNulo = nuevaLongitud + 1;
	size_t longitudDeOtraCadenaIncluyendoByteNulo = longitudDeOtraCadena + 1;
	char *cadenaConNuevaLongitud = realloc(cadena->datos, nuevaLongitudConByteNulo);
	if (cadenaConNuevaLongitud == NULL)
	{
		printf("Sin memoria suficiente para concatenar la nueva cadena");
		return;
	}
	cadena->datos = cadenaConNuevaLongitud;
	memcpy((char *)(cadena->datos + cadena->longitud), otraCadena, longitudDeOtraCadenaIncluyendoByteNulo);
	cadena->longitud = nuevaLongitud;
}

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	// Esta función podría ser invocada varias veces por cURL. https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
	size_t realsize = size * nmemb;
	concatenar((struct Cadena *)userp, (char *)contents);
	concatenar((struct Cadena *)userp, "");
	return realsize;
}

int main(void) {
	CURL *curl;	
	CURLcode res;


    // Inicializar globalmente libcurl
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl) {

		struct Cadena *miCadena = (struct Cadena *)malloc(sizeof(struct Cadena));

		iniciarCadena(miCadena);
        // Indicar la URL a consultar
		curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8000/api/getcharacter");
		// curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)miCadena);

        // Ejecutar la petición GET
		// res = curl_easy_perform(curl);

		res = curl_easy_perform(curl);

		if (res == CURLE_OK)
		{

			// while (res) {
			// 	printf("ID: %s, Character_name: %s\n", res, res);
			// }

			// struct Cadena c;

			// strcpy(c.data, miCadena->datos);

			// printf("Data: %s\n", c.data);

			// printf("La respuesta es: %p", miCadena->datos);
			printf("La respuesta es: %s", miCadena->datos);
			// printf("La respuesta es: %c", miCadena->datos);
			// printf("La respuesta es: %d", miCadena->datos);
			// printf("La respuesta es: %s", miCadena->datos);
		}
		else
		{
			fprintf(stderr, "Error en la petición: %s\n", curl_easy_strerror(res));
		}

        // Limpiar el manejador
		curl_easy_cleanup(curl);
	}

    // Finalizar el uso global de libcurl
	curl_global_cleanup();
	return 0;
}