#include <iostream>
#include <string>

#include "Node.cpp"

class Database {
    private:
        Node* root;

    public:
        std::string filename;

        Database(std::string _filename): root(new Node("root", nullptr)), filename(_filename) {

        }

        ~Database() {
            delete root;
        }

        void put_data(std::string path, void* value) {
            // add Node
            Node* new_node = get_node_by_path(path, root);
            new_node->set_value(value);
        }

        void* get_data(std::string path) {
            return get_node_by_path(path, root)->value;
        }

    private:
        Node* get_node_by_path(std::string path, Node* current_node) {
            int split_position = path.find_first_of("/");
            if (int64_t(split_position) == -1) {
                // search among the children for the id
                for (Node* child : current_node->children) {
                    if (child->id == path) return child;
                }

                Node* new_node = new Node(path, nullptr);
                current_node->add_child(new_node);

                return new_node;
            }

            std::string id_to_find = path.substr(0, split_position);
            std::string remaining_path = path.substr(split_position + 1, path.length() - 1);

            for (Node* child : current_node->children) {
                if (child->id == id_to_find) {
                    return get_node_by_path(remaining_path, child);
                }
            }

            // create the node and continue the search
            Node* new_node = new Node(id_to_find, nullptr);
            current_node->add_child(new_node);

            return get_node_by_path(remaining_path, new_node);
        }
};