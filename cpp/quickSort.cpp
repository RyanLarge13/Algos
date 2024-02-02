#include <iostream>
using namespace std;

class QuickSort {
  private:

  vector < int > initialArr;

  int partition(vector < int >& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
      if (arr[j] < pivot) {
        i++;
        swap(arr[i], arr[j]);
      }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
  }

  public:

  void print() {
    cout << endl;
    for (int num: initialArr) {
      cout << num << ", ";
    }
    cout << endl;
  }

  void sort(vector < int >& arr, int low, int high) {
    if (low < high) {
    int pivotIndex = partition(arr, low, high);
    sort(arr, low, pivotIndex - 1);
    sort(arr, pivotIndex + 1, high);
    } 
    initialArr = arr;
  }

};

int main() {
  QuickSort qckSrt;
  vector < int > myArr = {
    1,
    6,
    8,
    4,
    0,
    7,
    3,
    8,
    6,
    7
  };
  qckSrt.sort(myArr, 0, 10);
  qckSrt.print();
  return 0;
}