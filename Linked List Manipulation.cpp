#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void addLast(int k) {
        if (!head) {
            head = new Node(k);
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = new Node(k);
        }
    }

    void addFirst(int k) {
        Node* newNode = new Node(k);
        newNode->next = head;
        head = newNode;
    }

    void addAfter(int u, int v) {
        if (!head) return;
        Node* curr = head;
        while (curr) {
            if (curr->key == v) {
                Node* newNode = new Node(u);
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        }
    }

    void addBefore(int u, int v) {
        if (!head) return;
        if (head->key == v) {
            addFirst(u);
            return;
        }
        Node* curr = head;
        while (curr->next) {
            if (curr->next->key == v) {
                Node* newNode = new Node(u);
                newNode->next = curr->next;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        }
    }

    void remove(int k) {
        if (!head) return;
        if (head->key == k) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* curr = head;
        while (curr->next) {
            if (curr->next->key == k) {
                Node* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->key << " ";
            curr = curr->next;
        }
        cout << endl;
    }

private:
    Node* head;
};

int main() {
    int n;
    cin >> n;
    LinkedList list;
    unordered_map<int, bool> keyExist;

    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;
        if (!keyExist[key]) {
            list.addLast(key);
            keyExist[key] = true;
        }
    }

    string command;
    while (cin >> command) {
        if (command == "addlast") {
            int k;
            cin >> k;
            if (!keyExist[k]) {
                list.addLast(k);
                keyExist[k] = true;
            }
        } else if (command == "addfirst") {
            int k;
            cin >> k;
            if (!keyExist[k]) {
                list.addFirst(k);
                keyExist[k] = true;
            }
        } else if (command == "addafter") {
            int u, v;
            cin >> u >> v;
            if (!keyExist[u] && keyExist[v]) {
                list.addAfter(u, v);
                keyExist[u] = true;
            }
        } else if (command == "addbefore") {
            int u, v;
            cin >> u >> v;
            if (!keyExist[u] && keyExist[v]) {
                list.addBefore(u, v);
                keyExist[u] = true;
            }
        } else if (command == "remove") {
            int k;
            cin >> k;
            if (keyExist[k]) {
                list.remove(k);
                keyExist.erase(k);
            }
        } else if (command == "reverse") {
            list.reverse();
        } else if (command == "#") {
            break;
        }
    }

    list.printList();

    return 0;
}

