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

  void deleteSubstring(RopeNode* node, int startIndex, int length) {
    if (!node) {
      return;
    }
    if (startIndex >= node->weight) {
      return;
    }
    while (node && startIndex >= node->weight) {
      startIndex -= node->weight;
      node = node->right;
    }
    if (!node) {
      return;
    }
    if (startIndex + length <= node->weight) {
      node->value.erase(startIndex, length);
      node->weight -= length;
    } else {
      int charsToDelete = min(length, node->weight - startIndex);
      node->value.erase(startIndex, charsToDelete);
      node->weight -= charsToDelete;
      startIndex = 0;
      deleteSubstring(node->right, 0, length - charsToDelete);
    }
  }

  public:

  void printDocument() {
    print(mainRoot);
  }

  void insert(string value, int index) {
    insertString(mainRoot, value, index);
  }

  void deleteSubstring(int startIndex, int length) {
    deleteSubstring(mainRoot, startIndex, length);
  }
};

int main() {
  Rope myRope;
  myRope.printDocument();
  cout << endl;
  myRope.insert("This doc is short.", 0);
  myRope.deleteSubstring(0, 5);
  myRope.deleteSubstring(0, 50);
  myRope.insert("Hi", 0);
  myRope.insert(", how are you today?", 2);
  myRope.deleteSubstring(0, 10);
  myRope.printDocument();
  cout << endl;
  return 0;
}