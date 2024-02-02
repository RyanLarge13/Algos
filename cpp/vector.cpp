#include <iostream>
#include <initializer_list>
using namespace std;

struct Vect {
  size_t size;
  int* myArr;
  Vect(size_t size) : size(size),
    myArr(new int[size]) {}
};

class Vector {
private:
  size_t defaultSize = 10;
  Vect* vec = new Vect(defaultSize);
  size_t length = 10;
  size_t values = 0;
public:

  void print() {
    if (length == 0) {
      cout << "Your vect is empty" << endl;
    }
    cout << '[';
    for (int i = 0; i < values - 1; i++) {
      int* val = vec->myArr;
      if (i == values - 2) {
        cout << val[i];
        break;
      }
      cout << val[i] << ", ";
    }
    cout << ']' << endl;
  }

  void push(initializer_list < int > nums) {
    size_t numsSize = nums.size();
    if (numsSize < 1) {
      cout << "Pass in at least 1 value" << endl;
      return;
    }
    if (values + numsSize >= length) {
      length = max(length * 2, values + numsSize);
      int* newArr = new int[length];
      int* val = vec->myArr;
      int tracker = 0;
      for (int i = 0; i <= values; i++) {
        newArr[i] = *val;
        val++;
        tracker++;
      }
      values = tracker;
      for (int num : nums) {
        newArr[tracker - 1] = num;
        tracker++;
        values++;
      }
      delete[] vec->myArr;
      vec->myArr = newArr;
    }
    else {
      int* val = vec->myArr;
      for (int num : nums) {
        val[values] = num;
        values++;
      }
    }
    return;
  }
  void pop() {}
  void shift() {}
  void find(int index) {
    int* myArray = vec->myArr;
    cout << myArray[index] << endl;
  }
};

int main() {
  Vector myVect;
  myVect.push({
    1,
    3,
    4,
    5,
    473
    });
  myVect.push({ 5,4,6,7,4,6,5,4,3,6,4,5,7,4,3,2,5,4,4,4,4,4,4 });
  myVect.find(4); // should print 473
  myVect.print();
  return 0;
}