#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <string>
#include "ClickListener.hpp"

class Button {
    const std::string label;
    int top, bottom, left, right;
    static const int maxListeners = 10;
    int numListeners;
    ClickListener* listeners[maxListeners];
  public:
    Button(const std::string& label, int t, int b, int l, int r)
      : label(label), top(t), bottom(b), left(l), right(r), numListeners(0) {}

    const std::string& getLabel() const {
      return label;
    }

    bool addClickListener(ClickListener* listener);
    void onClick(int row, int col) const;
};

#endif

