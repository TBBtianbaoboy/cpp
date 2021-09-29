#include<iostream>
#include<string>
#include<memory>
using std::string;
using std::cout;
using std::endl;

int main(){
    std::shared_ptr<string> p1(new string("good"));
    cout << p1.use_count()<<endl;

    // p1.reset(); //@desc 断开了连接之后，string 对象被销毁，以下的过程都无效

    std::weak_ptr<string> p2 = p1;
    cout<< p2.use_count() << endl; //@desc weak_ptr不会增加引用计数

    if(p2.lock()) // @desc weak_ptr 的 lock() 方法用于转化为 shared_ptr 对象，然后才可以使用 shared_ptr 的方法
        cout << *p2.lock() << endl;
    //@other 使用如下方式也可以达到上述的效果,但是会传建一个 shared_ptr 对象，所以引用计数会 +1
    try{
        std::shared_ptr<string> p3(p2);
        cout << *p3 << " " << p3.use_count() <<endl;
    }
    catch(std::bad_weak_ptr){
        cout << "old object is delete" <<endl;
    }
    return 0;
}
