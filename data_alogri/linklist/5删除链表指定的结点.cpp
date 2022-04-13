//给定链表的头结点和指定的结点，删除这个指定的结点

#include <iostream>
using std::cout;
using std::endl;

struct Node {
  int value;
  Node *next;
  Node(const int &v) : value(v), next(nullptr) {}
};

Node *deleteOneNode(Node *head, Node *toBeDeleted) {
  //@brief: 处理存空情况
  if (head == nullptr || toBeDeleted == nullptr)
    return head;
  //@breif: 删除头结点情况
  if (head == toBeDeleted) {
    toBeDeleted = head->next;
    delete head;
    return toBeDeleted;
  }
  //@brief: 删除尾结点情况
  if (toBeDeleted->next == nullptr) {
    Node *tmp = head;
    while (tmp->next != toBeDeleted)
      tmp = tmp->next;
    tmp->next = nullptr;
    delete toBeDeleted;
    return head;
  }
  //@brief: 处理正常情况
  toBeDeleted->value = toBeDeleted->next->value;
  Node *tmp = toBeDeleted->next;
  toBeDeleted->next = toBeDeleted->next->next;
  delete tmp;
  tmp = nullptr;
  return head;
}

int main() {
  auto print = [](Node *head) {
    if (head == nullptr)
      return;
    while (head) {
      cout << head->value << " ";
      head = head->next;
    }
    cout << endl;
  };

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

  print(n1);
  print(deleteOneNode(nullptr, n4));

  return 0;
}
