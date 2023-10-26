#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node {
    int id;
    vector<Node*> children;

    Node(int _id) : id(_id) {}
};

unordered_map<int, Node*> node_map;

Node* MakeRoot(int u) {
    Node* root = new Node(u);
    node_map[u] = root;
    return root;
}

bool Insert(int u, int v) {
    if (node_map.find(u) != node_map.end() || node_map.find(v) == node_map.end()) {
        return false;
    }

    Node* newNode = new Node(u);
    node_map[u] = newNode;
    node_map[v]->children.push_back(newNode);
    return true;
}

void PreOrder(Node* root) {
    if (root) {
        cout << root->id << " ";
        for (Node* child : root->children) {
            PreOrder(child);
        }
    }
}

void InOrder(Node* root) {
    if (root) {
        if (root->children.size() >= 2) {
            InOrder(root->children[0]);
            cout << root->id << " ";
            for (size_t i = 1; i < root->children.size(); i++) {
                InOrder(root->children[i]);
            }
        } else {
            cout << root->id << " ";
        }
    }
}

void PostOrder(Node* root) {
    if (root) {
        for (Node* child : root->children) {
            PostOrder(child);
        }
        cout << root->id << " ";
    }
}

int main() {
    string action;
    while (cin >> action) {
        if (action == "MakeRoot") {
            int u;
            cin >> u;
            MakeRoot(u);
        } else if (action == "Insert") {
            int u, v;
            cin >> u >> v;
            Insert(u, v);
        } else if (action == "PreOrder") {
            PreOrder(node_map[10]); // Xu?t k?t qu? d?a trên nút g?c có id = 10
            cout << endl;
        } else if (action == "InOrder") {
            InOrder(node_map[10]); // Xu?t k?t qu? d?a trên nút g?c có id = 10
            cout << endl;
        } else if (action == "PostOrder") {
            PostOrder(node_map[10]); // Xu?t k?t qu? d?a trên nút g?c có id = 10
            cout << endl;
        } else if (action == "*") {
            break;
        }
    }

    return 0;
}

