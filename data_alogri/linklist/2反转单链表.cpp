//@desc 反转链表 纯c++ 版本
#include <stack>
#include <iostream>
#include <dbg.h>

class Node{
        int val;
        Node *next;
    public:
        Node(int _val=0):val(_val),next(nullptr){}
        ~Node(){}
        Node* getNext()const{
            return next;
        }
        void setNext(Node* _node){
            next = _node;
        }
        int getVal()const{
            return val;
        }
};

class List final{
    Node *head;
    Node *tail;
    int size;
    public:
        List():head(nullptr),tail(nullptr),size(0){
            head = new Node();
            tail = head;
        }
        ~List(){
            while(head!=nullptr){
                Node* _head = head->getNext();
                delete head;
                head = _head;
            }
        }
        //@desc forbidden 
        List(const List&)=delete;
        List& operator=(const List&)=delete;
        //@desc 追加结点
        void append(int val){
            Node* newNode = new Node(val);
            tail->setNext(newNode);
            ++size;
            tail = tail->getNext();
        }
        //@desc 反转链表
        void reverse(){
            Node* body = head->getNext();
            if(body==nullptr){
                return ;
            }
            tail = head;  
            std::stack<Node*> st;

            while(body){
                st.push(body);
                body = body->getNext();
            }

            while(!st.empty())
            {
                tail->setNext(st.top());
                st.pop();
                tail = tail->getNext();
            }
            tail->setNext(nullptr); 
        }
        //@desc 打印链表
        void print()const{
            Node* n = head->getNext();
            while(n){
                std::cout << n->getVal() << " ";
                n = n->getNext();
            }
            std::cout << std::endl;
        }
};

int main(){
    List l;
    l.append(1);
    l.append(2);
    l.append(3);
    l.append(4);
    l.append(5);
    l.print();
    l.reverse();
    l.print();
    return 0;
}
