//@desc 定义用来存放数据的结点

template<typename KEY,typename VALUE>
class LinkNode {
    private:
        LinkNode<KEY,VALUE> *pNext; //指向下一个结点
        KEY key; //哈希键
        VALUE value; //值

    public:
        LinkNode(KEY& k,VALUE& v);
        ~LinkNode();
        void setNextNode(LinkNode<KEY,VALUE>* next); //设置下一个结点
        LinkNode<KEY,VALUE>* getNext(); //获取下一个结点
        KEY& getKey() const; //获取哈希键
        VALUE& getValue() const; //获取值
};
//@desc 实现
template<typename KEY,typename VALUE>
LinkNode<KEY,VALUE>::LinkNode(KEY& k,VALUE& v):pNext(nullptr){
    key = k;
    value = v;
}

template<typename KEY,typename VALUE>
LinkNode<KEY,VALUE>::~LinkNode(){}

template<typename KEY,typename VALUE>
void LinkNode<KEY,VALUE>::setNextNode(LinkNode<KEY, VALUE>* next){
    this->pNext = next;
}

template<typename KEY,typename VALUE>
LinkNode<KEY,VALUE>* LinkNode<KEY,VALUE>::getNext(){
    return pNext;
}

template<typename KEY,typename VALUE>
KEY& LinkNode<KEY,VALUE>::getKey()const {
    return key;
}

template<typename KEY,typename VALUE>
VALUE& LinkNode<KEY,VALUE>::getValue()const {
    return value;
}
