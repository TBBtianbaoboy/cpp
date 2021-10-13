#include <cstdint>
#include <dbg.h>

struct cpp_struct {
    //@desc c++ 结构体中的数据成员默认为 public，可以添加限定符来使之成为 private 或 protected
    private:
        uint32_t a;
        char32_t b;
    public:
    //@desc 其他的与 c++ 中的类没有区别
        cpp_struct():a(1),b(2){}
        ~cpp_struct(){}
        //这两个会作用到当前类及其子类，表示不生成默认的拷贝构造函数和拷贝函数
        cpp_struct(const cpp_struct&)=delete;
        cpp_struct& operator=(const cpp_struct&)=delete;
        uint32_t getA()const{
            return a;
        }
        char32_t getB()const{
            return b;
        }
};

//@desc c++ struct 的继承方式默认为 public
//@compare c++ class 的继承方式默认为 private
struct cpp_struct_son : cpp_struct {
    private:
        int c;
    public:
        cpp_struct_son():c(0){}
        int getC()const{
            return c;
        }
};

int main(){
    //@desc 结构体的名字可以直接作为数据类型，不需要使用 typedef 
    cpp_struct t1;

    //@desc 不使用 private 限定数据成员的话在外部就可以访问到
    // dbg(t1.a,t1.b);

    dbg(t1.getA(),t1.getB());

    cpp_struct_son t2;
    dbg(t2.getA(),t2.getB(),t2.getC());

    return 0;
}
