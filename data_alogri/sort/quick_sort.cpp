#include<iostream>

using std::cout;
using std::endl;

class ToolKits{
    public:
        static void quick_sort(int*,int);
};

void ToolKits::quick_sort(int *target,int length){
   if(length>0){
       int l = 0,r = length - 1;
       int flag = target[0];
       while(r>l){
           while(r>l && target[r]>=flag)
               --r;
           if(r>l)
               target[l++] = target[r];
           while(r>l && target[l]<=flag)
               ++l;
           if(r>l)
               target[r--] = target[l];
       }
       target[l] = flag;
       quick_sort(target,l);
       quick_sort(target+l+1,length-l-1);
   } 
}

int main(){
    int a[] = {3,4,1,5,2,8,0,7,-1};
    ToolKits::quick_sort(a,9);
    for(int i=0;i<9;++i)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
