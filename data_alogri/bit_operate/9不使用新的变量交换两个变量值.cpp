//经常会被使用的
#include <iostream>
using std::cout;
using std::endl;

//@brief: 基于最基本的+-进行交换
void reverseTwoVar(int a, int b) {
  a = a + b;
  b = a - b;
  a = a - b;
  cout << a << b << endl;
}

//@brief: 基于位运算进行交换
void reverseTwoVar2(int a, int b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
  cout << a << b << endl;
}

int main() {
  reverseTwoVar(1, 2);
  reverseTwoVar2(1, 2);
  return 0;
}
