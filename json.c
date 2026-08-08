#include <iostream>
#include <json/json.h>

int main() {
    std::string jsonStr = "{\"edad\": 30, \"nombre\": \"Carlos\"}";
    Json::CharReaderBuilder builder;
    Json::Value root;
    std::string errs;

    std::unique_ptr<Json::CharReader> reader(builder.newCharReader());
    bool ok = reader->parse(jsonStr.data(), jsonStr.data() + jsonStr.size(), &root, &errs);

    if (ok) {
        std::cout << "Nombre: " << root["nombre"].asString() << "\n";
        std::cout << "Edad: " << root["edad"].asInt() << "\n";
    }
    return 0;
}