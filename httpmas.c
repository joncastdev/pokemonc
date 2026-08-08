#include <iostream>
#include <string>
#include <curl/curl.h>

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
    // int data[10] = {0}
    // char data[10] = "";

    // 2. Set the target API URL
    // curl_easy_setopt(curl, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts");
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
            std::cout << "Successfully retrieved JSON response:\n" << responseBody << std::endl;
            // std::cout << "Successfully retrieved JSON response:\n" << responseBody["character_name"] << std::endl;
         // std::cout << "Successfully retrieved JSON response:\n" <<  data[0] << std::endl;
            // You can now pass 'responseBody' to a JSON parser like nlohmann/json or JsonCpp
     } else {
        std::cerr << "HTTP Error Code: " << httpCode << std::endl;
    }
}

    // 8. Clean up resources
curl_slist_free_all(headers);
curl_easy_cleanup(curl);

return 0;
}