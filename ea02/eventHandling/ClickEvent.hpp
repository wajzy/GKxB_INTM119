#ifndef CLICKEVENT_HPP
#define CLICKEVENT_HPP

#include <string>

class ClickEvent {
    const std::string source;
    const int row;
    const int col;
  public:
    ClickEvent(const std::string& source, int row, int col)
      : source(source), row(row), col(col) {}

    const std::string& getSource() const {
      return source;
    }

    int getRow() const {
      return row;
    }

    int getCol() const {
      return col;
    }
};

#endif

