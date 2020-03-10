/*
    2020-03-10
    Hash Table 
*/
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>
#include <initializer_list>

template<typename Key, typename Value>
class HashTable
{
    public :
        HashTable() 
            : size(1000), keys(new Key[size]),  values(new Value[size]){}

        HashTable(int size) 
            : size(size), keys(new Key[size]),  values(new Value[size]){}

        HashTable(std::initializer_list<Key, Vector> pairs)
            : size(pairs.size), keys(new Key[size]), values(new Value[size])
        {
            std::copy()
        }


    private :

        int HashFunction() 
        {
            
        }

        int size;
        std::unique_ptr<Key> keys;
        std::unique_ptr<Value> values;
};



int main() {
    return 0;
}