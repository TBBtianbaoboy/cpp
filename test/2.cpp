//@desc 探讨与结构体字节对齐的两种方式

#include <cstdint>
#include <iostream>
#include <dbg.h>

struct struct_m1 {
    uint8_t a;
    uint16_t b;
    uint8_t c;
};

//@desc 如何alignas小于自然对齐的最小单位，则会被自动忽略
struct alignas(4) struct_m2 { //@desc set align type keyword is alignas 
    uint8_t a;
    uint16_t b;
    uint8_t c;
};
int main(){
    dbg(sizeof(struct_m1),alignof(struct_m1)); //@desc get align type keyword is alignof
    dbg(sizeof(struct_m2),alignof(struct_m2));
    return 0;
}
