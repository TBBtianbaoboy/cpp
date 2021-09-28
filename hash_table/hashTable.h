//定义哈希表

#include "linkNode.h"
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
