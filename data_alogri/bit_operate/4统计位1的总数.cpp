//---------------------------------
// File Name    : 4统计位1的总数.cpp
// Author       : aico
// Mail         : 2237616014@qq.com
// Github       : https://github.com/TBBtianbaoboy
// Site         : https://www.lengyangyu520.cn
// Create Time  : 2022-03-21 10:53:00
// Description  :
//----------------------------------
//@Summary: 左移补0
//          unsigned int 或正数int 右移补0 ，负数int 右移补1
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//@layer: 可能引起死循环的解法(只是简单地右移与1来进行计算)

//@layer: 常规解法 O(n)
int getIntBitCount2(const int &value) {
  int count{};
  unsigned int flag = 1;
  while (flag) {
    if (flag & value)
      ++count;
    flag <<= 1;
  }
  return count;
}
//@layer: 最优的解法 < O(n)
int getIntBitCount(int value) {
  int count{};
  while (value) {
    ++count;
    //@answer: 使用这种方式，无论value是正还是负，每次都会去掉value的最低位的1
    value &= value - 1;
  }
  return count;
}

int main() {
  int target{};
  cin >> target;
  cout << getIntBitCount(target) << endl;
  cout << getIntBitCount2(target) << endl;
  return 0;
}
