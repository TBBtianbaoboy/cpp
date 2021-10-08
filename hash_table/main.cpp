#include "hashTable.h"
#include <cstdlib>
#include <iostream>

using std::endl;
using std::cout;
int main()
{
    HashTable<unsigned int,int> hs; 
    cout << "bucket : " << hs.getBucketNum() << endl;
    cout << "size : " << hs.getSize() << endl;
    hs.insertValue(3);
    // for(int i=0;i<20;++i) 
    //     hs.insertValue(i);

    // hs.printHash();
    // if(hs.deleteValue(3))
    //     cout<<"3 delete success"<<endl;
    // else
    //  cout<<"3 delete fail"<<endl;
    // if(hs.searchValue(10))
    //     cout<<"10 search success"<<endl;
    // else
    //  cout<<"10 delete fail"<<endl;
    return 0;
}
