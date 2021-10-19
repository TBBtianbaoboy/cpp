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
//@why 空白基类最优化，优化为 0 字节
class C:public A{
    private:
        int a;
    public:
        C():a(1){}
};

//@desc 基类private数据成员也会继承下来，只是不能访问
//@desc 基类虚函数表指针也会继承下来
class D:public C,public B{
    private:
        int a;
    public:
        D():a(2){
        }
};


int main(){
    dbg(sizeof(A),sizeof(B));
    dbg(sizeof(C),sizeof(D));
    return 0;
}
