#include <dbg.h>
#include <string>

class A final {
    private:
        std::string str;
    public:
        //@desc 拷贝构造函数 @other 如果在构造函数前加关键字 explicit ,则禁止隐式调用
        A(const A& s):str(s.getStr()){dbg("A(const A&)");} 
        //@desc 构造函数重载
        A():str(""){dbg("A()");}
        //@desc 构造函数重载 @other 如果在构造函数前加关键字 explicit ，则禁止隐式调用
        A(const std::string &s):str(s){dbg("A(const std::string&)");}

        ~A(){}
        
        std::string getStr()const{
            return str;
        }
};

int main(){
    A a1;
    A a2(std::string("this is"));
    A a3(a2);
    dbg(a1.getStr(),a2.getStr(),a3.getStr());

    //@desc 隐式调用拷贝构造函数
    A a4 = a3;

    //@desc 隐式调用构造函数 
    A a5 = std::string("yyy");

    dbg(a4.getStr(),a5.getStr());
    
    return 0;
}
