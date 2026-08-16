// #include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#include <string>  
#include <iostream>

#include <curl/curl.h>
// Json:: se declara
#include <json/json.h>

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
// para poder usar cout
using namespace std;

// 1. Define the callback function to handle incoming data chunks
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
	size_t totalSize = size * nmemb;
	std::string* responseString = static_cast<std::string*>(userp);
	responseString->append(static_cast<char*>(contents), totalSize);
	return totalSize;
}



// Json::Value crearDatos(std::string baseUrl, std::string characterName, int id) {
Json::Value crearDatos(std::string segment) {

	std::string baseUrl = "http://127.0.0.1:8000/";
	std::string endpoint = baseUrl + segment;	
	

	CURL* curl = curl_easy_init();

	//  std::cout << baseUrl << std::endl;

	// return 1;

	if (!curl) {
		std::cerr << "Failed to initialize cURL." << std::endl;
		return 1;
	}

	std::string responseBody;
	long httpCode = 0;    

    // 2. Set the target API URL	
	// espera por defecto char por eso se ysa la funcion
	curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());


    // 3. Set up the header to request JSON data
	struct curl_slist* headers = nullptr;
	headers = curl_slist_append(headers, "Accept: application/json");
	curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // 4. Pass our callback function to capture the body data
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

    // 5. Pass the address of our string where data will be stored
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBody);

    // 6. Perform the synchronous network request
	CURLcode res = curl_easy_perform(curl);

    // 7. Check for network errors and verify HTTP response code
	if (res != CURLE_OK) {
		std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
	} else {
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);

		if (httpCode == 200) {

            // char data[10] =  {responseBody};
			std::cout << "Successfully retrieved JSON response:\n" << responseBody << std::endl;          
            // You can now pass 'responseBody' to a JSON parser like nlohmann/json or JsonCpp

		} else {
			std::cerr << "HTTP Error Code: " << httpCode << std::endl;
		}
	}

	// aqui es string
	std::string json_str = responseBody;

    // std::cout << "Data response: " << json_str.data() << "\n";

    // return json_str.data();

	Json::Value raiz;
	Json::CharReaderBuilder lector;
	std::string errs;

    // aqui ocurre el parse del response
	std::unique_ptr<Json::CharReader> const reader(lector.newCharReader());
	bool ok = reader->parse(json_str.data(), json_str.data() + json_str.size(), &raiz, &errs);

	return raiz;

}


int main() {
	ALLEGRO_BITMAP *bitmap;
	bool running = true;

	al_init();
	al_init_image_addon();


	ALLEGRO_DISPLAY *display = al_create_display(640, 480);

	// aqui ya tenemos el json parseado
	Json::Value resultado = crearDatos("api/getcreatures");

	// no necesito hacer estos pasos
	Json::StreamWriterBuilder builder;
	std::string jsonString = Json::writeString(builder, resultado);
	// Json::Value jsonString = Json::writeString(builder, resultado);

	// std::string creatureImg = jsonString["creature_img"].asString();

	// std::cout << "Data response: " << resultado << "\n";

	std::cout << "Data response: " << resultado["creature_img"] << "\n";

	// std::cout << "Data response: " << jsonString << "\n";

	// std::cout << "Data response: " << jsonString["creature_img"] << "\n";

		   // std::cout << "Data response: " << creatureImg << "\n";

	// exit(0);

	// return 0;


	while (running) {



		// int id = raiz["id"].asInt();
		// std::string characterImg = jsonString["character_img"].asString();

		

		// bitmap = al_load_bitmap_flags("images/pikachu.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		// bitmap = al_load_bitmap_flags(jsonString["creature_img"].asString().c_str(), ALLEGRO_NO_PREMULTIPLIED_ALPHA);	

		bitmap = al_load_bitmap_flags(resultado["creature_img"].asString().c_str(), ALLEGRO_NO_PREMULTIPLIED_ALPHA);			

		al_draw_bitmap(bitmap, 255, 100, 0);

		// // esto borra lo que se crea antes
		// al_clear_to_color(al_map_rgb(0, 0, 0));

		// bitmap = al_load_bitmap_flags("images/bulbasaur.jpeg", ALLEGRO_NO_PREMULTIPLIED_ALPHA);

		// al_draw_bitmap(bitmap, 355, 100, 0);

		// al_clear_to_color(al_map_rgb(0, 0, 0));  

		// si se usa fuera del ciclo se queda pegado
		al_flip_display();
	}



	
	return 0;

	
	// return 0;
}