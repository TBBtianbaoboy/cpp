//---------------------------------
//File Name    : 8三角形的最小路径和.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-21 16:50:06
//Description  : 
//----------------------------------
//@Desc: 从二维数组三角形的顶点到最下面一层的最小路径和
//@Analyse: 使用回朔(递归)进行分析，Min(i,j) = Tri(i,j) + min(Min(i+1,j),Min(i+1,j+1))
//@Define: 根据分析，我们需要从下往上进行递推，这时需要一个vector来记录每一层的Min()

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int min(const int &a,const int&b){
    return (a>b?b:a);
}

int getMax(vector<vector<int>> &arr){
    //@answer: 记录下最底层的所有值当做最小值
    vector<int> Min = arr[arr.size()-1];

    for(int i=arr.size()-2;i>=0;--i){
        for(int j=0;j<arr[i].size();++j){
            //@answer: 这就是状态压缩
            Min[j] = arr[i][j] + min(Min[j],Min[j+1]);
        }
    }
    return Min[0];
}

int main(){
    vector<vector<int>> arr{{2},{3,2},{6,5,4},{4,1,100,102}};
    cout << getMax(arr) << endl;
    return 0;
}
