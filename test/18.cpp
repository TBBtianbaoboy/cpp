//@desc discuss the difference between a and &a of array
#include <dbg.h>

int main(){
    int a[10]{1,2,3,4,5,6,7,8,9,10};
    typedef int (*array_ptr)[10];
    array_ptr p = &a;
    dbg(p);

    dbg(a,*a,*(a+1));
    dbg(**p,*(*p+1));

    //@desc err operation way
    // dbg(**(p+2)); //@err 读取了其他的内存地址，隐藏 bug 

    return 0;
}
