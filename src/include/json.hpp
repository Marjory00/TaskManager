
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

int main() {
    // Create a JSON object
    json j;
    j["name"] = "John";
    j["age"] = 30;
    j["city"] = "New York";

    // Convert JSON object to string
    std::cout << j.dump(4) << std::endl; // Pretty print with an indent of 4 spaces

    // Parse JSON string
    std::string jsonString = R"({"name":"Alice","age":25,"city":"London"})";
    json parsedJson = json::parse(jsonString);

    std::cout << "Name: " << parsedJson["name"] << std::endl;
    std::cout << "Age: " << parsedJson["age"] << std::endl;
    std::cout << "City: " << parsedJson["city"] << std::endl;

    return 0;
}