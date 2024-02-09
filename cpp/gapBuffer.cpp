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
  gapEnd(initialSize),
  indexState(0) {}

  void insert(char c, int index) {
    if (index < 0 || index > buffer.size()) {
      return;
    }
    if (gapStart != gapEnd) {
      moveGap(index);
    }
    buffer[gapStart] = c;
    gapStart++;
    indexState++;
    if (gapStart == gapEnd) {
      expandBuffer();
    }
  }

  void erase(int index) {
    if (index < 0 || index >= buffer.size()) {
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
  }

  void movePosForward(int amount) {
    if (indexState == buffer.size()) {
      return;
    }
    indexState += amount;
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
    switch (c) {
      case KEY_LEFT:
      buff.movePosBack(1);
      break;
      case KEY_RIGHT:
      buff.movePosForward(1);
      break;
      case KEY_DC:
      buff.erase(buff.getCurrentPos());
      break;
      case KEY_BACKSPACE:
      buff.movePosBack(1);
      buff.erase(buff.getCurrentPos());
      break;
      case 127:
      buff.erase(buff.getCurrentPos());
      break;
      case 13:
      buff.insert('\n', buff.getCurrentPos());
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
      if (buff.getCurrentPos() > 0) {
        buff.movePosBack(1);
      }
      break;
      case 5:
      if (buff.getCurrentPos() <= buff.getSize()) {
        buff.movePosForward(1);
      }
      break;
      case '\n': // Handle newline
      // Handle newline as needed
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
    move(0, buff.getCurrentPos());
    refresh();
  }
  endwin();
  return 0;
}