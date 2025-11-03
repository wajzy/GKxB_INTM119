#include <iostream>
#include "Time.h"

int main() {
    Time t1(23, 59, 58);
    std::cout << "Inital time: " << t1 << std::endl;

    std::cout << "++t1 -> " << ++t1 << std::endl;
    std::cout << "t1++ -> " << t1++ << " (return value)\n";
    std::cout << "after increasing t: " << t1 << std::endl;

    std::cout << "--t1 -> " << --t1 << std::endl;
    std::cout << "t1-- -> " << t1-- << " (return value)\n";
    std::cout << "after reducing t: " << t1 << std::endl;

    Time t2(0, 0, -5);
    std::cout << "Inital time: " << t2 << std::endl;
}
