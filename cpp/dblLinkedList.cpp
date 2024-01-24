#include <iostream>
using namespace std;

struct DblLink {
    DblLink* prevLink;
    DblLink* nextLink;
    int value;
    DblLink(DblLink* prev, DblLink* next, int val) : prevLink(prev), nextLink(next), value(val) {}
};

class DoubleyLinkedList {
private:
    DblLink* head = new DblLink(nullptr, nullptr, 0);
public:
    void print() {
        if (!head) {
            cout << "Your list is empty" << endl;
            return;
        }
        if (!head->nextLink) {
            cout << head->value << endl;
            return;
        }
        DblLink* link = head->nextLink;
        while (link != head) {
            cout << link->value;
            link = link->nextLink;
        }
    }
    void findValue(int value) {
        if (!head) {
            cout << "Your list is empty" << endl;
            return;
        }
        DblLink* temp = head->nextLink;
        while (temp != head) {
            if (temp->value == value) {
                cout << "!1!" << endl;
                return;
            }
            temp = temp->nextLink;
        }
    }
    void insert(int value) {

    }
    void remove() {}
    // void shift() {}
};

int main() {
    DoubleyLinkedList dblList;
    dblList.print();
    dblList.findValue(0);
    return 0;
}