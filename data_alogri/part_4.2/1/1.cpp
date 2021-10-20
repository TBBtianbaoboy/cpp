//@desc 合并两个有序单链表
#include <iostream>

struct myList{
    int value;
    myList *next;

    myList(int _val):value(_val),next(nullptr){}
};

myList* merge(myList* one,myList* two){
    if (one==nullptr)return two;
    if (two==nullptr)return one;

    myList head(0);
    myList* node = &head;

    while(one != nullptr && two != nullptr){
        //@desc 如果是升序就是 < ，如果是降序就是 >
        if(one->value > two->value){
            node->next = one;
            one = one->next;
        }
        else{
            node->next = two;
            two = two->next;
        }
        node = node->next;
    }

    if (one==nullptr){
        node->next = two;
    }else if(two == nullptr){
        node->next = one;
    }

    return head.next;
}

void printList(myList* l){
    while(l){
        std::cout << l->value << " " << std::endl;
        l = l->next;
    }
    std::cout << std::endl;
}

int main(int argc,char*argv[]){
    myList* node0 = new myList(5);    
    myList* node1 = new myList(4);    
    myList* node2 = new myList(3);    
    myList* node3 = new myList(2);    
    myList* node4 = new myList(1);    

    myList* node5 = new myList(3);    
    myList* node6 = new myList(2);    
    myList* node7 = new myList(1);    
    node0->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    node5->next = node6;
    node6->next = node7;
    printList(node0);
    printList(node5);
    printList(merge(node0,node5));
    
    return 0;
}
