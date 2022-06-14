//@brief: [Floding reference] is called by template derivation default, can't be
// used manually.
//@brief: [Universal reference] is called in template by using T &&.This way can
// accept any value.
//@brief: [Perfectly forward] is used in template for delivery parameter to
// other function with corresponding value type.

#include <iostream>
using std::cout;
using std::endl;

template <class T> void perfectlyForward(T &param) {
  cout << param << "lvalue" << endl;
}

template <class T> void perfectlyForward(T &&param) {
  cout << param << "rvalue" << endl;
}

template <class T> void universalReferenceFunction(T &&param) {
  //@brief: Inside the function,all reference is left value reference.
  //@brief: forward function template convert param to T type
  perfectlyForward(std::forward<T>(param));
}

int main() {
  int a = 3;
  int &b = a;
  universalReferenceFunction(a);      // T is int&
  universalReferenceFunction(b);      // T is int&
  universalReferenceFunction((int)4); // T is int
}
