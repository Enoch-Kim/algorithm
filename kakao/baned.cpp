#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

bool isEqual(string s1, string s2){
    if(s1.length() != s2.length()) 
        return false;

    for(int i=0; i<s1.length(); i++){
        if(s1[i] == '*') continue;
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

void calcSet(vector<vector<int>>& bMap, unordered_map<int,bool>& ans, int curIdx, int bset){
    if(curIdx == bMap.size()-1){
        for(int i=0; i < bMap[curIdx].size(); i++){
            if( bset&(1<<bMap[curIdx][i])) continue;
            ans[bset|1<<bMap[curIdx][i]] = true;
        }
    }else{
        for(int i=0; i< bMap[curIdx].size(); i++){
            if(bset&(1<<bMap[curIdx][i])) continue;
            int nextBset = bset|(1<<bMap[curIdx][i]);
            calcSet(bMap, ans, curIdx+1, nextBset);
        }
    }
}


int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    unordered_map<int, bool> ans;
    int bSize = banned_id.size();
    int uSize = user_id.size();
    int maxAns = 1;
    vector<vector<int>> bMap(bSize);
    for(int i=0; i<bSize; ++i){
        int cur = 0;
        for(int j=0; j<uSize; ++j){
            if(isEqual(banned_id[i], user_id[j])){
                bMap[i].push_back(j);
            }
        }
    }
    calcSet(bMap, ans, 0, 0);
    for(auto i : ans)
        answer++;

    return answer;
}