//---------------------------------
//File Name    : 1.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-20 20:38:29
//Description  : 
//----------------------------------
#include <iostream>
#include <vector>
#include <memory>

using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> getAll(vector<int> &a){
    //@answer: 创建返回值
    std::shared_ptr<vector<vector<int>>> target(new vector<vector<int>>);
    //@answer: 处理特殊情况
    if(a.size()==0)
        return *target;
    //@answer: 计算所有可能的情况
    unsigned int count = 1 << a.size();
    for(int i=0;i<count;++i){
        //@answer: 创建新增对象
        vector<int> add_object;
        for(int j=0;j<a.size();++j){
            //@answer: 核心代码就一段,通过位运算进行处理
            unsigned int tmp = (1 << j) & i;

            if(tmp != 0)
                add_object.push_back(a[j]);
        }
        target->push_back(add_object);
    }
    return *target;
}

int main(){
    vector<int> arr{1,2,3};
    auto result = getAll(arr);
    for (const auto &x :result) {
        for(const auto &y : x){
            cout << y << " ";
        }
        cout << endl;
    }

    return 0;
}
