#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// Estructura para guardar los datos dinámicamente
struct MemoryStruct {
  char *memory;
  size_t size;
};

// Función de callback que se ejecuta al recibir datos
static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;

  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(!ptr) {
    // Sin memoria suficiente
    printf("No se pudo asignar mas memoria\n");
    return 0;
  }

  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0; // Null-terminate

  return realsize;
}

int main(void) {
  CURL *curl_handle;
  CURLcode res;

  struct MemoryStruct chunk;
  chunk.memory = malloc(1);  // Empezar con 1 byte
  chunk.size = 0;    // Sin datos al inicio

  curl_global_init(CURL_GLOBAL_ALL);
  curl_handle = curl_easy_init();

  if(curl_handle) {
    curl_easy_setopt(curl_handle, CURLOPT_URL, "https://httpbin.org/get");
    
    // Asignar la función callback
    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    
    // Pasar la estructura como argumento a la callback
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&chunk);

    res = curl_easy_perform(curl_handle);

    if(res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() fallo: %s\n", curl_easy_strerror(res));
    } else {
      printf("%lu bytes recuperados\n", (unsigned long)chunk.size);
      printf("Respuesta:\n%s\n", chunk.memory);
    }

    curl_easy_cleanup(curl_handle);
    free(chunk.memory);
  }

  curl_global_cleanup();
  return 0;
}