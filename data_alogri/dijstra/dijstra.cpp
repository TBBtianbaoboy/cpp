#include <iostream>
#include <climits>
#include <dbg.h>
#include <vector>

#define MAX_PRICE INT_MAX

class Dijstra {
    private:
        std::vector<std::vector<int>> path_m;    //路径数据
        int src_m;    //出发点
        int dest_m;    //终点
        // int limit_m;    //可选字段，用来限制中间路径

    public:
        Dijstra(){}
        Dijstra(const Dijstra&)=delete; 
        ~Dijstra(){}
        Dijstra& operator=(const Dijstra&)=delete;
        int get_price()const;
        int get_src()const;
        int get_dest()const;
};

int Dijstra::get_src()const{
    return src_m;
}
int main(){
    Dijstra a;
    dbg(a.get_src());
    return 0;
}
