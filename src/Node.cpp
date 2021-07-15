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
            // FILE* file = fopen(filename.c_str(), "w");
            // if (file == NULL) {
            //     delete file;
            //     return;
            // }

            // fwrite(&id, sizeof(id), 1, file);
            // fwrite(&data_size, sizeof(data_size), 1, file);
            // fwrite(value, data_size, 1, file);
            // fclose(file);
            // delete file;

            std::ofstream ostream;
            ostream.open(filename);
            if (!ostream) return;

            ostream << data_size;
            ostream.write((char*) value, data_size);
            ostream.close();            
        }

        void read_from_file(std::string filename) {
            // FILE* file = fopen(filename.c_str(), "r");
            // if (file == NULL) {
            //     delete file;
            //     return;
            // }

            // fread(&id, sizeof(std::string), 1, file);
            // fread(&data_size, sizeof(size_t))
            std::ifstream ifstream;
            ifstream.open(filename);
            if (!ifstream) return;

            ifstream >> data_size;
            char* buff = new char[data_size];
            ifstream.read(buff, data_size);
            value = buff;
        }

        // friend std::ostream& operator<< (std::ostream& os, const Node& node) {
        //     os << node.id;
        //     os << node.data_size;
            
        //     // std::fwrite(node.value, node.data_size, os);
        // }
};