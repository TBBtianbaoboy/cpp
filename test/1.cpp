//@desc 测试 main 函数之前和之后发生了什么

#include <cstdlib>
#include <iostream>
#include <dbg.h>

class Test{
    private:
        int a;
        char b;
    public:
        Test():a(1),b('O'){}
        Test(const Test&)=delete;
        Test& operator=(const Test&)=delete;
        ~Test(){
            dbg("after main!");
        }
        int getInt()const{
            return a;
        }
        char getChar()const{
            return b;
        }
};

//@desc store in .data field
int int_m; //global int
char char_m; //global char
bool bool_m; //global bool
int* ptr_m; //global pointer

//@desc 根据运行结果，可以确知，全局对象的析构函数在 main 函数之后运行
Test test_m; //global class object

//@desc store in .bss
static bool static_m; //global static

void after_main();

int main(int argc,char *argv[]){
    //@desc 根据以下内容，可以确知参数部分在main运行之前赋值，并以引用的方式使用
    dbg(argc);
    if(argc!=2){
        exit(1);
    }
    dbg(argv[0],argv[1]);

    //@desc 根据以下内容，可以确知全局未初始化变量的赋值情况以及全局类对象的构造函数在 main 之前运行
    dbg(int_m,char_m,bool_m,ptr_m,test_m.getInt(),test_m.getChar());

    //@desc 根据以下内容，可以确知全局静态变量的初始化赋值情况
    dbg(static_m);

    //@desc 使用 atexit 函数注册一个函数，在 main 之后运行
    atexit(after_main);

    return 0;
}

void after_main(){
    dbg("this function excute after main");
}
