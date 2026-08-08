#include <stdio.h>
#include <curl/curl.h>

int main(void) {
	CURL *curl;	
	CURLcode res;


    // Inicializar globalmente libcurl
	curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = curl_easy_init();

	if(curl) {
        // Indicar la URL a consultar
		curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8000/api/getcharacter");

        // Ejecutar la petición GET
		// res = curl_easy_perform(curl);

		res = curl_easy_perform(curl);

		// size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

		// CURLcode curl_easy_setopt(CURL *handle, CURLOPT_WRITEFUNCTION, write_callback);

		// CURLcode curl_easy_setopt(CURL *handle, CURLOPT_WRITEDATA, void *pointer);

        // Verificar si ocurrió algún error
		if(res != CURLE_OK) {
			fprintf(stderr, "Error en la petición: %s\n", curl_easy_strerror(res));
		}

        // Limpiar el manejador
		curl_easy_cleanup(curl);
	}

    // Finalizar el uso global de libcurl
	curl_global_cleanup();
	return 0;
}