//@desc 反转单链表
//@more 出是版本，更符合 c++ 形式的版本是2_more.cpp
#include <stack>
#include <iostream>

struct Node{
    int val;
    Node* next;
    Node(int _val):val(_val),next(nullptr){}
};

Node* init(){
    Node* _0 = new Node(0);
    Node* _1 = new Node(1);
    Node* _2 = new Node(2);
    Node* _3 = new Node(3);
    Node* _4 = new Node(4);
    Node* _5 = new Node(5);

    _0->next = _1;
    _1->next = _2;
    _2->next = _3;
    _3->next = _4;
    _4->next = _5;

    return _0;
}

Node* reverse(Node* l){
    if(l==nullptr){
        return l;
    }
    
    std::stack<Node*> st;

    while(l){
        st.push(l);
        l = l->next;
    }

    Node head(0);
    Node *headPtr = &head;

    while(!st.empty())
    {
        headPtr->next = st.top();
        st.pop();
        headPtr = headPtr->next;
    }
    headPtr->next = nullptr;
    
    return head.next;
}

void printList(Node* _list){
    while(_list){
        std::cout << _list->val << " ";
        _list = _list->next;
    }
    std::cout << std::endl;
}

int main(){
    Node* _list = init();
    printList(_list);
    printList(reverse(_list));
    return 0;
}
