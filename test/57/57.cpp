#include <cstdlib>
#include <iostream>

void malloc_test(){
    //@desc malloc 申请的空间的值本应该是随机初始化的，但这里却会初始化为0
    void* p = malloc(sizeof(int)*4);
    for(int i=0;i<4;++i){
        ((int*)p)[i] = i;
        std::cout << ((int*)p)[i] << " ";
    }
    std::cout << std::endl;
    //@desc calloc 申请的空间会初始化为 0 
    void* q = calloc(6,sizeof(int));
    for(int i=0;i<6;++i){
        std::cout << ((int*)q)[i] << " ";
    }
    std::cout << std::endl;
    free(q);
    //@desc
    void *t = realloc(p,sizeof(int)*6);
    for(int i=0;i<6;++i){
        std::cout << ((int*)t)[i] << " ";
    }
    std::cout << std::endl;
    free(t);
}

int main(){
    malloc_test();
    return 0;
}
