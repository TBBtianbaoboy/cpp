#include <cstdint>
#include <dbg.h>

//@usage typedef type name; @desc 用于定义类型别名 @compare 与宏定义相比，宏主要用来定义常量以及书写复杂的内容...
//@compare 宏替换发生在预处理阶段，typedef 发生在编译期
//@compare 宏不会进行类型检查，typedef 会进行类型检查
//@compare 宏不是语句，末尾不加 ; ，typedef 是语句，末尾要加分号

//@suggestion 不要使用宏来定义类型别名，一定使用 typedef 

#define CHAR_P char*

typedef struct Te {
    uint8_t size;
    uint16_t length;
    Te():size(96),length(1){}
}Te;

int main(){
    //@desc use typedef successfully
    typedef std::int32_t * char_m;
    char_m a{},b{};
    dbg(a,b);

    //@desc use define failed
    CHAR_P c{},d{};
    dbg(c,d); //d is not nullptr

    Te test_m;
    dbg(test_m.length,test_m.size);
    return 0;
}
