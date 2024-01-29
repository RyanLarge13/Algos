#include <iostream>
using namespace std;

struct RopeNode {
    RopeNode* left;
    RopeNode* right;
    RopeNode* parent;
    string value;

    RopeNode(RopeNode* parent, RopeNode* left, RopeNode* right, string val): parent(parent), left(left), right(right), value(val) {} 
};

class Rope {
    private: 
         RopeNode* mainRoot = new RopeNode(nullptr, nullptr, nullptr, "New document");
    public: 
        void printDocument() {
            RopeNode* temp = mainRoot;
            while(temp) {
                cout << temp->value;
            }
            return;
        }
        void insert() {

        }
        void remove() {

        }
        void replace() {

        }
};

int main() {
    Rope myRope;
    myRope.printDocument();
    return 0;
}