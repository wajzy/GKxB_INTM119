#include <iostream>

class Employee {
  protected: // private --> protected
    int baseSalary;
  public:
    Employee(int salary) {
      baseSalary = salary;
    }
    virtual int getSalary() const {
      return baseSalary;
    }
    void setSalary(int salary) {
      baseSalary = salary;
    }
};

class Programmer : public Employee {
    double bonusMult;
  public:
    Programmer(int salary, double bonus) : Employee(salary) {
      bonusMult = bonus;
    }
    /* virtual */ int getSalary() const { // implicitely virtual
      return (int)(baseSalary * bonusMult); // OK
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
  
  Employee* eArray[] = { &e, &p };
  for(unsigned i=0; i<sizeof(eArray)/sizeof(eArray[0]); i++) {
    // OK! Late / dynamic binding
    std::cout << eArray[i]->getSalary() << std::endl;
  }
}
