/*
https://programmers.co.kr/learn/courses/30/lessons/64065
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    unordered_map<int, int> numMap; // num : cnt
    
    int left = 2;    // 괄호 무시
    while(left < s.size()-1){
        int right = s.find('}', left);
        
        if(right == string::npos) break;
        
        int idx = left;
        while(idx < right){
            if(s[idx] == ','){
                int num = stoi(s.substr(left,idx-left));
                numMap[num]++;
                left=idx+1;
            }
            idx++;
        }
        int num = stoi(s.substr(left, right - left));
        numMap[num]++;
        
        left = right+3;
    }
    
    int size = 0;
    for(auto num : numMap){
        size = max(size, num.second);
    }
    
    answer = vector<int>(size, 0);
    
    for(auto num : numMap){
        answer[size - (num.second)] = num.first;
    }
    
    
    return answer;
}