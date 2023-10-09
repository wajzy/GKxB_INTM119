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

class Programmer : public Employee {
    double bonusMult;
  public:
    Programmer(int salary, double bonus) 
    : Employee(salary) {
      bonusMult = bonus;
    }
    int getSalary() const {
      // 'int Employee::baseSalary' is private 
      // within this context
      // return (int)(baseSalary * bonusMult);
      return (int)(Employee::getSalary() 
        * bonusMult);
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
  
  // Using base class is OK: Programmer inherites from Employee
  Employee* eArray[] = { &e, &p };
  for(unsigned i=0; i<sizeof(eArray)/sizeof(eArray[0]); i++) {
    // Ooops! Early / static binding!!!
    std::cout << eArray[i]->getSalary() << std::endl;
  }
}
