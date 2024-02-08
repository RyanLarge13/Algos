#include <iostream>
using namespace std;

class GapBuffer {
  private:
  vector < char > buffer;
  int gapStart;
  int gapEnd;
  int indexState;

  void moveGap(int index) {
    if (index < gapStart) {
      int offset = gapStart - index;
      copy(buffer.begin() + index, buffer.begin() + gapStart, buffer.begin() +
        gapEnd - offset);
      gapStart = index;
      gapEnd -= offset;
    } else if (index > gapStart) {
      int offset = index - gapStart;
      copy(buffer.begin() + gapEnd, buffer.begin() + gapEnd + offset,
        buffer.begin() + gapStart);
      gapStart += offset;
      gapEnd = index;
    }
  }

  void expandBuffer() {
    int newSize = buffer.size() * 2;
    buffer.resize(newSize, ' ');
    gapEnd = newSize;
  }

  public:
  GapBuffer(int initialSize = 10): buffer(initialSize, ' '),
  gapStart(0),
  gapEnd(initialSize) {}

  void insert(char c, int index) {
    if (index < 0 || index > buffer.size()) {
      return;
    }
    if (gapStart != gapEnd)
    moveGap(index);
    buffer[gapStart] = c;
    gapStart++;
    indexState++;
    if (gapStart == gapEnd)
    expandBuffer();
  }

  void erase(int index) {
    if (index < 0 || index > buffer.size()) {
      return;
    }
    if (gapStart != gapEnd) {
      moveGap(index);
    }
    gapStart--;
    indexState--;
  }

  string print() {
    string bufferStr(buffer.begin(), buffer.end());
    bufferStr.erase(gapStart, gapEnd - gapStart);
    return bufferStr;
  }

  int getCurrentPos() const {
    return indexState;
  }

};

int main() {
  GapBuffer buff;
  string line;
  while(getline(cin, line)) {
    if (line.empty()) {
      cout << "End of input. Press Enter again to exit." << endl;
      getline(cin, line);
      if (line.empty()) {
        break;
      }
    }
    for (char c: line) {
      buff.insert(c, buff.getCurrentPos());
    }
  }
  return 0;
}