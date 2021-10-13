#include <iostream>
#include <dbg.h>

//@desc 宏定义，在预处理期进行替换 g++ -E 13.cpp -o 13.i 可以查看到预处理后的代码的内容
//@desc 宏定义没有返回值
//@desc 宏定义的参数没有类型，不会进行类型检查
#define max(a,b) (((a)>(b))?(a):(b))

int main(){
    int max = max(5,2);
    dbg(max);
    return 0;
}
