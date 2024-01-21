#include <iostream>
using namespace std;

struct Node {
    // Node data including the integer passed and a pointer to the next node in the list
    int data;
    Node* next;
    // constructor
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
public:
    // constructor initializes the head pointer and sets it to nullptr as the first node in the linked list
    Node* head;
    LinkedList() : head(nullptr) {}
    // append function takes in value
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }
    void insertAt(int placement, int value) {

    }
    void pop() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    void shift() {

    }
    void removeAt(int placement) {

    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;
    myList.append(0);
    myList.prepend(10);
    myList.prepend(20);
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.pop();
    myList.display();
    return 0;
}