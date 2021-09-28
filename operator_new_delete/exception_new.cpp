//------------------这是关于new分配空间出错的解决方案--------------------------------
//new 出错最好使用set_new_handler函数解决问题
#include <iostream>
#include <new>

using std::set_new_handler;
using std::cout;
using std::endl;

void my_new_handler();

int *pool = nullptr;

int main()
{
   set_new_handler(&my_new_handler); 
   pool = new int[75*1024*1024]{};
   if(pool){
       cout<<"preserve 101M at ----"<<pool<<endl;
   }
   cout<<std::get_new_handler()<<endl;

   int *p = nullptr;
   for(int i=0;i<20;i++){
       p = new int[75*1024*1024]{};
       cout<<i+1<<" * 100M,p = "<<p<<endl;
   }
   cout <<"Done!"<<endl;
   return 0;
}

void my_new_handler()
{
    if(pool){
        cout<<"try to get more memory"<<endl;
        delete [] pool;
        pool = nullptr;
        return;
    }else{
        cout << "I can not help you!"<<endl;
        throw std::bad_alloc();
    }
    return;
}
