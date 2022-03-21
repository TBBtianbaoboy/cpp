//---------------------------------
//File Name    : 2判断哪个数是奇数个.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-14 13:53:02
//Description  : 
//----------------------------------
#include <vector>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
//@Annotation: ^位运算比+-*/都要快

//@Desc: 如果只存在一个数为奇数，其他数为偶数
//@Annotation: 计算机中的^ 满足交换率和结合律，即0^N==N N^N==0 a^b^c^d^e...^n 中的字母可以随意交换位置
auto once_number(const vector<int> &arr){
    int number = 0;
    for(const auto &x : arr)
        //@CoreCode: 将所有数^即可解决
        number ^= x;
    return number;
}

//@Desc: 如果存在两个数为奇数，其他数为偶数
void two_number(const vector<int> &arr){
    int eor = 0;
    for(const auto &x : arr)
        eor ^= x;
    int tmp = eor & (~eor + 1);
    int eor2 = 0;
    for(const auto &x : arr)
        if((tmp&x)==0)
            eor2 ^= x;
    cout << eor2 << " " << (eor ^ eor2) << endl;

}

int main(){
    vector<int> arr{3,2,4,1,6,3,4,1,2,6,2,6,7,8,7,8};
    // cout << once_number(arr) << endl;
    two_number(arr);

    return 0;
}

