#ifndef CLICKEVENT_H
#define CLICKEVENT_H

class Button;

class ClickEvent {
  public:
    const Button& button;
    ClickEvent(const Button& button) : button(button) {}
};

#endif
