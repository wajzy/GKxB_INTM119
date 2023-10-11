#include <iostream>
#include <string>
#include "Listener.h"
#include "Button.h"

int main() {
  Button b1("Button1", 0, 100, 0, 100);
  Button b2("Button2", 0, 100, 150, 250);
  Listener l1("Listener1");
  l1.subscribeTo(b1);
  l1.subscribeTo(b2);
  Listener l2("Listener2");
  l2.subscribeTo(b1);
  std::string row, col;
  while(std::cout << "row: ", std::getline(std::cin, row), !row.empty()) {
    int r = stoi(row);
    std::cout << "col: "; getline(std::cin, col);
    int c = stoi(col);
    b1.onClick(r, c);
    b2.onClick(r, c);
  }
}
