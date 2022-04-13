//在一个数组中除了一个数字出现之外，其他数字都出现了三次，请找出这个只出现一次的数字
//可以用哈希表来做，可是空间复杂度为O(n)
//也可以用排序来做，可是排序时间复杂度为O(nlogn)
//要求：时间复杂度为O(n)，空间复杂度为O(1)

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using std::cout;
using std::endl;
/* using std::unordered_map; */
using std::vector;

//@layer: 最优解
int GetSingleNumByBit(const vector<int> &arr) {
  int bitArr[32]{};
  //@answer: 将所有value的二进制位数相加
  for (const auto &value : arr) {
    int flag = 1;
    for (int i = 31; i >= 0; --i) {
      if (value & flag) {
        bitArr[i] += 1;
      }
      flag <<= 1;
    }
  }
  int result = 0;
  //@answer: 只要二进制是1的位数的个数不是三的倍数，那就一定是那个独一无二的位数
  for (int i = 0; i < 32; ++i) {
    result <<= 1;
    result += bitArr[i] % 3;
  }
  return result;
}

//@layer: 次优解
/* int GetSingleNumByHashmap(const vector<int> &arr) { */
/*   int result{}; */
/*   unordered_map<int, int> map; */
/*   return result; */
/* } */

//@layer: 弱优解
/* int GetSingleNumBySort(vector<int> &arr) {} */

int main() {
  vector<int> arr{5, 5, 5, 7, 18, 7, 7};
  cout << GetSingleNumByBit(arr) << endl;
  return 0;
}
