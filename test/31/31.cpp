#include <dbg.h>

int main(){
    //@desc 指针 p 未被初始化，就是野指针，会乱指，后续使用会出错,应该置 nullptr
    int *p{};
    dbg(p);
    if(p){
        dbg(*p);
    }

    int *p2 = new int{2};
    //@desc delete 指针 p2 后，p2 还是指针原来的地址，这就是悬空指针，所以 delete 之后要将指针 p2 置 nullptr
    delete p2;
    //@do
    p2 = nullptr;
    dbg(p2);
    if(p2){
        dbg(*p2);
    }
    return 0;
}
