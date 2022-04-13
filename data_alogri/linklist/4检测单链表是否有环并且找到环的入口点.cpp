//---------------------------------
// File Name    : 4检测单链表是否有环.cpp
// Author       : aico
// Mail         : 2237616014@qq.com
// Github       : https://github.com/TBBtianbaoboy
// Site         : https://www.lengyangyu520.cn
// Create Time  : 2022-03-08 18:13:56
// Description  :
//----------------------------------
#include <iostream>
using std::cout;
using std::endl;

struct Node {
  int value;
  Node *next;
  Node(const int &v) : value(v), next(nullptr) {}
};

//@Annotation: 采用快慢指针的方式来进行检测
Node *IsLinklistLoop(Node *head) {
  //@Annotation: 排除无结点和只有一个结点的情况
  if (nullptr == head)
    return head;
  Node *slow = head->next;
  if (nullptr == slow)
    return nullptr;
  Node *fast = slow->next;
  //@Annotation: 核心算法解释
  //@1:
  //快指针在初始的时候比慢指针多一格，当快指针走到nullptr时，说明该单链表不成环,因此结束循环
  //@2:
  //当且仅当slow==fast时该链表成环。在fast向后移动一格之后如果不为nullptr，则再移动一格，一次移动两格效率更高
  while (slow != nullptr && fast != nullptr) {
    if (slow == fast) {
      return fast;
    }
    slow = slow->next;
    fast = fast->next;
    if (fast != nullptr) {
      fast = fast->next;
    }
  }
  return nullptr;
}

Node *getLoopEntry(Node *head) {
  //@brief: 首先检测链表是否有环
  Node *ptr = IsLinklistLoop(head);
  if (ptr == nullptr)
    return ptr;
  //@brief: 其次获取环的长度
  int loopLength = 1;
  Node *tmp = ptr->next;
  while (tmp != ptr) {
    tmp = tmp->next;
    ++loopLength;
  }
  //@brief: 将双指针的第二个指针移动到环长度位置
  ptr = head;
  tmp = head;
  for (int i = 0; i < loopLength; ++i) {
    tmp = tmp->next;
  }
  //@brief: 双指针同时向后移动一个位置，相遇的结点则是环入口
  while (ptr != tmp) {
    tmp = tmp->next;
    ptr = ptr->next;
  }
  return ptr;
}

int main() {
  Node *n1 = new Node(1);
  Node *n2 = new Node(2);
  Node *n3 = new Node(3);
  Node *n4 = new Node(4);
  Node *n5 = new Node(5);
  Node *n6 = new Node(6);
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;
  n4->next = n5;
  n5->next = n6;
  n6->next = n6;
  auto print = [](Node *head) {
    Node *tmp = getLoopEntry(head);
    if (tmp == nullptr)
      return;
    cout << tmp->value << endl;
  };
  print(n1);
  return 0;
}
