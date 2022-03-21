//---------------------------------
//File Name    : 7爬楼梯.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-21 15:47:51
//Description  : 
//----------------------------------
//@Desc: 每次可以选择爬1层或两层，求爬到n层一共有多少种可能
//@Summary: Dp状态方程是f(n) = f(n-1) + f(n-2)，就是斐波那锲数列呀

//@answer: 这次采用时间复杂度为O(n)，空件复杂度为O(1)的动态规划方式来求解
//         刚好补充本章第5节的内容
//         @Summary:
//                  Dp vs 回朔 vs贪心
//                  回朔: 递归（重复计算）
//                  贪心: 永远局部最优
//                  Dp: 记录局部最优子结构/多种记录值
#include <iostream>
using std::endl;
using std::cout;

int Sum(const int &n){
    if(n<0) return 0;
    if(n<=2) return n;

    int one_step = 1;
    int two_step = 2;
    int all_step = 0;
    for(int i=2;i<n;++i){
        all_step = one_step + two_step;
        one_step = two_step;
        two_step = all_step;
    }
    return all_step;
}

int main(){
    cout << Sum(-1) << endl;
    cout << Sum(0) << endl;
    cout << Sum(1) << endl;
    cout << Sum(2) << endl;
    cout << Sum(3) << endl;
    return 0;
}
