#include <iostream>
#include <cstring>
#include <dbg.h>

int main(){
    const char *p = "abc\0ef";
    //@desc sizeof is keyword ,strlen is lib function
    //@desc sizeof 在编译期就可以获得，strlen 在运行期才能获得
    dbg(sizeof(p),strlen(p));

    char *char_array_m = new char[10]{'a'};

    dbg(sizeof(char_array_m),strlen(char_array_m),char_array_m[2]);

    //@desc sizeof 作用于数组名的时候，可以获取数组的长度
    char a[10]{'a','b'};
    dbg(sizeof(a),strlen(a));
    return 0;
}
