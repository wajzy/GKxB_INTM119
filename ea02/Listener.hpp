#ifndef LISTENER_HPP
#define LISTENER_HPP

#include <string>
#include "ClickListener.hpp"
#include "Button.hpp"

class Listener : public ClickListener {
    const std::string name;
  public:
    Listener(const std::string& name) : name(name) {}
    void subscribeTo(Button& button) {
      button.addClickListener(this);
    }
    virtual void clickPerformed(const ClickEvent& ce) {
      std::cout << name << " received a click event from " 
                << ce.button.getLabel() << std::endl;
    }
};

#endif
