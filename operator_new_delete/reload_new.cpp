#include <cstddef>
#include <iostream>
#include <new>
#include <ostream>
#include <string>

void* operator new(std::size_t n,std::string file,int line){
    std::cout << "size : "<< n <<std::endl;
    std::cout << "new at : "<<file<<",line "<<line<<std::endl;
    return ::operator new(n);
}

void operator delete(void *ptr,std::string file,int lint){
    std::cout<<"delete at : " << file <<",line "<<lint<<std::endl;
    ::operator delete(ptr);
    return;
}
// #define new new(__FILE__,__LINE__)
int main(){
    // char *p = new char('a');
    char *p = new(__FILE__,__LINE__) char;    //重载的 new 可以直接带参数使用的，只要重载了相对应的形式就可以，其他的不用管
    ::operator delete(p,__FILE__,__LINE__);    //重载的delete需要加 operator 前缀才可以使用，而且格式必须如左所示，在这里 :: 可以不要 ，仅代表全局的意思
    int *a = new int[10];
    delete [] a;// ::operator delete[](a);
    return 0;
}
