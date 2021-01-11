/*
https://programmers.co.kr/learn/courses/30/lessons/42578
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    unordered_map<string, int> typeMap;
    
    for(auto c : clothes){
        typeMap[c[1]]++;
    }
    
    for(auto t : typeMap){
        answer *= t.second+1;
    }
    
    return answer-1;
}