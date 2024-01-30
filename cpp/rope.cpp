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

        RopeNode mainRoot = new RopeNode(nullptr, nullptr, nullptr, "New document");

        void print(RodeNode* rope) {
            RopeNode* left = rope->left;
            RopeNode* right = rope->right;
            cout << rope->value;
            if (left) {
                print(left);
            }
            if (right) {
                print(right);
            }
        }

        RopeNode* findLeaf(RopeNode* node) {
            RopeNode* left = node->left;
            RopeNode* right = node->right;
            string value;
            if (value.length() > 50) {
                
            }
            return node;
        }

    public:
    
        void printDocument() {
            printDocument(mainRoot);
        }

        void printSection(RopeNode* leaf) {
            print(leaf);
        }

        void insert(string value, int position) {
            RopeNode* leafToConcatenate = findLeaf(mainRoot);
        }
};

int main() {
    Rope myRope;
    myRope.printDocument();
    return 0;
}