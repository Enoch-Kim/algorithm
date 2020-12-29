/*
https://programmers.co.kr/learn/courses/30/lessons/42576
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> userMap;
    
    for(auto p : participant){
        userMap[p]++;
    }
    
    for(auto c : completion){
        userMap[c]--;
    }
    
    for(auto u : userMap){
        if(u.second){
            answer = u.first;
            break;
        }
    }
    
    return answer;
}