#include <iostream>
#include <cstring>

struct DinStr {
  char* pStr;
  int length;
  int alloc;
};

void dsInit(DinStr& s) {
  s.alloc = 8;
  s.pStr = new char[s.alloc];
  *s.pStr = '\0';
  s.length = 0;
}

void dsPrint(const DinStr& s) {
  std::cout << s.pStr;
}

int dsLength(const DinStr& s) {
  return s.length;
}

int dsAlloc(const DinStr& s) {
  return s.alloc;
}

DinStr& dsCopy(DinStr& dest, const char* src) {
  int sLength = strlen(src);
  int incAlloc = dest.alloc;
  while(incAlloc < sLength + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > dest.alloc) {
    delete[] dest.pStr;
    dest.pStr = new char[incAlloc];
    dest.alloc = incAlloc;
  }

  strcpy(dest.pStr, src);
  dest.length = sLength;

  return dest;
}

DinStr& dsCopy(DinStr& dest, const DinStr& src) {
  int incAlloc = dest.alloc;
  while(incAlloc < src.length + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > dest.alloc) {
    delete[] dest.pStr;
    dest.pStr = new char[incAlloc];
    dest.alloc = incAlloc;
  }

  strcpy(dest.pStr, src.pStr);
  dest.length = src.length;

  return dest;
}

DinStr& dsCat(DinStr& dest, const char* src) {
  int incLength = dest.length + strlen(src);
  int incAlloc = dest.alloc;
  while(incAlloc < incLength + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > dest.alloc) {
    char* incStr = new char[incAlloc];
    strcpy(incStr, dest.pStr);
    delete[] dest.pStr;
    dest.pStr = incStr;
    dest.alloc = incAlloc;
  }

  strcat(dest.pStr, src);
  dest.length = incLength;

  return dest;
}

DinStr& dsCat(DinStr& dest, const DinStr& src) {
  int incLength = dest.length + src.length;
  int incAlloc = dest.alloc;
  while(incAlloc < incLength + 1) {
    incAlloc *= 2;
  }
  if(incAlloc > dest.alloc) {
    char* incStr = new char[incAlloc];
    strcpy(incStr, dest.pStr);
    delete[] dest.pStr;
    dest.pStr = incStr;
    dest.alloc = incAlloc;
  }

  strcat(dest.pStr, src.pStr);
  dest.length = incLength;

  return dest;
}

void dsFree(DinStr& s) {
  delete[] s.pStr;
  s.length = 0;
  s.alloc = 0;
}

int main() {
  DinStr s1, s2, s3;
  dsInit(s1);
  dsInit(s2);
  dsInit(s3);

  dsPrint(s1);
  std::cout << "Length of s1 is: " << dsLength(s1) << " / " << dsAlloc(s1) << std::endl;
  dsCopy(s1, "Hello\n");
  dsPrint(s1);
  std::cout << "Length of s1 is: " << dsLength(s1) << " / " << dsAlloc(s1) << std::endl;
  dsCat(s1, "World!\n");
  dsPrint(s1);
  std::cout << "Length of s1 is: " << dsLength(s1) << " / " << dsAlloc(s1) << std::endl;
  /*
  dsCopy(s1, "Welcome to ");
  dsCopy(s2, s1);
  dsCat(s2, "the world of ");
  dsCopy(s3, "C++ programming!\n");
  dsCat(s2, s3);
  dsPrint(s2);
  std::cout << "Length of s2 is: " << dsLength(s2) << " / " << dsAlloc(s2) << std::endl;
  */
  dsPrint(
    dsCat(
      dsCat(
        dsCopy(
          s2,
          dsCopy(
            s1,
            "Welcome to "
          )
        ),
        "the world of "
      ),
      dsCopy(
        s3,
        "C++ programming!\n"
      )
    )
  );
  std::cout << "Length of s1 is: " << dsLength(s2) << " / " << dsAlloc(s2) << std::endl;

  dsFree(s1);
  dsFree(s2);
  dsFree(s3);
}
