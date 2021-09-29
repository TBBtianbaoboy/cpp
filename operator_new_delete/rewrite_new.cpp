// 重写 operator new ，即使用自己定的 new 来管理内存的分配
// 为了与 operator new 对应，同样也要重写 operator delete 

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <new>
#include <sys/resource.h>

using std::cout;
using std::endl;

void my_new_handle();
int *p = nullptr;
void* operator new(std::size_t size){
    void *ptr = nullptr;
    cout << "use myself rewrited operator new" << endl;
    if(size == 0)
        size = 1;

    while(1){
        ptr = malloc(size);
        if(ptr){
            cout << "get memory: " << size << "B" << endl;
            return ptr;
        }
        // std::new_handler globalhandler = std::get_new_handler();
        std::new_handler globalhandler = std::set_new_handler(0);
        std::set_new_handler(globalhandler);

        if(globalhandler){
            cout << "call new_handler" << endl;
            globalhandler();
        }else{
            cout << "no memory,no new_handler" <<endl;
            throw std::bad_alloc();
        }
    }
}

void operator delete(void *ptr){
    cout << "use myself rewrited operator delete" << endl;
    free(ptr);
}

int main(){
    //设置虚拟内存的大小，这样的分配的内存空间不能超过此
    //如果不设置的话，由于内存分配不足，会被 OOM killer SIGKILL
    struct rlimit newlimit;
    newlimit.rlim_cur = 1024*1024*700;
    newlimit.rlim_max = 1024*1024*1024;
    setrlimit(RLIMIT_AS,&newlimit);

    std::set_new_handler(my_new_handle);
    p = new int[100*1024*1024]{};
    int *h = nullptr;
    for(int i=0;i<20;++i){
        h = new int[50*1024*1024]{};
    }
    return 0;
}

void my_new_handle(){
    cout << "use my defined new_handler" << endl;
    if(p){
        cout <<"try to get more memory" <<endl;
        delete [] p;
        return;
    }
    throw std::bad_alloc();
}
