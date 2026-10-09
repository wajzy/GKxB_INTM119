#ifndef CONSOLELOGGER_HPP
#define CONSOLELOGGER_HPP

#include <iostream>
#include <string>
#include "ClickListener.hpp"

class ConsoleLogger : public ClickListener {
    const std::string name;
  public:
    ConsoleLogger(const std::string& name) : name(name) {}

    void clickPerformed(const ClickEvent& ce) override {
      std::cout << "[" << name << "] Click received from " 
                << ce.getSource() << " at ("
                << ce.getRow() << ", " << ce.getCol() << ")" 
                << std::endl;
    }
};

#endif

