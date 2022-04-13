//获取链表倒数第k个结点和删除链表倒数第k个结点
#include <iostream>
using std::cout;
using std::endl;

struct Node {
  int value;
  Node *next;
  Node(const int &v) : value(v), next(nullptr) {}
};

Node *DelteKnum(Node *list, unsigned int n) {
  //@brief: 排除特殊情况
  if (list == nullptr || n == 0)
    return list;
  int i = 0;
  Node *two = list;
  while (i < n && two) {
    two = two->next;
    ++i;
  }
  //@brief: 检测n是否超出链表的长度
  if (i != n)
    return list;
  Node *one = list;
  Node *pre = nullptr;
  while (two != nullptr) {
    pre = one;
    one = one->next;
    two = two->next;
  }
  //@brief: 删除的是头结点
  if (pre == nullptr) {
    pre = one->next;
    delete one;
    return pre;
  }
  //@brief: 头尾结点皆可如此
  pre->next = one->next;
  delete one;
  return list;
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  auto print = [](Node *head) {
    if (head == nullptr)
      return;
    while (head) {
      cout << head->value << " ";
      head = head->next;
    }
    cout << endl;
  };
  print(DelteKnum(n1, 6));
  return 0;
}
