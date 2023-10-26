#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int k) : key(k), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int k) {
    if (!root) {
        root = new TreeNode(k);
        return;
    }
    
    if (k < root->key)
        insert(root->left, k);
    else if (k > root->key)
        insert(root->right, k);
}

void preOrder(TreeNode* root) {
    if (root) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main() {
    TreeNode* root = nullptr;
    string command;
    while (cin >> command) {
        if (command == "insert") {
            int k;
            cin >> k;
            insert(root, k);
        } else if (command == "#") {
            break;
        }
    }

    preOrder(root);
    return 0;
}

