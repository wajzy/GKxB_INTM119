#include "Button.hpp"

bool Button::addClickListener(ClickListener* listener) {
  if (listener != nullptr && numListeners < maxListeners) {
    listeners[numListeners++] = listener;
    return true;
  }
  return false;
}

void Button::onClick(int row, int col) const {
  if (row >= top && row <= bottom && col >= left && col <= right) {
    ClickEvent ce(label, row, col);
    for (int i = 0; i < numListeners; i++) {
      listeners[i]->clickPerformed(ce);
    }
  }
}

