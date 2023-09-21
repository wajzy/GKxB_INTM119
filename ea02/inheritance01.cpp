#include <iostream>

class Employee {
    int baseSalary;
  public:
    Employee(int salary) {
      baseSalary = salary;
    }
    int getSalary() const {
      return baseSalary;
    }
    void setSalary(int salary) {
      baseSalary = salary;
    }
};

class Programmer {
    int baseSalary;
    double bonusMult;
  public:
    Programmer(int salary, double bonus) {
      baseSalary = salary;
      bonusMult = bonus;
    }
    int getSalary() const {
      return (int)(baseSalary * bonusMult);
    }
    void setSalary(int salary) {
      baseSalary = salary;
    }
    void setBonus(double bonus) {
      bonusMult = bonus;
    }
};

int main() {
  Employee e(300000);
  Programmer p(300000, 2.5);
  std::cout << e.getSalary() << std::endl;
  std::cout << p.getSalary() << std::endl;
}
