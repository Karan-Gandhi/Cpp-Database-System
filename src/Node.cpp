#include <vector>
#include <string>

// template <class T>
class Node {
    public:
        std::string id;
        std::vector<Node*> children;
        void* value;

    public:
        Node(std::string _id, void* _value): id(_id), children(std::vector<Node*>()), value(_value) {

        }

        ~Node() {
            for (Node* child : children) delete child;
            children.clear();
        }

        void set_value(void* _value) {
            value = _value;
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