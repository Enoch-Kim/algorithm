/*
    2020-03-10
    Hash Table 
    include Chaining Collision Resolution by Linked List
*/
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <memory>

template<typename Key, typename Val>
struct HashNode{
    public :
        HashNode()
            : key(), val(), next(nullptr) 
        {}
        HashNode(Key key, Val val)
            : key(key), val(val), next(nullptr)
        {}

        HashNode<Key,Val>* next;
        Key key;
        Val val;
};



template<typename Key, typename Val>
class HashTable
{
    public :
        HashTable() 
            : size(1000), vals(new HashNode<Key,Val>[size])
        {}

        HashTable(int size) 
            : size(size), vals(new HashNode<Key,Val>[size])
        {}

        HashTable(Key key, Val val)
            : size(1000), vals(new HashNode<Key,Val>[size])
        {
            InsertData(key, val);
        }

        HashTable(Key key, Val val, int size)
            : size(size), vals(new HashNode<Key,Val>[size])
        {
            InsertData(key, val);
        }
        
        void InsertData(Key key, Val val){
            int hashKey = getHashKey(key);
            if(hashKey == 0) throw "Overflow Maximum Size!!";

            if(vals[hashKey].key){
                std::cout << "insert to linked list" << std::endl;
                HashNode<Key,Val>* node = &(vals[hashKey]);
                if(node -> key == key){
                    node -> val = val;
                    return;
                }
                else{
                    
                }
                    while(node -> next){
                        node = node -> next;
                        if(node -> key == key){
                            node -> val = val;
                            return;
                        }
                    }
                node -> next = new HashNode(key, val);  
            }
            else {
                vals[hashKey].key = key;
                vals[hashKey].val = val;
                return;
            }
        }

        Val getData(Key key) {
            int hashKey = getHashKey(key);
            if(hashKey == 0) throw "Overflow Maximum Size!!";

            if(vals[hashKey].key){
                HashNode<Key,Val>* node = &(vals[hashKey]);
                if(node -> key == key)
                    return node -> val;
                else
                    while(node -> next){
                        std::cout << '\n' << "---------------------------" << std::endl;
                        node = node -> next;
                        if(node -> key == key)
                            return node -> val;
                    }
                return 0;
            }
            else 
                return 0;
        }

        int DeleteData(Key key) {
            int hashKey = getHashKey(key);
            if(hashKey == 0) throw "Overflow Maximum Size!!";

            if(vals[hashKey].key){
                HashNode<Key,Val>* node = &(vals[hashKey]);
                if(node -> key == key){
                    if(node -> next){
                        HashNode<Key,Val>* nextNode = node -> next;
                        node -> key = nextNode -> key;
                        node -> val = nextNode -> val;
                        node -> next = nextNode -> next;
                        delete nextNode;
                        return 1;
                    }
                    node -> key = 0;
                    node -> val = 0;
                }
                else
                    while(node -> next){
                        node = node -> next;
                        if(node -> key == key){
                            if(node -> next){
                                HashNode<Key,Val>* nextNode = node -> next;
                                node -> key = nextNode -> key;
                                node -> val = nextNode -> val;
                                node -> next = nextNode -> next;
                                delete nextNode;
                                return 1;   
                            }
                            node -> key = 0;
                            node -> val = 0;
                            return 1;
                        }
                    }
                return 0;
            }
            else 
                return 0;
        }

    private :
       
        int getHashKey(Key k) {
            if(int(k) >= size){
                return 0;
            }
            int hashKey = int(k) % size;
            return hashKey > 0 ? hashKey : hashKey + size;  // 0이 존재하지 않음
        }
        
        int size;
        std::unique_ptr<HashNode<Key,Val>[]> vals;
};



int main() {
    HashTable<char, int> hashTable1('c', 1, 100);
    std::cout << "value of key c is " << hashTable1.getData('c') << std::endl;
    hashTable1.InsertData('c', 2);
    std::cout << "value of key c is " << hashTable1.getData('c') << std::endl;
    hashTable1.InsertData('b', 3);
    std::cout << "value of key b is " << hashTable1.getData('b') << std::endl;
    hashTable1.InsertData(-1, 500);
    std::cout << "value of key -2 is " << hashTable1.getData(-1) << std::endl;

    HashTable<double, int> hashTable2(2, 3, 100);
    std::cout << "value of key 2 is " << hashTable2.getData(2) << std::endl;
    hashTable2.InsertData(3, 5);
    std::cout << "value of key 3 is " << hashTable2.getData(3) << std::endl;
    hashTable2.InsertData(-98, 34344);
    std::cout << "value of key -98 is " << hashTable2.getData(-98) << std::endl;
    hashTable2.InsertData(10, 32432);
    std::cout << "value of key 10 is " << hashTable2.getData(10) << std::endl;
    hashTable2.DeleteData(2);
    std::cout << "value of key 2 is " << hashTable2.getData(2) << std::endl;
    std::cout << "value of key -98 is " << hashTable2.getData(-98) << std::endl;
    return 0;
}