//@desc 使用强制转换判断大小端

#include <iostream>
#include <dbg.h>

bool checkP(){
    const int &int_m = 0x1234;
    if (char(int_m)==0x34){
        dbg("small");
        return false;
    }
    dbg("big");
    return true;
}

int main(){
    checkP();
    return 0;
}
