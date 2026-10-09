#include <iostream>
#include "Button.hpp"
#include "ConsoleLogger.hpp"
#include "ClickCounter.hpp"

int main() {
  Button b1("Button1", 0, 100, 0, 100);
  Button b2("Button2", 0, 100, 150, 250);

  ConsoleLogger logger1("Logger1");
  ConsoleLogger logger2("Logger2");
  ClickCounter counter;

  // Subscribe listeners to buttons
  b1.addClickListener(&logger1);
  b1.addClickListener(&logger2);
  b1.addClickListener(&counter);

  b2.addClickListener(&logger1);
  b2.addClickListener(&counter);

  // Test 1: Click inside Button1
  std::cout << "1. Click (row=50, col=50):\n";
  b1.onClick(50, 50);
  b2.onClick(50, 50);

  // Test 2: Click inside Button2
  std::cout << "\n2. Click (row=50, col=200):\n";
  b1.onClick(50, 200);
  b2.onClick(50, 200);

  // Test 3: Click outside buttons
  std::cout << "\n3. Click (row=300, col=300):\n";
  b1.onClick(300, 300);
  b2.onClick(300, 300);

  // State of ClickCounter
  std::cout << "\nTotal clicks registered by ClickCounter: " 
            << counter.getCount() << std::endl;

  return 0;
}

