//@desc 定义哈希表

#include "linkNode.h"
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

template<typename KEY,typename VALUE>
class HashTable{
    private:
        typedef LinkNode<KEY,VALUE>* ptrLinkNode;
        ptrLinkNode* hashArray;
        unsigned int bucket; // 桶数量
        unsigned int size; //结点数量
    public:
        HashTable(int cap_init=10);
        ~HashTable();
        unsigned int getBucketNum()const;
        unsigned int getSize()const;
        bool insertValue(const VALUE& value);
        bool deleteValue(const VALUE& value);
        bool searchValue(const VALUE& value) const;
        void printHash()const;
    private:
        KEY hashFunc(const VALUE& value) const;
};

template <typename KEY, typename VALUE>
HashTable<KEY, VALUE>::HashTable(int cap_init)
    : size(0), bucket(cap_init), hashArray(nullptr) {
  hashArray = new ptrLinkNode[bucket];
  for (int i = 0; i < 10; i++) {
    hashArray[i] = nullptr;
  }
}

template <typename KEY, typename VALUE> HashTable<KEY, VALUE>::~HashTable() {
  for (int i = 0; i < bucket; ++i) {
    ptrLinkNode pointer = hashArray[i];
    while (pointer) {
      ptrLinkNode pointer2 = pointer->getNext();
      delete pointer;
      pointer = pointer2;
    }
  }
  delete[] hashArray;
}

//@desc 获取哈希表桶的数量 @test success
template <typename KEY,typename VALUE>
unsigned int HashTable<KEY,VALUE>::getBucketNum()const{
    return bucket;
}

//@desc 获取哈希表结点的数量 @test success
template <typename KEY,typename VALUE>
unsigned int HashTable<KEY,VALUE>::getSize()const{
    return size;
}

//@desc 向哈希表中插入数据 @test success
template <typename KEY, typename VALUE>
bool HashTable<KEY, VALUE>::insertValue(const VALUE &value) {
  VALUE a = value;
  KEY bucket_num = hashFunc(value);
  cout << "value = " << value << ",bucket_num = " << bucket_num << endl;
  ptrLinkNode pointer = hashArray[bucket_num];
  ptrLinkNode newNode = new LinkNode<KEY, VALUE>(bucket_num, a);
  newNode->setNextNode(pointer);
  hashArray[bucket_num] = newNode;
  ++size;
  return true;
}

//@desc 从哈希表中删除数据
template <typename KEY, typename VALUE>
bool HashTable<KEY, VALUE>::deleteValue(const VALUE &value) {
  KEY bucket_num = hashFunc(value);
  ptrLinkNode prev = hashArray[bucket_num];
  // while(prev){
  //     ptrLinkNode pointer = prev->getNext();
  //     if(prev->getValue() == value){
  //         //........
  //     }
  // }
  return false;
}

//@desc 在哈希表中寻找数据 @test success
template <typename KEY, typename VALUE>
bool HashTable<KEY, VALUE>::searchValue(const VALUE &value) const {
  KEY bucket_num = hashFunc(value);
  cout << "start search " << value << ",bucket number is " << bucket_num << endl;
  ptrLinkNode pointer = hashArray[bucket_num];
  while (pointer) {
    if (pointer->getValue() == value) {
      return true;
    }
    pointer = pointer->getNext();
  }
  return false;
}

//@desc 输出哈希表 @test success
template <typename KEY,typename VALUE>
void HashTable<KEY,VALUE>::printHash()const{
    for(int i=0;i<bucket;++i){
        ptrLinkNode pointer = hashArray[i];
        while(pointer){
            cout << pointer->getValue() << endl;
            pointer = pointer->getNext();
        }
    }
}

//@desc 哈希函数 @test success
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
  KEY key = (KEY)hash % bucket;
  return key;
}
