#include <iostream>
#include <random>
#include <cmath>
#include <chrono>
using namespace std;

int len = 0;

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
        len++;
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
        if (value == node->value) {
            return;
        }
        if (!left && !right) {
            if (value < node->value) {
                node->left = newNode;
                return;
            }
            node->right = newNode;
            return;
        }
        if (value < node->value) {
            if (node->left != nullptr) {
                delete newNode;
                insert(left, value);
                return;
            }
            node->left = newNode;
            return;
        }
        if (value > node->value) {
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
    for (int i = 0; i < 10000; i++) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distribution(1, 10000);
        int randomNumber = distribution(gen);
        myTree.insertValue(randomNumber);
    }
    auto start = chrono::high_resolution_clock::now();
    // myTree.printValues();
    // for (int i = 0; i < 6350; i++) {
    //     cout << i << endl;
    //     len++;
    // }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast <chrono::microseconds> (end - start);
    cout << "Print runtime   " << duration.count() << ", items total: " << len << endl;
    return 0;
}