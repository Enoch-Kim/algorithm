/*
https://programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    unordered_map<string, bool> playerMap;  // 선수들의 xor 결과를 담을 해시테이블
    
    for(auto p : participant){
        playerMap[p] ^= 1;
    }
    
    for(auto c : completion){
        playerMap[c] ^= 1;
    }
    
    for(auto p : playerMap){
        if(p.second) {
            answer = p.first;        // 결국 홀수로 남은 선수가 결과
            break;
        } 
    }
    return answer;
}