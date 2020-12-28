/*
https://programmers.co.kr/learn/courses/30/lessons/42584
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(),0);
    vector<int> s(0);
    for(int i=0; i < prices.size(); i++){
        while(!s.empty() && prices[s.back()] > prices[i]){
            answer[s.back()] = i-s.back();
            s.pop_back();
        }
        s.push_back(i);
    }
    
    while(!s.empty()){
        answer[s.back()] = prices.size()-1 - s.back();
        s.pop_back();
    }
    
    return answer;
}