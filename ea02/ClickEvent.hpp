#ifndef CLICKEVENT_HPP
#define CLICKEVENT_HPP

class Button;

class ClickEvent {
  public:
    const Button& button;
    ClickEvent(const Button& button) : button(button) {}
};

#endif
