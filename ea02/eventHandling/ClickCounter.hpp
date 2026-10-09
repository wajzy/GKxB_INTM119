#ifndef CLICKCOUNTER_HPP
#define CLICKCOUNTER_HPP

#include <iostream>
#include "ClickListener.hpp"

class ClickCounter : public ClickListener {
    int count;
  public:
    ClickCounter() : count(0) {}

    void clickPerformed(const ClickEvent& ce) override {
      count++;
      std::cout << "[ClickCounter] Total clicks: " << count 
                << " (last from " << ce.getSource() << ")" 
                << std::endl;
    }

    int getCount() const {
      return count;
    }

    void reset() {
      count = 0;
    }
};

#endif

