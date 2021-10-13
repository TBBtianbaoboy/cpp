#include <cstdint>
#include <dbg.h>

//@desc 这是声明，声明定义在其他源文件中，可以有多处声明
extern std::uint32_t var;

int main(){
    dbg(var);
    return 0;
}
