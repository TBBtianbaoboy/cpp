//@desc 测试在成员函数中调用 delete this 
#include <dbg.h>

class A {
    int a;
    const char b;
    public:
        A():a(1),b('c'){
            dbg("use A constructor");
        }
        ~A(){
            dbg("use A deconstructor");
            //@desc 非静态成员函数中都有 this 
            //@err 禁止这么做，会形成无限递归，导致堆栈溢出
            // delete this;
        }
        void print()const{
            dbg(this);
            dbg(a,b);
            //@desc 禁止这么做
            // delete this;
        }
        void test_failed(){
            dbg("--------",a,b);
        }
        static void test_ok();
};

void A::test_ok(){
    dbg("yes");
}

int main(int argc,char*argv[]){
    A *a = new A;
    a->print();
    //@desc 把对象delete 后，静态成员函数是可以正确访问到的
    A::test_ok();

    //@err 把对象delete 后，依旧可以访问其他成员函数，但会出现不可预期的错误
    //@why 牵扯到操作系统的内存管理策略，delete this 释放了类对象的内存空间，但是内存空间并不是马上被回收到系统中，此时这段内存依旧可以访问，但是其中的值是不确定的，也就是不可预期的错误
    //@que 这种问题，在操作数据成员以及调用虚函数表时，问题会很大，要避免
    a->test_failed();

    // a->print(); //@err double free
    return 0;
}


