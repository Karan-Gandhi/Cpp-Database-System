#include <vector>
#include <string>

template <class T>
class Node {
    public:
        std::vector<Node> children;
        std::string id;
        T value;

    public:
        Node(std::string _id): id(_id), children(std::vector<Node>()) {

        }

        void addChild(Node child) {
            children.push_back(child);
        }

        bool hasChild(std::string child_id) {
            for (Node node : children) {
                if (node.id == child_id) return true;
            }
            return false;
        }
};