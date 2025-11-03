#ifndef TIME_H
#define TIME_H
#include <ostream>
#include <iomanip>

class Time {
    int hour;
    int minute;
    int second;

    // Normalizes time (60sec = 1min, etc.)
    void normalize() {
        if(second >= 60) {
            minute += second / 60;
            second %= 60;
        } else if(second < 0) {
            int borrow = (-second + 59) / 60;
            minute -= borrow;
            second += borrow * 60;
        }

        if(minute >= 60) {
            hour += minute / 60;
            minute %= 60;
        } else if(minute < 0) {
            int borrow = (-minute + 59) / 60;
            hour -= borrow;
            minute += borrow * 60;
        }

        // 24 hour circulation
        hour = (hour % 24 + 24) % 24;
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {
        normalize();
    }

    // Prefix ++
    Time& operator++() {
        ++second;
        normalize();
        return *this;
    }

    // Postfix ++
    Time operator++(int) {
        Time temp = *this;
        ++(*this);
        return temp;
    }

    // Prefix --
    Time& operator--() {
        --second;
        normalize();
        return *this;
    }

    // Postfix --
    Time operator--(int) {
        Time temp = *this;
        --(*this);
        return temp;
    }

    // Inline friend operator
    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << std::setfill('0')
           << std::setw(2) << t.hour << ":"
           << std::setw(2) << t.minute << ":"
           << std::setw(2) << t.second;
        return os;
    }
};
#endif
