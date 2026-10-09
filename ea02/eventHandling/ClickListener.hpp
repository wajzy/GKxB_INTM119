#ifndef CLICKLISTENER_HPP
#define CLICKLISTENER_HPP

#include "ClickEvent.hpp"

class ClickListener {
  public:
    virtual void clickPerformed(const ClickEvent& ce) = 0;
    virtual ~ClickListener() = default;
};

#endif

