//@desc 探究类大小
#include <dbg.h>

//@desc 空类占一个字节
//@why 为了保证当前空类的实例均有独一无二的地址
class A{
};

//@desc 多态类占 8 个字节
class B{
    public:
        virtual ~B(){}
};


//@desc 继承自空类占 4 个字节
class C:public A{
    private:
        int a;
    public:
        C():a(1){}
};


int main(){
    dbg(sizeof(A),sizeof(B));
    dbg(sizeof(C));
    return 0;
}
