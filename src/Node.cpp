#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Node {
    public:
        std::string id;
        std::vector<Node*> children;
        void* value;
        size_t data_size;

    public:
        Node(std::string _id, void* _value, size_t _data_size): id(_id), children(std::vector<Node*>()), value(_value), data_size(_data_size) {

        }

        ~Node() {
            for (Node* child : children) delete child;
            children.clear();
        }

        void set_value(void* _value, size_t _data_size) {
            value =_value;
            data_size = _data_size;
        }

        void add_child(Node* child) {
            children.push_back(child);
        }

        bool has_child(std::string child_id) {
            for (Node* node : children) {
                if (node->id == child_id) return true;
            }
            return false;
        }

        void update_file(std::string filename) {
            std::ofstream ostream;
            ostream.open(filename, std::fstream::app);
            if (!ostream) return;

            ostream << id << std::endl;
            ostream << data_size << std::endl;
            ostream.write((char*) value, data_size);
            // write children
            ostream << children.size() << std::endl;
            for (Node* child : children) child->update_file(filename);

            ostream.close();
        }

        void read_from_file(std::string filename) {
            FILE* file = fopen(filename.c_str(), "w");

            read_file_recursively(file);

            fclose(file);
        }

    private:
        void read_file_recursively(FILE* file) {
            if (feof(file)) return;
            
            id = get_string(file);
            
            data_size = atoi(get_string(file).c_str());

            std::cout << id << std::endl;
            std::cout << data_size << std::endl;
            
            fread(value, data_size, 1, file);
            // ifstream.read(buff, data_size);
            if (data_size) std::cout << *(std::string*) value << std::endl;
            
        // read_children:
            // int number_of_children;
            // ifstream >> number_of_children;
            // std::cout << number_of_children << std::endl;
            // for (int i = 0; i < number_of_children; i++) {
            //     Node* child = new Node("", nullptr, 0);
            //     child->read_file_recursively(ifstream);
            //     children.push_back(child);
            // }
        }

        std::string get_string(FILE* file) {
            std::string res;
            char* buff;
            fgets(buff, 10000, file);
            res = buff;
            return res;
        }

        // void read_file_recursively(std::ifstream& ifstream) {
        //     if (ifstream.eof()) return;

        //     std::getline(ifstream, id);

        //     ifstream >> data_size;
        //     char* buff = new char[data_size];

        //     // std::cout << id << std::endl;
        //     // std::cout << data_size << std::endl;
            
        //     ifstream.read(buff, data_size);
        //     value = buff;
        //     if (data_size) std::cout << *(std::string*) value << std::endl;
            
        // read_children:
        //     int number_of_children;
        //     ifstream >> number_of_children;
        //     std::cout << number_of_children << std::endl;
        //     for (int i = 0; i < number_of_children; i++) {
        //         Node* child = new Node("", nullptr, 0);
        //         child->read_file_recursively(ifstream);
        //         children.push_back(child);
        //     }
        // }
};