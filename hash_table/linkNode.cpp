#include "linkNode.h"

template<typename KEY,typename VALUE>
LinkNode<KEY,VALUE>::LinkNode(KEY& k,VALUE& v):pNext(nullptr),pPrev(nullptr){
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
void LinkNode<KEY,VALUE>::setPrevNode(LinkNode<KEY, VALUE> *prev){
    this->pPrev = prev;
}

template<typename KEY,typename VALUE>
LinkNode<KEY,VALUE>* LinkNode<KEY,VALUE>::getPrev(){
    return pPrev;
}

template<typename KEY,typename VALUE>
KEY& LinkNode<KEY,VALUE>::getKey()const {
    return key;
}

template<typename KEY,typename VALUE>
VALUE& LinkNode<KEY,VALUE>::getValue()const {
    return value;
}
