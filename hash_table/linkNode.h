// 定义用来存放数据的结点

template<typename KEY,typename VALUE>
class LinkNode {
    private:
        LinkNode<KEY,VALUE> *pPrev; //指向上一个结点
        LinkNode<KEY,VALUE> *pNext; //指向下一个结点
        KEY key; //哈希键
        VALUE value; //值

    public:
        LinkNode(KEY& k,VALUE& v);
        ~LinkNode();
        void setNextNode(LinkNode<KEY,VALUE>* next); //设置下一个结点
        LinkNode<KEY,VALUE>* getNext(); //获取下一个结点
        void setPrevNode(LinkNode<KEY,VALUE>* prev); //设置上一个结点
        LinkNode<KEY,VALUE>* getPrev(); //获取上一个结点
        KEY& getKey() const; //获取哈希键
        VALUE& getValue() const; //获取值
};
