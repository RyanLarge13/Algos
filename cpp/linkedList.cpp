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
    int getPop() {
        int returnValue;
        if (!head) {
            return -1;
        }
        if (!head->next) {
            returnValue = head->data;
            delete head;
            head = nullptr;
            return returnValue;
        }
        Node* temp = head;
        while (temp->next && temp->next->next) {
            temp = temp->next;
        }
        returnValue = temp->next->data;
        delete temp->next;
        temp->next = nullptr;
        return returnValue;
    }
    void shift() {
        if (!head) {
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
    }
    int getShift() {
        int returnValue;
        if (!head) {
            return -1;
        }
        if (!head->next) {
            returnValue = head->data;
            delete head;
            head = nullptr;
            return returnValue;
        }
        returnValue = head->data;
        Node* temp = head;
        head = temp->next;
        delete temp;
        return returnValue;
    }
    int removeAt(int placement) {
        int iteration;
        if (!head) {
            return -1;
        }
        if (!head->next && placement > 0) {
            return -1;
        }
        Node* temp = head;
        if (placement == 0) {
            delete temp;
            head = nullptr;
            return head->data;
        }
        while (temp->next) {

        }
    }
    int removeValue(int value) {

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
    myList.shift();
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(4);
    myList.append(5);
    myList.pop();
    int myPoppedValue = myList.getPop();
    int myShiftedValue = myList.getShift();
    myList.shift();
    myList.display();
    cout << "Popped value: " << myPoppedValue << endl;
    cout << "Shifted value: " << myShiftedValue << endl;
    return 0;
}