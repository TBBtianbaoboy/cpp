#include <stdio.h>
#include <stdint.h>

//@desc extern 同 c++ ，别处定义也可以使用
extern uint32_t var;

int main(){
    printf("%d\n",var);
    return 0;
}
