#include <iostream>
#include "ncurses.h"
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
      indexState = index;
    } else if (index > gapStart) {
      int offset = index - gapStart;
      copy(buffer.begin() + gapEnd, buffer.begin() + gapEnd + offset,
        buffer.begin() + gapStart);
      gapStart += offset;
      gapEnd = index;
      indexState = index;
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
  gapEnd(initialSize),
  indexState(0) {}

  void insert(char c, int index) {
    if (index < 0 || index > buffer.size()) {
      return;
    }
    if (gapStart != gapEnd) {
      moveGap(index);
    }
    if (gapStart == gapEnd) {
      expandBuffer();
    }
    buffer[gapStart] = c;
    gapStart++;
    indexState++;
  }

  void erase(int index) {
    if (index <= 0 || index > gapEnd) {
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

  void movePosBack(int amount) {
    indexState -= amount;
    if (indexState <= 0) {
      indexState = 0;
      return;
    }
  }

  void movePosForward(int amount) {
    indexState += amount;
    if (indexState > buffer.size() - (gapEnd - gapStart)) {
      indexState = buffer.size() - (gapEnd - gapStart);
      if (indexState < 0) {
        indexState = 0;
      }
      return;
    }
  }

  int getSize() {
    return buffer.size();
  }

};

int main() {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  GapBuffer buff;
  bool editing = true;
  while(editing) {
    char c = getch();
    cout << c;
    switch (c) {
      // back btn
      case 127:
      buff.erase(buff.getCurrentPos());
      break;
      // enter pressed
      case 13:
      buff.insert('\n', buff.getCurrentPos());
      break;
      case 2:
      break;
      case 3:
      break;
      //left btn
      case 4:
      buff.movePosBack(1);
      move(0, buff.getCurrentPos());
      break;
      // right btn
      case 5:
      buff.movePosForward(1);
      move(0, buff.getCurrentPos());
      break;
      // tab key
      case 9:
      buff.movePosForward(2);
      break;
      case 17:
      editing = false;
      break;
      default:
      buff.insert(c, buff.getCurrentPos());
      break;
    }
    clear();
    printw("%s", buff.print().c_str());
    refresh();
  }
  endwin();
  return 0;
}