//@desc 定义哈希表

#include "linkNode.h"
#include <cstring>

template<typename KEY,typename VALUE>
class HashTable{
    private:
        typedef LinkNode<KEY,VALUE>* ptrLinkNode;
        ptrLinkNode* hashArray;
        unsigned int cap;
        unsigned int size; 
    public:
        HashTable(int cap_init=10);
        ~HashTable();
        bool insertValue(const VALUE& value);
        bool deleteValue(const VALUE& value);
        bool searchValue(const VALUE& value) const;
    private:
        KEY hashFunc(const VALUE& value) const;
};

template <typename KEY, typename VALUE>
HashTable<KEY, VALUE>::HashTable(int cap_init)
    : size(0), cap(cap_init), hashArray(nullptr) {
  hashArray = new ptrLinkNode[cap];
  for (int i = 0; i < 10; i++) {
    hashArray[i] = nullptr;
  }
}

template <typename KEY, typename VALUE> HashTable<KEY, VALUE>::~HashTable() {
  for (int i = 0; i < cap; ++i) {
    ptrLinkNode pointer = hashArray[i];
    while (pointer) {
      ptrLinkNode pointer2 = pointer->getNext();
      delete pointer;
      pointer = pointer2;
    }
  }
  delete[] hashArray;
}

//@desc
//向哈希表中插入数据-----------------------------------------------------未考虑异常情况，只实现基本功能
template <typename KEY, typename VALUE>
bool HashTable<KEY, VALUE>::insertValue(const VALUE &value) {
  VALUE a = value;
  KEY bucket_num = hashFunc(value);
  ptrLinkNode pointer = hashArray[bucket_num];
  ptrLinkNode newNode = new LinkNode<KEY, VALUE>(bucket_num, a);
  ptrLinkNode tmp = pointer;
  pointer = newNode;
  if (tmp == nullptr) {
    pointer->setPrevNode(nullptr);
    pointer->setNextNode(nullptr);
  } else {
    tmp->setPrevNode(pointer);
    pointer->setNextNode(tmp);
    pointer->setPrevNode(nullptr);
  }
  ++size;
  return true;
}

//@desc 从哈希表中删除数据
template <typename KEY, typename VALUE>
bool HashTable<KEY, VALUE>::deleteValue(const VALUE &value) {
  KEY bucket_num = hashFunc(value);
  ptrLinkNode pointer = hashArray[bucket_num];
  while (pointer) {
    if (pointer->getValue() == value) {
      if (pointer->getPrev() == nullptr) {
        ptrLinkNode pointer2 = pointer->getNext();
        delete pointer;
        pointer = pointer2;
        pointer->setPrevNode(nullptr);
        --size;
        return true;
      } else if (pointer->getNext() == nullptr) {
        ptrLinkNode pointer2 = pointer->getPrev();
        delete pointer;
        pointer2->setNextNode(nullptr);
        --size;
        return true;
      } else {
        ptrLinkNode pointer_l = pointer->getPrev();
        ptrLinkNode pointer_r = pointer->getNext();
        delete pointer;
        pointer_l->setNextNode(pointer_r);
        pointer_r->setPrevNode(pointer_l);
        --size;
        return true;
      }
    }
    pointer = pointer->getNext();
  }
  return false;
}

//@desc 在哈希表中寻找数据
template <typename KEY, typename VALUE>
bool HashTable<KEY, VALUE>::searchValue(const VALUE &value) const {
  KEY bucket_num = hashFunc(value);
  LinkNode<KEY, VALUE> *pointer = hashArray[bucket_num];
  while (pointer) {
    if (pointer->getValue() == value) {
      return true;
    }
    pointer = pointer->getNext();
  }
  return false;
}

// hash function
template <typename KEY, typename VALUE>
KEY HashTable<KEY, VALUE>::hashFunc(const VALUE &value) const {
  int data_length = sizeof(value);
  char *str_local = new char[data_length + 1];
  memcpy(str_local, &value, data_length);
  str_local[data_length] = '\0';
  unsigned long hash = 5381;
  int c;
  while (c = *str_local++)
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  KEY key = (KEY)hash % cap;
  return key;
}
