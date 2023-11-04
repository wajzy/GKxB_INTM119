#include <iostream>

class BaseException {};
class DerivedException : public BaseException {};
// private inheritance --> exception object's reference 
//                         cannot be bound to base reference

int main() {
  for(int exceptType = 0; exceptType < 6; exceptType++) {
    try {
      switch(exceptType) {
        case 0:
          std::cout << "Throwing int... ";
          throw 42;
          break;
        case 1:
          std::cout << "Throwing double... ";
          throw 3.14;
          break;
        case 2:
          std::cout << "Throwing const char*... ";
          throw "Can you access it?";
          break;
        case 3:
          std::cout << "Throwing BaseException... ";
          throw BaseException();
          break;
        case 4:
          std::cout << "Throwing DerivedException... ";
          throw DerivedException();
          break;
        case 5:
          std::cout << "Throwing char... ";
          throw 'x';
          break;
      }
    } catch(char c) {
      std::cout << "caught " << c << ", re-throw exception" 
                << std::endl;
      throw;
    // no implicite type conversions, no conversion ctor calls
    } catch(double d) {
      std::cout << "caught " << d << std::endl;
    } catch(const char*) { // parameter without name
      std::cout << "caught an unknown message" << std::endl;
    // warning: exception of type 'DerivedException' will be 
    //          caught by earlier handler for 'BaseException'
    } catch(BaseException& se) {
      std::cout << "caught BaseException object" << std::endl;
    } catch(DerivedException& de) {
      std::cout << "caught DerivedException object" << std::endl;
    } catch(...) {
      std::cout << "caught an UNKNOWN exception" << std::endl;
    }
  }
}
