//---------------------------------
//File Name    : 1移动字符串的前n个字母置末尾.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-09 14:40:36
//Description  : 
//----------------------------------
#include <iostream>
#include <string>
#include <queue>

using std::cout;
using std::endl;
using std::string;
using std::queue;

class T {
    private:
        string str;
    public:
        T(const char *s = nullptr);
        ~T();
        T(const T&);
        T& operator=(const T&);
        bool move(int);
        void print()const;
};

T::T(const char* s):str(s){}
T::~T(){}
T::T(const T& other):str(other.str){}
T& T::operator=(const T& s){
    str = s.str;
    return *this;
}
//@Annotation 这里是算法的核心,左右移，采用STL queue来解决问题
bool T::move(int n){
    if(str.size()==0)
        return false;
    queue<char> que;
    for(int i=0;i<n;++i){
        que.push(str[i]);
    }
    for(int i=n;i<str.size();++i){
        str[i-n] = str[i];
    }
    for(int i=str.size()-n;i<str.size();++i){
        str[i] = que.front();
        que.pop();
    }
    return true;
}

void T::print()const{
    cout << str << endl;
}

int main(){
    T a("123456789");
    a.print();
    a.move(5);
    a.print();

    // T b(a);
    // b.print();
    // T c("a");
    // c = b;
    // c.print();
    return 0;
}
