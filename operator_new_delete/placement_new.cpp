//placement new可以很高效地用于内存池的管理，将所要分配的空间分配在已经申请的堆上
//另外，placement new也可以将所申请的空间转向到memory stack上
#include <iostream>

using std::cout;
using std::endl;

int main(int argc,char*argv[]){
    char c[100]{};
    int *p = reinterpret_cast<int*>(c);

    int* a = new(p) int[10]{};
    cout <<a<<" "<<p<<endl;
    return 0;
}
