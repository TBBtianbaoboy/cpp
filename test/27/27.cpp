//@desc discuss keywork override and final

#include <dbg.h>
#include <memory>

class A {
    protected:
        int length;
        int width;
    public:
        A():length(2),width(3){}
        virtual ~A(){}
        A(const A&)=delete;
        A& operator=(const A&)=delete;
        virtual int getV()=0;
        //@desc 关键字 final 表示虚函数 test_final 不可以被重写(override)
        virtual void test_final()final{

        }
};

//@desc 关键字 final 表示类 B 不可以被继承，也就是不能再作为其他类的夫类
class B final:public A {
    private:
        int c;
    public:
        B():c(4){}
        virtual ~B(){}
        //@desc 关键字 override 用来表示这个函数重写了基类的某个虚函数,有了这个关键字，可以确保重写正确
        virtual int getV() override{
            return (length*width*c);
        }
};

//@err 编译错误
// class C:public B{
// } ;

//@err 编译错误
// class D:public A {
//     public:
//         //@err 类 A 中的 虚函数 test_final 不可以被重写(override)
//         virtual void test_final() override;
// }

int main(){
    std::shared_ptr<A> t1(new B);
    dbg(t1.use_count(),t1->getV());
    return 0;
}
