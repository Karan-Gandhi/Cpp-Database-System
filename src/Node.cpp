#include <iostream>
#include <vector>
#include <string>

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
};