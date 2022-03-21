//---------------------------------
//File Name    : 4求最长不含重复字符的子字符串.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-17 18:27:56
//Description  : 
//----------------------------------
//@Summary 完全符合动态规划的4大特点
//@Desc: 字符串中只包含a-z，求长度

#include <iostream>
using std::cout;
using std::endl;
using std::string;

int getMax(const string &str){
     int curLength = 0;
     int maxLength = 0;

     //@answer: 用来存放对应字母在字符串中的位置
     int *pos = new int[26];
     for(int i=0;i<26;++i)
         pos[i] = -1;

     //@answer: 只需要O(n)的时间和空间复杂度
     for(int i=0;i<str.length();++i){
         if()

     }

}
