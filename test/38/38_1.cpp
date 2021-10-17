#include <dbg.h>

typedef union check_union {
    int int_m;
    char char_m;
}check_union;

bool checkP(){
    check_union a;
    a.int_m = 0x1234;
    dbg(a.char_m);
    if(a.char_m==0x34){
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
