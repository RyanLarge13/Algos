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
    
    void print(RodeNode* rope) {
        RopeNode* left = rope->left;
        RopeNode* right = rope->right;
        cout << rope->value;
        while(left && right) {
            print(right);
            print(left);
        }
    }

    RopeNode mainRoot = new RopeNode(nullptr, nullptr, nullptr, "New document");
    public:
    
    void printDocument() {
        RopeNode* temp = mainRoot;
          
    }
};

int main() {
    Rope myRope;
    return 0;
}