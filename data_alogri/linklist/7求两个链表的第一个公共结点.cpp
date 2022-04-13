//该题目也可以扩展成求二叉树中两个结点的最低公共祖先
#include <iostream>
using std::cout;
using std::endl;

struct Node {
  int value;
  Node *next;
  Node(const int &v) : value(v), next(nullptr) {}
};

//@brief: 时间复杂度为O(m+n),空间复杂度为O(1)
//如果用栈进行求解的话也可以，只是时间复杂度是O(min(m,n)),空间复杂度为O(m+n)
Node *getXNode(Node *n1, Node *n2) {
  if (n1 == nullptr || n2 == nullptr)
    return nullptr;
  //@brief: 首先分别计算两个链表的长度
  int length1{}, length2{};
  Node *tmp1 = n1;
  Node *tmp2 = n2;
  while (tmp1) {
    ++length1;
    tmp1 = tmp1->next;
  }
  while (tmp2) {
    ++length2;
    tmp2 = tmp2->next;
  }
  //@brief: 分别处理长度差问题
  if (length1 > length2) {
    for (int i = 0; i < length1 - length2; ++i)
      n1 = n1->next;
  } else if (length2 > length1) {
    for (int i = 0; i < length2 - length1; ++i)
      n2 = n2->next;
  }
  //@brief: 同时向后进行移动，直到地址相同位置
  while (n1 != n2) {
    n1 = n1->next;
    n2 = n2->next;
  }
  return n1;
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  Node *n7 = new Node(7);
  n1->next = n2;
  n2->next = n3;
  n3->next = n6;
  n6->next = n7;
  n4->next = n5;
  n5->next = n6;

  auto print = [](Node *n) {
    if (n == nullptr)
      return;
    cout << n->value << endl;
  };

  print(getXNode(n1, n4));
  return 0;
}
