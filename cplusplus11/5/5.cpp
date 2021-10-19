//@desc lambda 表式式,捕获体和函数体不能省略，其他的都可以省略,而且，lambda 表达式重载了() 运算符,似仿函数
//@example [caputer](args)options -> return {};
#include <dbg.h>
#include <iostream>
#include <ostream>

class Test{
    private:
        int n;
    public:
        Test():n(10){}
        void output(int x,int y){
            //@desc 此时 x1 是一个变量
            //@right 不捕获任何外部变量
            auto x1 = [](int a)->int{return a;}(5);
            std::cout << x1 << std::endl;

            //@desc 此时 x2 是一个函数对象
            //@right 以值拷贝的方式捕获所有外部变量，包括x,y,this
            auto x2 = [=](const int& a)->int{
                //@right 以值拷贝的方式捕获到的 this 可以读写其指向的数据成员
                this->n = this->n + x + y + a;
                // @err 以值拷贝的方式捕获到的所有外部变量都是只读的
                // x = 1;  int -> const int
                // y = 1;  int -> const int
                // this = nullptr;  Test * const -> Test * const
                return this->n;
            };
            std::cout << x2(1) << x << y << std::endl;

            //@desc 此时 x3 是一个变量
            //@right 以引用的方式捕获所有外部变量,包括x,y,this
            auto x3 = [&](int a)->int{
                // @right 以引用的方式捕获到的所有外部变量都是可读写的,除(this)
                ++x;
                ++y;
                //@err
                // this = nullptr;
                //@right 以引用的方式捕获到的 this 可以读写其指向的数据成员
                this->n = this->n + x + y + a;
                return this->n;
            }(3);
            std::cout << x3 << x << y << std::endl;

            //--------------------------------------------------------------------------------------------------
            
            //@desc 使用 mutable 选项可以修改以值拷贝的方式捕获到的外部变量
            auto x4 = [=](int a)mutable->int{
                ++x;
                ++y;
                //@err this指针的指向是永远不可能变的
                //this = nullptr
                this->n = x+a;
                return this->n;
            }(3);
            std::cout << x4 << x << y << std::endl;



            //@desc 对于没有捕获任何变量的 lambda 表达式，还可以转换成一个普通的函数指针
            using func_ptr = int(*)(int);
            func_ptr func = [](int a)->int{
                return a;
            };
            std::cout << func(10) << std::endl;

        }
};

int main(){
    Test t;
    t.output(3, 4);
    return 0;
}
