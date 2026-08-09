#include <iostream>
#include <string>
#include <curl/curl.h>
#include <json/json.h>

// 1. Define the callback function to handle incoming data chunks
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    size_t totalSize = size * nmemb;
    std::string* responseString = static_cast<std::string*>(userp);
    responseString->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

int main() {



    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize cURL." << std::endl;
        return 1;
    }

    std::string responseBody;
    long httpCode = 0;    

    // 2. Set the target API URL
    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:8000/api/getcharacter");
    

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
            // std::cout << "Successfully retrieved JSON response:\n" << responseBody << std::endl;          
            // You can now pass 'responseBody' to a JSON parser like nlohmann/json or JsonCpp

        } else {
            std::cerr << "HTTP Error Code: " << httpCode << std::endl;
        }
    }



    // std::string json_str = "{\"nombre\": \"Ana\", \"edad\": 25, \"activo\": true}";

    std::string json_str = responseBody;

    // std::cout << "Data response: " << json_str.data() << "\n";

    // return 1;

    Json::Value raiz;
    Json::CharReaderBuilder lector;
    std::string errs;

    // aqui ocurre el parse del response
    std::unique_ptr<Json::CharReader> const reader(lector.newCharReader());
    bool ok = reader->parse(json_str.data(), json_str.data() + json_str.size(), &raiz, &errs);


    // std::cout << "Data Parse: " <<  raiz << "\n";

     // While loop array iteration
    Json::ArrayIndex i = 0;
    while (i < raiz.size()) {
        std::cout << "Id " << i << ": " << raiz[i]["id"].asInt() << "\n";
        std::cout << "character_name " << i << ": " << raiz[i]["character_name"].asString() << "\n";
        i++;
    }
    return 0;



    return 1;

    if (!ok) {
        std::cout << "Error al parsear JSON: " << errs << "\n";
        return 1;
    }

    // std::string nombre = raiz["nombre"].asString();
    int id = raiz["id"].asInt();
    std::string characterName = raiz["character_name"].asString();
    // bool activo = raiz["activo"].asBool();

    std::cout << "Nombre: " << id << "\n";
    std::cout << "Edad: " << characterName << "\n";
    // std::cout << "Activo: " << (activo ? "Sí" : "No") << "\n";

    return 0;
}