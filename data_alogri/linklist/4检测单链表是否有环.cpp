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

struct Node {
  int value;
  Node *next;
  Node() : value(0), next(nullptr) {}
};

Node *InitLinklist() { return nullptr; }

//@Return: flase表示无环，true表示有环
//@Annotation: 采用快慢指针的方式来进行检测
bool IsLinklistLoop() {
  Node *head = InitLinklist();
  //@Annotation: 排除无结点和只有一个结点的情况
  if (nullptr == head)
    return false;
  Node *slow = head->next;
  if (nullptr == slow)
    return false;
  Node *fast = slow->next;
  //@Annotation: 核心算法解释
  //@1:
  //快指针在初始的时候比慢指针多一格，当快指针走到nullptr时，说明该单链表不成环,因此结束循环
  //@2:
  //当且仅当slow==fast时该链表成环。在fast向后移动一格之后如果不为nullptr，则再移动一格，一次移动两格效率更高
  while (slow != nullptr && fast != nullptr) {
    if (slow == fast) {
      return true;
    }
    slow = slow->next;
    fast = fast->next;
    if (fast != nullptr) {
      fast = fast->next;
    }
  }
  return false;
}
