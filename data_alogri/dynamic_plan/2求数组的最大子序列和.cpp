//---------------------------------
//File Name    : 1求数组的最大子序列和.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-13 23:20:10
//Description  : 
//----------------------------------
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;

auto max(const int &v1,const int &v2){
    return v1>v2?v1:v2;
}

//@Annotation: 采用动态规划的方式来进行求解
int sum(const vector<int> &arr){
    if(arr.empty())
        return 0;
    int pre = 0,maxNums = arr[0];

    //@Annotation: 核心算法
    for (const auto &x : arr) {
        pre = max(pre+x,x);
        maxNums = max(maxNums,pre);
    }

    return maxNums;
}

int main(){
    vector<int> a{-2,1,-3,4,-1,2,1,-5,4};
    cout << sum(a) << endl;
}


