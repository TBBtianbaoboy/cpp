//位运算思想
//如何判断一个数是 2 的幂次

// 复杂切低效的思路
#include<iostream>
#define HIGHWAY

int main(){
    int num{};
    std::cin>>num;
// #ifdef LOWWAY
//     int length = sizeof(int);
//     if((num&1)==1)
//     {
//         std::cout<<"not"<<std::endl;
//         return 0;
//     }
//     for(int i=0,flag=0;i<(length<<3);++i){
//         num >>= 1;
//         if((num&1)==1)
//             flag++;
//         if(flag>1)
//         {
//             std::cout<<"not"<<std::endl;
//             return 0;
//         }
//     }
//     std::cout<<"yes"<<std::endl;
// #endif //LOWWAY

#ifdef HIGHWAY
    if((num&(~num+1))==num)
        std::cout<<"yes"<<std::endl;
    else
        std::cout<<"not"<<std::endl;
#endif //HIGHWAY
    return 0;
}

