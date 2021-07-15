#include <iostream>

#include "Node.cpp"
// #include "Database.cpp"

int main() {
    // Database* db = new Database("test");
    std::string data = "hello, world, I am Karan";
    // db->put_data("hello/world", &data, sizeof (data));

    // std::string* new_data = (std::string*) db->get_data("hello/world");

    // std::cout << *new_data << std::endl;
    
    // delete db;

    Node* node = new Node("node id", &data, sizeof data);
    node->update_file("hello.bin");

    Node* new_node = new Node("", nullptr, 0);
    new_node->read_from_file("hello.bin");    

    std::string* new_data = (std::string*) new_node->value;

    std::cout << *new_data << std::endl;

    return 0;
}