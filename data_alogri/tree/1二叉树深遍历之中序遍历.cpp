//---------------------------------
// File Name    : 1二叉树深遍历之中序遍历.cpp
// Author       : aico
// Mail         : 2237616014@qq.com
// Github       : https://github.com/TBBtianbaoboy
// Site         : https://www.lengyangyu520.cn
// Create Time  : 2022-03-09 16:11:56
// Description  :
//----------------------------------
#include <iostream>
#include <stack>

using std::cout;
using std::endl;
using std::stack;

struct Node {
public:
  int value;
  Node *left;
  Node *right;
  Node(const int &v = 0) : value(v), left(nullptr), right(nullptr) {}
};

class Tree final {
private:
  Node *head;
  int size;

public:
  Tree() : head(nullptr), size(0) {}
  //@Annotation: 中序遍历内容，使用栈来存储待访问结点,先将左子树遍历入栈,然后访问。可以使之有序输出
  void Print() const;
  //@Annotation: 数据插入内容
  void Insert(const int &value = 0);
  // void Delete();
};

void Tree::Print() const {
    stack<Node*> nodeStack;
    Node* p = head;
    while(!nodeStack.empty() || p){
        if(p){
            nodeStack.push(p);
            p = p->left;
        }else{
            p = nodeStack.top();
            cout << p->value << endl;
            p = p->right;
            nodeStack.pop();
        }
    }

}

void Tree::Insert(const int &value) {
  if (head == nullptr) {
    head = new Node(value);
    return;
  }
  Node *tmp = head;
  while (true) {
    if (value <= tmp->value) {
      if (tmp->left == nullptr) {
        tmp->left = new Node(value);
        break;
      } else
        tmp = tmp->left;
    } else {
      if (tmp->right == nullptr) {
        tmp->right = new Node(value);
        break;
      } else
        tmp = tmp->right;
    }
  }
}

int main() {
  Tree a;
  a.Insert(10);
  a.Insert(7);
  a.Insert(4);
  a.Insert(5);
  a.Insert(14);
  a.Insert(13);
  a.Insert(1);
  a.Insert(3);
  a.Insert(10);
  a.Print();
}
