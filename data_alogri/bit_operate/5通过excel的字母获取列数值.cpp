#include <cmath>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int getColByAB(const string &col) {
  int colSize = col.size();
  int result{};
  for (int i = colSize - 1; i >= 0; --i) {
    //@answer: 转化为26进制进行计算
    result += (col[i] - 'A' + 1) * std::pow(26, colSize - i - 1);
  }
  return result;
}

int main() {
  string target;
  cin >> target;
  cout << getColByAB(target) << endl;
  return 0;
}
