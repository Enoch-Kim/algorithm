/*
https://programmers.co.kr/learn/courses/30/lessons/64062
*/

#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    map<int, int> stoneMap; // num, cnt
    
    for(int i=0; i<k; i++){
        stoneMap[stones[i]]++;
    }
    answer = stoneMap.rbegin() -> first;
    
    for(int i=k; i<stones.size(); i++){
        if(stoneMap[stones[i-k]] == 1){
            stoneMap.erase(stones[i-k]);
        } else {
            stoneMap[stones[i-k]]--;
        }
        stoneMap[stones[i]]++;
        answer = min(answer, stoneMap.rbegin() -> first);
        
    }
    
    
    return answer;
}