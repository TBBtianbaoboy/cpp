//---------------------------------
//File Name    : 2根据指定字符切割字符串.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-09 15:39:08
//Description  : 
//----------------------------------
#include <iostream>
#include <sstream>
#include <string>

using std::istringstream;
using std::string;
using std::cout;
using std::endl;

void splitString(const char *s){
    istringstream obj(s);
    string out;

    while(obj.good()){
        //@Annotation: 根据指定字符切割流式字符串到string中
        std::getline(obj,out,'x');
        if(!out.empty()){
            cout << out << endl;
        }
    }

    //@Annotation: 大神用法，整不会了
    // while(obj >> out) {
    //     cout << out << endl;
    // }
}

int main(){
    splitString("xx123x456x789xxxx0xx");
    return 0;
}
