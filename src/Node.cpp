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
            std::ifstream ifstream;
            ifstream.open(filename);
            if (!ifstream) return;

            std::getline(ifstream, id);
            ifstream >> data_size;
            char* buff = new char[data_size];

            std::cout << id << std::endl;
            if (!data_size) goto read_children;
            std::cout << data_size << std::endl;
            
            ifstream.read(buff, data_size);
            value = buff;
            
            read_children:
            int number_of_children;
            ifstream >> number_of_children;
            for (int i = 0; i < number_of_children; i++) {
                Node* child = new Node("", nullptr, 0);
                child->read_from_file(filename);
                children.push_back(child);
            }
            
            ifstream.close();
        }
};