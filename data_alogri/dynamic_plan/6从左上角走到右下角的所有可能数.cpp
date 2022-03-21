//---------------------------------
//File Name    : 6从左上角走到右下角的所有可能数.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-21 14:10:10
//Description  : 
//----------------------------------
//@Summary: 采用递归的思想去分析问题
//          则Dp状态方程就是Sum(i,j) = Sum(i,j+1) + Sum(i+1,j)
//@answer: 采用动态规划的方式编写，复杂度为O(m*n)

#include <iostream>
using std::cout;
using std::endl;

//@Situation1: 网格中存在石头，其值为-1,表示禁止通行的意思
int Sum1(int **arr,const int &m,const int &n){
    //先计算出下边界和右边界的值
    arr[m][n] = 1;
    for(int i=n-1;i>=0;--i)
        arr[m][i] = (arr[m][i]!=-1)?arr[m][i+1]:0;
    for(int i=m-1;i>=0;--i)
        arr[i][n] = (arr[i][n]!=-1)?arr[i+1][n]:0;
    //依次递推计算
    for(int i=m-1;i>=0;--i){
        for(int j=n-1;j>=0;--j){
            //@answer: 如果不是障碍物，则为下右相加，否则，为0
             arr[i][j] = (arr[i][j]!=-1)?(arr[i+1][j]+arr[i][j+1]):0;
        }
    }
    return arr[0][0];
}

//@Situation2: 网格中不存在石头 (递归解法)
int Sum2(int **arr,const int &m,const int &n){
    if(m>=0 && n>=0){
        if(m==0 || n==0)
            return 1;
        return Sum2(arr,m-1,n) + Sum2(arr ,m,n-1);
    }
    return 0;
}

//@Situation3: 网格中不存在石头 (动态规划解法)
int Sum3(int **arr,const int &m,const int &n){
    //先初始化网格的下边界和有边界
    arr[m][n] = 1;
    for(int i=n-1;i>=0;--i)
        arr[m][i] = 1;
    for(int i=m-1;i>=0;--i)
        arr[i][n] = 1;
    for(int i=m-1;i>=0;--i)
        for(int j=n-1;j>=0;--j)
            arr[i][j] = arr[i+1][j] + arr[i][j+1];
    return arr[0][0];
}

int main(){
    //@Test: Situation1
    //新建一个二维数组
    int **p = new int*[4];
    for(int i=0;i<4;++i)
        p[i] = new int[5]{};
    //初始化障碍
    p[1][1] = -1;
    p[1][3] = -1;
    p[3][2] = -1;
    p[0][2] = -1;
    p[3][0] = -1;
    //执行
    cout << Sum1(p,3,4) << endl;

    //@Test: Situation2 Situation3
    int **p2 = new int*[4];
    for(int i=0;i<4;++i)
        p2[i] = new int[5]{};
    cout << Sum2(p2,3,4) << endl;
    cout << Sum3(p2,3,4) << endl;

    //delete

    return 0;
}
