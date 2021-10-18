#include <dbg.h>
#include <exception>
#include <new>
#include <sys/resource.h>

//@desc 测试不抛出异常的 ::operate new 
void test_nothrow_new(){
    char *p = new(std::nothrow) char[1024*1024*500];
    if (p==nullptr){
        dbg("alloc failed");
        return;
    }
    dbg("alloc success");
    delete [] p;
    return;
}

//@desc 测试抛出异常的 ::operate new
void test_plain_new()throw(std::bad_alloc){
    try{
        char *p = new char[1024*1024*800];
        dbg("alloc auccess");
        delete [] p;
    }catch(std::exception &e){
        dbg(e.what());
        dbg("alloc failed");
        throw;
    }
}

//@desc 测试 placement new
class A{
    int a;
    int b;
    public:
        A():a(1),b(1){
            dbg("use A constructor");
        }
        ~A(){
            dbg("use A deconstructor");
        }
};

void test_placement_new(){
    char *p = new(std::nothrow) char[sizeof(A)+1];
    if (p==nullptr){
        dbg("alloc failed");
        return;
    }
    A *q = new(p) A();
    //@desc 需要显示调用类对象的析构函数，否则就不会调用析构函数，容易引发 memory leak
    q->A::~A();
    delete [] p;
}

int main(){
    //@desc 设置limit RSS,避免由于分配不足被 killed 
    struct rlimit newlimit;
    newlimit.rlim_cur = 1024*1024*700;
    newlimit.rlim_max = 1024*1024*1024;
    setrlimit(RLIMIT_AS,&newlimit);

    test_nothrow_new();

    try{
        test_plain_new();
    }catch(std::exception &e){
        dbg(e.what(),"--------------");
    }


    test_placement_new();
    return 0;
}
