/*
https://programmers.co.kr/learn/courses/30/lessons/43163
*/

#include <string>
#include <vector>
#include <deque>

using namespace std;

bool canChange(string& a, string& b){
    int differCnt = 0;
    for(int i=0; i<a.size(); i++){
        if(a[i] != b[i]){
            differCnt++;
        }
    }
    if(differCnt == 1) return true;
    else return false;
}

int solution(string begin, string target, vector<string> words) {
    
    int beginIdx = -1;
    int targetIdx = -1;
    int size = words.size();
    vector<vector<bool>> changeMap(size, vector<bool>(size,false));
    deque<vector<int>> wordQueue(0); // {cnt, idx} queue
    vector<bool> visitMap(size);
    
    for(int i=0; i<size; i++){
        string temp = words[i];
        if(temp == target){
            targetIdx = i;
        }

        if(canChange(temp, begin)){
            wordQueue.push_back({1, i});
        }
        
        for(int j=i+1; j<size; j++){
            string next = words[j];
            if(canChange(temp, next)){
                changeMap[i][j] = true;
                changeMap[j][i] = true;
            }
        }
    }
    
    if(targetIdx == -1) return 0;
    
    while(wordQueue.size()){
        int changeCnt = wordQueue.front().at(0);
        int idx = wordQueue.front().at(1);
        

        wordQueue.pop_front();
        
        if(visitMap[idx]){
            continue;
        }
        visitMap[idx] = true;
        
        if(idx == targetIdx){
            return changeCnt;
        }
        
        for(int i=0; i<words.size(); i++){
            if(changeMap[idx][i]){
                wordQueue.push_back({changeCnt+1, i});
            }
        }
        
        
    }
    
    
    return 0;
}
