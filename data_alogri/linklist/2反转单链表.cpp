#include <iostream>
using std::cout;
using std::endl;

struct Node {
  int value;
  Node *next;
  Node(const int &v) : value(v), next(nullptr) {}
};

Node *reverseList(Node *head) {
  if (head == nullptr || head->next == nullptr)
    return head;

  //@answer: use three pointer to reverse forward list
  Node *pre = head;
  Node *now = head->next;
  Node *last = now->next;

  pre->next = nullptr;
  while (last) {
    now->next = pre;
    pre = now;
    now = last;
    last = last->next;
  }
  now->next = pre;
  return now;
}

Node *initList() {
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

  return n1;
}

void printList(Node *head) {
  if (head) {
    while (head) {
      cout << head->value << " ";
      head = head->next;
    }
    cout << endl;
  }
}

int main() {
  Node *head = initList();
  printList(head);
  printList(reverseList(head));
  return 0;
}
