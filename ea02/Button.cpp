#include "Button.h"

bool Button::addClickListener(ClickListener* listener) {
  if(numListeners < maxListeners) {
    listeners[numListeners++] = listener;
    return true;
  }
  return false;
}

void Button::onClick(int row, int col) const {
  if(row>=top and row<=bottom and col>=left and col<=right) {
    for(auto i=0; i<numListeners; i++) { // auto-detected type
      listeners[i]->clickPerformed(ClickEvent(*this));
    }
  }
}
