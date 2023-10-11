#ifndef CLICKLISTENER_H
#define CLICKLISTENER_H

#include "ClickEvent.h"

class ClickListener {
  public:
    virtual void clickPerformed(const ClickEvent& ce) = 0;
};

#endif
