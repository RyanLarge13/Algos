#include <iostream>
#include <initializer_list>
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
  size_t length = 0;
  public:

  void print() {
    if (length == 0) {
      cout << "Your vect is empty" << endl;
    }
    cout << '[';
    for (int i = 0; i < vec->size; i++) {
      if (i == length - 1) {
        cout << vec->myArr[i];
        break;
      }
      cout << vec->myArr[i] << ", ";
    }
    cout << ']' << endl;
  }

  void push(initializer_list < int > nums) {
    size_t numsSize = nums.size();
    if (numsSize < 1) {
      cout << "Pass in at least 1 value" << endl;
      return;
    }
    if (numsSize >= length) {
      length = (length == 0 ? 1: length *= 2);
      delete vec;
      vec = new Vect(length);
      push(nums);
      return;
    }
    int newArr[length + numsSize];
    int tracker = 0;
    for (int i = 0; i < length; i++) {
      newArr[i] = vec->myArr[i];
      tracker++;
    }
    for (int num: nums) {
      cout << num;
      newArr[tracker] = num;
      tracker++;
    }
    return;
  }
  void pop() {}
  void shift() {}
  void find() {}
};

int main() {
  Vector myVect;
  myVect.print();
  myVect.push({
    1, 2, 3, 4
  });
  myVect.print();
  return 0;
}