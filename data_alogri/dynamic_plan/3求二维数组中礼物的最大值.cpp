//---------------------------------
// File Name    : 3求二维数组中礼物的最大值.cpp
// Author       : aico
// Mail         : 2237616014@qq.com
// Github       : https://github.com/TBBtianbaoboy
// Site         : https://www.lengyangyu520.cn
// Create Time  : 2022-03-17 12:30:35
// Description  :
//----------------------------------

//@Summary: 完全符合动态规划的 4大特点

#include <iostream>
using std::cout;
using std::endl;

int getMaxValue(const int *arr, int raws, int cols) {
  //@answer: 首先排除特殊情况
  if (arr == nullptr || raws <= 0 || cols <= 0)
    return 0;

  //@answer: 核心算法
  int *maxs = new int[cols]{};
  for (int i = 0; i < raws; ++i) {
    for (int j = 0; j < cols; ++j) {
      int max_up = 0;
      int max_left = 0;
      if (i > 0)
        max_up = maxs[j];
      if (j > 0)
        max_left = maxs[j - 1];
      maxs[j] = (max_up > max_left ? max_up : max_left) + arr[i * raws + cols];
    }
  }

  //@answer: 获取最大值，释放堆空间，返回最大值
  int max = maxs[cols - 1];
  delete[] maxs;
  return max;
}

int main() {
  int a[16] = {1, 10, 3, 8, 12, 2, 9, 6, 5, 7, 4, 11, 3, 7, 16, 5};
  cout << getMaxValue(a, 4, 4) << endl;
  return 0;
}
