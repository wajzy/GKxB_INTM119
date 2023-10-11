#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include "ClickListener.h"

class Button {
    const std::string label;
    int top, bottom, left, right;
    const int maxListeners;
    int numListeners;
    ClickListener** listeners;
  public:
    Button(const std::string& label, int t, int b, int l, int r)
    : label(label), maxListeners(10) {
      top = t;
      bottom = b;
      left = l;
      right = r;
      numListeners = 0;
      listeners = new ClickListener*[maxListeners];
    }
    const std::string& getLabel() const {
      return label;
    }
    bool addClickListener(ClickListener* listener);
    void onClick(int row, int col) const;
    ~Button() {
      delete[] listeners;
    }
};

#endif
