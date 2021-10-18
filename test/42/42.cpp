//@desc 有关异常相关的 all

#include <dbg.h>
#include <exception>

//@desc exception bad_typeid
class bad_typeid_test {
    virtual void print()throw(){}  
};

void test_bad_typeid(const bad_typeid_test* obj){
    dbg(obj);
    try{
        //@con private constructor，type_info 类就是一个单例类
        auto &obj_type_info = typeid(*obj); //@desc 多态类对象指针作为typeid 参数最棒，可以检测异常
        dbg(obj_type_info.hash_code(),obj_type_info.name());
    }catch(std::exception &e){
        dbg(e.what());
    }
}

//@desc exception bad_cast
class basic_class {
    public:
        virtual ~basic_class(){}
        virtual void print()=0;
};

class derived_class final:public basic_class{
    public:
        virtual ~derived_class(){}
        virtual void print()override{
            dbg("this is derived class");
        }
        void derived_unique(){
            dbg("derived class unique");
        }
};

//@desc exception bad_alloc,bad_array_new_length
void test_bad_alloc(){
    try{
        int *a = new int[1024*1024*1024*2]{};
    }catch(std::exception &e){
        dbg(e.what());
    }
}
int main(){
    //@desc exception bad_typeid
    bad_typeid_test a;
    test_bad_typeid(nullptr);
   
    //@desc exception bad_cast
    basic_class *bc = new derived_class();
    bc->print();
    try{
        dynamic_cast<derived_class*>(bc)->derived_unique();
    }catch(std::exception& e){
        dbg(e.what());
    }

    //@desc exception bad_alloc
    test_bad_alloc();

    return 0;
}
