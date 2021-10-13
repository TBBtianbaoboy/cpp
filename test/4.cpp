//@desc 探讨何时使用指针，何时使用引用

#include <dbg.h>

//@desc 以下这两种方式使用会出错，只有针对非局部变量才可用,第一种方式可以使用堆，但是不够好！
// int* getnum(int a,int b){
//     int c = a + b;
//     return &c;
// }

// int& getnum(int a,int b){
//     int c = a + b;
//     return c;
// }

int* getnum(int a,int b){
    int *c = new int;
    *c = a + b;
    return c;
}
int main(){
    int* p = getnum(1,2);
    dbg(p,*p);
    if (p) delete p;
    p = nullptr;
    return 0;
}
