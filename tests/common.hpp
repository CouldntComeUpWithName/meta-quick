#pragma once

struct some_info {
  float f;
  int n;
};

typedef struct {
  int data;
} another_struct;

class Clazz {
public:
  Clazz() = default;
  ~Clazz() = default;
private:
  char data[1024];
};

enum Enum {
  A,
  B,
  C,
  D,
};

enum class EnumClass {
  A,
  B,
  C,
  D,
};

union MyUnion {
  int a;
  float b;
  void* ptr;
};


class Base {

};

class Derived : public Base {

};