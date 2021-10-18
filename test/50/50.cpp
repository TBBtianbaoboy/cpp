//@desc 探究引用的底层实现
#include <dbg.h>

//@desc 采用结构体探究
struct Test{
    // int &p; //@aim 8 B
    char &p;   //@aim 8 B
};

int main(){
    //@desc 这样看不出来，编译器屏蔽引用地址
    int x = 1;
    int &b = x;
    dbg(&x,&b);

    //@desc 探究结构体
    dbg(sizeof(Test));
    return 0;
}

//@summary 引用存的就是指针
//引用地址对外不可见
//引用占存储空间 位数 / 8
