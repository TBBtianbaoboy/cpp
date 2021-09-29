//@author aico
//@desc shared_ptr 用来共享同一对象,采用引用计数的方式连接对象,拷贝构造函数和 operator= 都是 public 
#include <iostream>
#include <memory>

using std::string;
using std::cout;
using std::endl;

int main(){
    std::shared_ptr<string> p1(new string("good"));
    cout << *p1 << p1.use_count()<< endl;//@desc 获取引用计数的值
    std::shared_ptr<string> p2(p1);
    cout << *p2 << p2.use_count()<< endl;
    std::shared_ptr<string> p3 = p1;
    cout << *p3 <<p3.use_count()<< endl;
   
    std::shared_ptr<string> p4;
    p4 = p1;
    cout << *p4 <<p4.use_count() << endl;

    p2.reset(); //@desc 断开与原来的连接，引用计数 -1 
    cout << p1.use_count()<<endl;
    return 0;
}

//@question 既然是引用计数，那么自然就不可避免 循环引用 的问题
//@answer 解决这个问题，需要用到 weak_ptr
