// 输入两个数m和n，计算需要改变m的二进制表示中的多少位才能得到n

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int getCount(const int &m, const int &n) {
  //@answer: 通过异或获取不同位
  int value = m ^ n;
  int count{};
  while (value) {
    ++count;
    //@answer: 计算有多少个不同位
    value &= value - 1;
  }
  return count;
}

int main() {
  int m, n;
  cin >> m >> n;
  cout << getCount(m, n) << endl;
  return 0;
}
