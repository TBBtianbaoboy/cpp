#include <stdint.h>

//@tip c 中的 struct 是用户数据类型UDT，只能用来封装数据,并不能隐藏数据
//@desc c 中的结构体如果要作为类型的话，1 是使用 typedef ,2 是 使用 struct struct_name
typedef struct c_struct {
    int16_t a;
    char b;
    //@desc c 的结构体中没有限定符号，统一为 public
    /* private: */
    /* public: */
    /* protected: */

    //@desc c 的结构体中不能有函数声明定义
    /* c_struct():a(0),b(0){} */
}c_struct;

struct c_struct2 {
    int16_t a;
    char b;
};

int main(){
    c_struct a;
    struct c_struct b;
    return 0;
}
