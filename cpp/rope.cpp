#include <iostream>
using namespace std;
struct RopeNode {
  RopeNode* left;
  RopeNode* right;
  string value;
  int weight;

  RopeNode(RopeNode* left, RopeNode* right, string val, int
    weight):
  left(left),
  right(right),
  value(val),
  weight(weight) {}
};


class Rope {
  private:

  RopeNode* mainRoot = new RopeNode(nullptr, nullptr, "", 0);

  void print(RopeNode* rope) {
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

  void insertString(RopeNode* node, string value, int index) {
    if (index <= 0) {
      RopeNode* newNode = new RopeNode(nullptr, nullptr, value, value.length());
      newNode->weight = value.length();
      newNode->right = node;
      mainRoot = newNode;
      return;
    }
    if (index >= node->weight) {
      if (!node->right) {
        node->right = new RopeNode(nullptr, nullptr, value, value.length());
        node->weight += value.length();
      } else {
        insertString(node->right, value, index - node->weight);
        node->weight += value.length();
      }
    }
    else {
      string currentVal = node->value;
      RopeNode* newLeft = new RopeNode(nullptr, nullptr, currentVal.substr(0, index), index);
      RopeNode* newMiddle = new RopeNode(nullptr, nullptr, value, value.length());
      RopeNode* newRight = new RopeNode(nullptr, nullptr, currentVal.substr(index), currentVal.length() - index);
      newLeft->weight = index;
      newMiddle->weight = value.length();
      newRight->weight = currentVal.length() - index;

      node->left = newLeft;
      newMiddle->right = newRight;
      newLeft->right = newMiddle;
      node->value = "";
      node->weight = index;
    }
  }

  public:

  void printDocument() {
    print(mainRoot);
  }

  void insert(string value, int index) {
    insertString(mainRoot, value, index);
  }

  void deleteAt(int index) {}
};

int main() {
  Rope myRope;
  myRope.printDocument();
  myRope.insert(" This doc is short.", 0);
  myRope.insert(" end-ish", 5);
  myRope.printDocument();
  myRope.insert("Begin!", 0);
  myRope.insert("What the vi!!!", 4);
  myRope.printDocument();
  cout << endl;
  return 0;
}