/*
https://programmers.co.kr/learn/courses/30/lessons/42577
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book) {
    unordered_multiset<string> phone_set;
    
    for(auto phone : phone_book){
        phone_set.insert(phone);
    }
    
    for(auto phone : phone_book){
        string temp = "";
        
        if(phone_set.count(phone) > 1) return false;    // 중복이 있는경우도 false
        
        for(int i=0; i<phone.size()-1; i++){    // 동일한건 무조건 있으니 size-2 까지만 확인  
            temp += phone[i];
            if(phone_set.count(temp)){
                return false;
            }
        }
        
    }
    
    return true;
}