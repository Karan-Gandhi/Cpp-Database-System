#include <iostream>

#include "Database.cpp"

int main() {
    Database* db = new Database("test");
    std::string data = "hello, world";
    db->put_data("hello/world", &data);

    std::string* new_data = (std::string*) db->get_data("hello/world");

    std::cout << *new_data << std::endl;

    delete db;

    return 0;
}