/*
https://programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_set<string> phoneSet;
    
    for(auto nums : phone_book){
        phoneSet.insert(nums);
    }
    
    for(auto p : phone_book){
        string prefix = "";
        for(size_t i=0; i<p.size()-1; i++){
            prefix += p[i];
            if(phoneSet.count(prefix)){
                return false;
            }
        }
    }
    
    return true;
}