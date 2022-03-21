//@Summary: 动态规划问题有四个特点:
//          1: 求这个问题的最优解
//          2: 大问题的最优解是依赖各个子问题的最优解
//          3: 大问题可以分解成若干个小问题，小问题之间还有相互重叠的更小的子问题
//          4: 从上往下分析问题，从下往上求解问题，即先计算小问题的最优解并存储下来，再以此为基础求解大问题的最优解
//
#include <iostream>
using std::cout;
using std::endl;

int maxX(int length){
    //@answer: 先处理特殊情况
    if(length<2) return 0;
    if(length==2) return 1;
    if(length==3) return 2;

    //@answer: 在length>=4时，0-3中存储的是对应的max，做为子问题的最优解的基础
    int *products = new int[length+1];
    for(int i=0;i<4;++i)
        products[i] = i;

    int max = 0;
    //@answer: 最外一层循环用来求解每个子问题的最优解
    for(int i=4;i<=length;++i){
        max = 0;
        //@answer: 将j控制在i>>1可以避免重复的计算
        for(int j=1;j<=(i>>1);++j){
            int product = products[j]*products[i-j];
            if(max<product)
                max = product;
        }
        products[i] = max;
    }

    //@answer: 记录大问题的最优解，删除堆空间，然后返回最优解
    max = products[length];
    delete [] products;
    return max;
}

int main(){
    cout << maxX(0) << endl;
    cout << maxX(1) << endl;
    cout << maxX(2) << endl;
    cout << maxX(3) << endl;
    cout << maxX(4) << endl;
    cout << maxX(5) << endl;
    cout << maxX(6) << endl;
    cout << maxX(10) << endl;
    cout << maxX(9) << endl;
    return 0;
}
