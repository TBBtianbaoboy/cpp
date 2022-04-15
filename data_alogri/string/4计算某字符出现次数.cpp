//写出一个程序，接受一个由字母、数字和空格组成的字符串，和一个字符，然后输出输入字符串中该字符的出现次数。（不区分大小写字母）
//数据范围: 1≤n≤1000
#include<iostream>
using std::cout;
using std::string;
using std::cin;
using std::endl;

int main(){
    string s;
    char c;
    int n = 0;
    //@answer: get input data until meet '\n'
    std::getline(cin,s) >> c;
    for(auto &i : s){
        if(std::tolower(i)==c)
            ++n;
    }
    cout << n << endl;
}
