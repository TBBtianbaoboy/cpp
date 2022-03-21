//---------------------------------
//File Name    : 5斐波那锲数列.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-21 11:52:27
//Description  : 
//----------------------------------
#include <iostream>
using std::cout;
using std::endl;

void print(const int &value){
    cout << value << endl;
}
//@Summary: 斐波那锲数列的Dp方程是: F(n) = F(n-1) + F(n-2)，这就是回朔和Dp的核心

//@answer: 递归求解 -- 时间复杂度为O(2^n)，空间复杂度为O(1)
int recision(const int &n){
    if(n<=0) return 0;
    return n<=2?n:(recision(n-1)+recision(n-2));
}

//@answer: Dp求解 -- 时间复杂度为O(n)，如果采用数组的话，空间复杂度为O(n),如果采用三个变量的方式，则空间复杂度为O(1)
int dp(const int &n){
    if(n<0) return 0;
    int *container = new int[n+1];
    container[0] = 1;
    container[1] = 1;
    int i;
    for(i=2;i<n+1;++i)
        container[i] = container[i-1] + container[i-2];
    i = container[n];
    delete [] container;
    return i;
}

int main(){
    print(recision(-1));
    print(recision(0));
    print(recision(1));
    print(recision(2));
    print(recision(3));
    print(recision(4));
    cout <<"-------------" << endl;
    print(dp(-1));
    print(dp(0));
    print(dp(1));
    print(dp(2));
    print(dp(3));
    print(dp(4));
    return 0;
}
