//@desc 汇总所有构造函数

#include <dbg.h>
#include <utility>

class Array {
    private:
        int *arr;
        int size;

    public:
        //@desc 初始化构造函数&默认构造函数
        Array(const int& s=10):arr(nullptr),size(s){
            arr = new int[size]{};
        }

        //@desc 拷贝构造函数
        Array(const Array& a){
            size = a.size;
            arr = new int[size]{};
            for(int i=0;i<size;++i){
                arr[i] = a.arr[i];
            }
        }

        //@desc 移动构造函数，也就是只有一个参数，和初始化构造函数&默认构造函数没什么区别

        //@desc 委托构造函数，则是在参数列表中调用其他的构造函数，但是要注意，避免形成死循环

        //@desc 移动构造函数
        //@other 右值引用用 && 表示，指向右值，而不是左值，而且，右值引用本身是左值
        Array(Array&& a){
            size = a.size;
            arr = a.arr;
            a.arr = nullptr;
        }

        ~Array(){
            if(arr) delete [] arr;
        }

        //@desc 拷贝运算符函数
        Array& operator=(const Array& a){
            delete [] arr;
            size = a.size;
            arr = new int[size]{};
            for(int i=0;i<size;++i){
                arr[i] = a.arr[i];
            }
            return *this;
        }

        //@desc []运算符重载
        int& operator[](const int& index){
            if(index>=0 && index<=size-1){
                return arr[index];
            }
            return arr[size-1];
        }

        //@desc 以下皆为成员函数
        int getSize()const {
            return size;
        }

        void getArr()const{
            if(arr){
                for(int i=0;i<size;i++){
                    dbg(arr[i]);
                }
            }
        }
};

int main(){
    //@desc 测试初始化构造函数&默认构造函数
    Array a;
    for(int i=0;i<10;++i){
        a[i] = i;
    }
    a.getArr();

    //@desc 测试 operator=
    Array b;
    b = a;
    b.getArr();
    a.getArr();
    
    //@desc 测试拷贝构造函数
    Array c = b;
    c.getArr();

    //@desc 测试移动构造函数
    Array d = std::move(c);
    dbg("here is move constructor");
    d.getArr();
    c.getArr();

    //
    return 0;
}
