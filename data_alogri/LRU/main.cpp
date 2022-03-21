//---------------------------------
//File Name    : 1LRU.cpp
//Author       : aico
//Mail         : 2237616014@qq.com
//Github       : https://github.com/TBBtianbaoboy
//Site         : https://www.lengyangyu520.cn
//Create Time  : 2022-03-11 18:24:07
//Description  : 缓存页面淘汰算法(最近最少使用)，使用map/list来实现
//----------------------------------
#include <map>
#include <iostream>
#include <type_traits>
#include <utility>

using std::map;
using std::cout;
using std::endl;
using std::string;

struct ListNode {
    int key;
    string value;
    ListNode* pre;
    ListNode* next;
    ListNode(const int &k,const string &v):key(k),value(v),pre(nullptr),next(nullptr){}
};

class List {
    private:
        ListNode head;
        ListNode *tail;
        int size;
    public:
        List():head(0,""),tail(nullptr),size(0){}
        ~List(){
            ListNode* pointer = head.next;
            for(;!pointer;pointer = pointer->next)
                delete pointer;
            cout << "-------" << endl;
        }

        void print()const{
            ListNode* pointer = head.next;
            for(;pointer;pointer=pointer->next){
                cout << pointer->value << endl;
            }
        }

        void MoveToHead(ListNode* pointer){
            //空双链表
            if(!head.next)
                return;
            //尾结点
            if(pointer->next == nullptr && pointer->pre != nullptr){
                tail = pointer->pre;
                pointer->pre->next = nullptr;
                pointer->pre = nullptr;
                pointer->next = head.next;
                pointer->next->pre = pointer;
                head.next = pointer;
            }else if(pointer->pre == nullptr){
            }else{
                pointer->pre->next = pointer->next;
                pointer->next->pre = pointer->pre;
                pointer->pre = nullptr;
                pointer->next = head.next;
                head.next->pre = pointer;
                head.next = pointer;
            }
        }

        void InsertHead(ListNode* pointer){
            if(head.next == nullptr){
                head.next = pointer;
                tail = pointer;
                return;
            }
            pointer->next = head.next;
            head.next->pre = pointer;
            head.next = pointer;
        }

        int DeleteTail(){
            tail->pre->next = nullptr;
            ListNode* tmp = tail;
            int key = tail->key;
            tail = tmp->pre;
            delete tmp;
            --size;
            return key;
        }

        int GetSize()const {
            return size;
        }

        void SetSize(bool Is){
            if(Is){
                ++size;
                return;
            }
            --size;
        }

};

class Lru final {
    private:
        map<int,ListNode*> map_m;
        List list;
        int cap;
    public:
        Lru(const int &c = 6);
        ~Lru();
        string getCache(const int&);
        void setCache(const int&,const string&);
        void print()const;
};

Lru::Lru(const int &c):cap(c){}

Lru::~Lru(){
    map_m.erase(map_m.begin(),map_m.end());
}

string Lru::getCache(const int& key){
    auto iter = map_m.find(key);
    if(iter != map_m.end()){
        ListNode *pointer = iter->second;
        list.MoveToHead(pointer);
        return pointer->value;
    }
    return "";
}

void Lru::setCache(const int& key,const string& value){
    auto iter = map_m.find(key);
    ListNode *pointer = nullptr;
    //数据存在，更新数据
    if(iter != map_m.end()){
        pointer = iter->second;
        pointer->value = value;
        list.MoveToHead(pointer);
        return;
    }
    //数据不存在，插入到头部
    list.SetSize(true); //更新现有量
    pointer = new ListNode(key,value);
    list.InsertHead(pointer);
    map_m[key] = pointer;
    //如果超出容量，则删除尾结点
    if(list.GetSize()>cap){
        int k_d = list.DeleteTail();
        map_m.erase(k_d);
    }
}

void Lru::print()const{
    list.print();
}

int main(){
    Lru lru_cache(6);
    lru_cache.setCache(1,"a");
    lru_cache.setCache(2,"b");
    lru_cache.setCache(3,"c");
    lru_cache.setCache(4,"d");
    lru_cache.setCache(5,"e");
    lru_cache.setCache(6,"f");
    // lru_cache.setCache(6,"f");
    // lru_cache.setCache(3,"c");
    // lru_cache.setCache(7,"g");
    // lru_cache.setCache(8,"h");
    // lru_cache.setCache(5,"e");
    // lru_cache.setCache(9,"i");
    lru_cache.print();
    return 0;
}


