//如何判断一个数是 2 的幂次

#include <iostream>
using std::cout;
using std::endl;

//@answer: 核心代码就一行
bool isTwoPow(int value) { return value != 0 && !(value & (value - 1)); }

int main() {
  int num{};
  std::cin >> num;
  cout << isTwoPow(num) << endl;
  return 0;
}
