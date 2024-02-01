#include <iostream>
using namespace std;

struct Vect {
  size_t size;
  int* myArr;
  Vect(size_t size): size(size),
  myArr(new int[size]) {}
};

class Vector {
  private:
  size_t defaultSize = 0;
  Vect* vec = new Vect(defaultSize);
  size_t length = sizeof(vec->myArr) / sizeof(vec[0]);
  public:
  template < typename... Nums >
  void print(Nums... nums) {
    if (length == 0) {
      cout << "Your vect is empty" << endl;
    }
    cout << '[';
    for (int i = 0; i < length; i++) {
      cout << vec->myArr[i] << ", ";
    }
    cout << ']' << endl;
  }
  void push() {}
  void pop() {}
  void shift() {}
  void find() {}
};

int main() {
  Vector myVect;
  return 0;
}