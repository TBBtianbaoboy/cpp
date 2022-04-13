// 根据给定的前序遍历数组和中序遍历数组，请输出后序遍历的结果
#include <iostream>
using std::cout;
using std::endl;
int pre[] = {1, 2, 3, 4, 5, 6};
int mid[] = {3, 2, 4, 1, 6, 5};
int last[] = {3, 4, 2, 6, 5, 1};

//@answer:root是根节点在pre中的下标，start和end是在mid中用来切割左子树和右子树的下标
void get_last(int root, int start, int end) {
  if (start > end)
    return;
  int i = start;
  //在中序遍历中找到根
  while (i < end && mid[i] != pre[root])
    ++i;
  //优先遍历左子树
  get_last(root + 1, start, i - 1);
  //再遍历右子树，关键是root+i+1-start
  get_last(root + 1 + i - start, i + 1, end);
  //输出根
  cout << pre[root] << " ";
}

//@answer: 扩充：根据中序遍历和后序遍历求前序遍历
void get_pre(int root, int start, int end) {
  if (start > end)
    return;
  int i = start;
  while (i < end && mid[i] != last[root])
    ++i;
  //输出根
  cout << last[root] << " ";
  //再遍历左子树
  get_pre(root + i - 1 - end, start, i - 1);
  //最后遍历右子树
  get_pre(root - 1, i + 1, end);
  return;
}

int main() {
  get_last(0, 0, 5);
  cout << endl;
  get_pre(5, 0, 5);
  cout << endl;
  return 0;
}
