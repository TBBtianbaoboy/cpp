//@Annotation 有关构造与析构的顺序| 有关初始化列表的疑问
#include <iostream>

using std::cout;
using std::endl;

class Base{
    protected:
        int a;
        //@desc 引用数据成员必须在初始化列表初始化
        int &b;
        char c;
        //@desc 初始化一个常量成员时必须在初始化列表中初始化
        const int d;
    public:
        Base(int a_,char c_):a(a_),c(c_),d(a_),b(a){
            cout <<"构造基类"<<endl;
        }
        ~Base(){
            cout <<"释放基类"<<endl;
        }
        virtual void print()const{
            cout << "a = "<<a <<",c = "<<c<<endl;
        }
};

class Friend{
    int a;
    public:
    Friend(int a_):a(a_){
        cout <<"构造组合类"<<endl;
    }
    ~Friend(){
        cout <<"释放组合类"<<endl;
    }
};

class Derived_1:public Base{
    private:
        //@desc 除了组合类构造和基类构造更优先外，子类的数据成员构造顺序由声明顺序决定，而不是在初始化列表中的顺序决定
        int d1_a;
        char d1_c;
        //@desc 组合类的构造晚于基类，早于子类，而且，没有默认构造的组合类必须在初始化列表显示构造
        Friend fr;
    public:
        //@desc 没有默认构造的基类必须在初始化列表显示构造
        //@desc 初始化列表的初始化工作在子类构造函数体之前就会完成，意思就是说基类和组合类以及子类的数据成员的初始化在子类构造函数体之前完成
        Derived_1(int a_,char c_,int d1_a_,char d1_c_):Base(a_,c_),d1_a(d1_a_),d1_c(d1_c_),fr(4){
            cout <<"构造子类"<<endl;
        }
        ~Derived_1(){
            cout <<"释放子类"<<endl;
        }
        virtual void print()const override{
            cout << a << " " << c <<" " << d1_a <<" " << d1_c <<endl;
        }
};

int main(){
    Derived_1 a(1,'1',2,'2');
    a.print();
    return 0;
}


