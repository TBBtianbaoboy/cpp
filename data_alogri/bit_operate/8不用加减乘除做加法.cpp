//@Summary: 只能考虑使用位运算
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int getTwoIntSum(int n1, int n2) {
  int tmp1, tmp2;
  do {
    //@answer: 第一步先相加不进位
    tmp1 = n1 ^ n2;
    //@answer: 第二步计算进位
    tmp2 = (n1 & n2) << 1;
    n1 = tmp1;
    n2 = tmp2;
    //@answer: 直到没有进位为止
  } while (tmp2);
  return tmp1;
}

int main() {
  int n1, n2;
  cin >> n1 >> n2;
  cout << getTwoIntSum(n1, n2) << endl;
  return 0;
}
