#include "hashTable.h"
#include <cstdlib>
#include <iostream>

using std::endl;
using std::cout;
int main()
{
    HashTable<unsigned int,int> hs; 
    int a,b,c;
    for(int i=0;i<20;++i) 
    {
       int flag = rand();
       if (i==3)
           a = flag;
       else if(i==12)
           b = flag;
       else if(i==18)
           c = flag;
       cout << flag <<" "; 
       hs.insertValue(flag);
    }
    cout <<endl;
    if(hs.deleteValue(a))
        cout<<a <<"delete success"<<endl;
    else
     cout<<a<<"delete fail"<<endl;
    if(hs.searchValue(b))
        cout<<b<<"search success"<<endl;
    else
     cout<<b<<"delete fail"<<endl;
    return 0;
}
