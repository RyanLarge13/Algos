#include <iostream>
using namespace std;

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    int value;

    Node(Node* parent, Node* left, Node* right, int value) : parent(parent), left(left), right(right), value(value) {}
};

class BinaryTree {
private:

    Node* mainRoot = nullptr;

    void print(Node* node) {
        Node* left = node->left;
        Node* right = node->right;
        Node* parent = node->parent;
        cout << node->value << endl;
        if (left != nullptr) {
            print(left);
        }
        if (right != nullptr) {
            print(right);
        }
    }

    void insert(Node* node, int value) {
        Node* left = node->left;
        Node* right = node->right;
        Node* newNode = new Node(node, nullptr, nullptr, value);
        cout << "Value: " << value << ", Node value: " << node->value << ", New Node Value: " << newNode->value;
        if (value == node->value) {
            cout << " (Exactly equals)" << endl << endl;
            return;
        }
        if (!left && !right) {
            cout << " (No left, no right)" << endl << endl;
            if (value < node->value) {
                node->left = newNode;
                return;
            }
            node->right = newNode;
            return;
        }
        if (value < node->value) {
            cout << " (Value less than)" << endl << endl;
            if (node->left != nullptr) {
                delete newNode;
                insert(left, value);
                return;
            }
            node->left = newNode;
            return;
        }
        if (value > node->value) {
            cout << " (Value greater than)" << endl << endl;
            if (node->right != nullptr) {
                delete newNode;
                insert(right, value);
                return;
            }
            node->right = newNode;
            return;
        }
        return;
    }

public:

    void printValues() {
        if (!mainRoot) {
            cout << "Your tree is empty, insert some values" << endl;
        }
        print(mainRoot);
    }

    void insertValue(int value) {
        if (!mainRoot) {
            mainRoot = new Node(nullptr, nullptr, nullptr, value);
            return;
        }
        insert(mainRoot, value);
    }
};

int main() {
    BinaryTree myTree;
    myTree.insertValue(50);
    myTree.insertValue(20);
    myTree.insertValue(10);
    myTree.printValues();
    return 0;
}