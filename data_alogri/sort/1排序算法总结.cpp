//---------------------------------
// File Name    : 1选择排序.cpp
// Author       : aico
// Mail         : 2237616014@qq.com
// Github       : https://github.com/TBBtianbaoboy
// Site         : https://www.lengyangyu520.cn
// Create Time  : 2022-03-14 12:45:43
// Description  :
//----------------------------------

//@Add: 优化方向：根据数据的分布状况和问题的需求来进行优化
//@Add: 对数器：将一个可靠的算法和自写的算法进行n次随机比对，如果结果都相同，则说明自写的算法没错，主要用于自测试
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

void swap(vector<int> &arr, const int &a, const int &b) {
    //@Care: arr[a] 和arr[b] 不能指向同一块内存
  arr[a] = arr[a] ^ arr[b];
  arr[b] = arr[a] ^ arr[b];
  arr[a] = arr[a] ^ arr[b];
}

//@Desc: 选择排序
//@Annotation: 选择排序是时间复杂度为O(n^2)的算法
//             不管数据的组成结构是什么样的，时间复杂度都不会变
//             额外空间复杂度为O(1)
//             核心代码就6行
void choose_sort(vector<int> &arr) {
  if (arr.size() < 2)
    return;
  for (int i = 0; i < arr.size() - 1; ++i) {
    int min_index = i;
    for (int j = i + 1; j < arr.size(); ++j)
      min_index = arr[j] < arr[min_index] ? j : min_index;
    if (min_index != i)
      swap(arr, i, min_index);
  }
}

//@Desc: 冒泡排序
//@Annotation: 冒泡排序是时间复杂度为O(n^2)的算法
//             不管数据的组成结构是什么样的，时间复杂度都不会变
//             额外空间复杂度为O(1)
//             核心代码就4行
void bubble_sort(vector<int> &arr) {
  if (arr.size() < 2)
    return;

  for (int i = 0; i < arr.size() - 1; ++i)
    for (int j = 0; j < arr.size() - i; ++j)
      if (arr[j] > arr[j + 1])
        swap(arr, j, j + 1);
}

//@Desc: 插入排序
//@Annotation: 插入排序是时间复杂度为O(n^2)的算法
//             会与数据的组成结构有影响，有最坏/最好的情况，所以总体上来说比冒泡排序和选择排序更好
//             额外空间复杂度为O(1)
//             核心代码就3行
void insert_sort(vector<int> &arr) {
  if (arr.size() < 2)
    return;

  for(int i=0;i<arr.size()-1;++i)
      for(int j=i+1;j>0 && arr[j]<arr[j-1];--j)
          swap(arr,j,j-1);
}

//@Desc: 归并排序 TODO:存在问题，暂时没发现
//@Annotation: 归并排序是时间复杂度为O(nlogn)的算法
//             会与数据的组成结构有影响，有最坏/最好的情况，所以总体上来说比冒泡排序和选择排序更好
//             额外空间复杂度为O(n)
//             merge的核心代码就1行，采用条件表达式来处理，如果数值相等先拷贝右值
void merge(vector<int> &arr,int l,int mid,int r){
    int *tmp = new int[r-l+1]{};
    int p1 = l;
    int p2 = mid+1;
    int i = 0;
    // for(int i=l;i<=r;++i)
    //     cout << arr[i] << " " ;
    // cout << endl;
    while(p1 << mid && p2<=r)
    {
        tmp[i++] = arr[p1]<arr[p2]?arr[p1++]:arr[p2++];
    }
    while(p1<=mid)
        tmp[i++] = arr[p1++];
    while(p2<=r)
        tmp[i++] = arr[p2++];
    for(i=0;i<r-l+1;++i)
        arr[l+i] = tmp[i];
    // for(int i=0;i<r-l+1;++i)
    //     cout << tmp[i] <<" ";
    // cout << endl;
    delete [] tmp;
}

void merge_sort(vector<int> &arr,int l,int r) {
  if (l==r)
    return;
  int mid = l + ((r-l)>>1); //采用>>的方式来求中点，无懈可击，不但不会溢出，而且运行更快
  merge_sort(arr,l,mid);
  merge_sort(arr,mid+1,r);
  merge(arr,l,mid,r);
}


//@Desc: 插入排序
//@Annotation: 插入排序是时间复杂度为O(n^2)的算法
//             会与数据的组成结构有影响，有最坏/最好的情况，所以总体上来说比冒泡排序和选择排序更好
//             额外空间复杂度为O(1)
//             核心代码就3行
void quick_sort(vector<int> &arr) {
  if (arr.size() < 2)
    return;

}

void print(const vector<int> &arr) {
  for (const auto &value : arr)
    cout << value << endl;
}

int main() {
  vector<int> arr{5,3, 2, 7, 1, 8, 2, 4, 0, 9};
  // choose_sort(arr);
  // bubble_sort(arr);
  // insert_sort(arr);
  // merge_sort(arr,0,arr.size()-1);
  print(arr);
  return 0;
}
