//@author aico
//@desc unique_ptr 是一个类模板，在其内封装了指针，当实例化对象是，需要传入其他对象的指针作为参数，unique_ptr 没有采用引用计数的方式，故有如下两个 private 函数用做限制
#include <iostream>
#include <memory>
#include <string>

using std::cout;
using std::endl;

int main(){
    std::unique_ptr<std::string> ps1(new std::string("unique_ptr"));
    cout <<*ps1<<endl;

    // ------------------------------------------unique_ptr的 operator= 为 private; @des : error
    // std::unique_ptr<std::string> ps2;
    // ps2 = ps1;

    // ------------------------------------------unique_ptr的拷贝构造函数为 private; @des : error
    // std::unique_ptr<std::string> ps2(p1); @other std::unique_ptr<std::string> ps2 = ps1;
    
    return 0;
}

