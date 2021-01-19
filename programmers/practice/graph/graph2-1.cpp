/*
https://programmers.co.kr/learn/courses/30/lessons/49191
처음에 푼 방식 => E * V^2
*/

#include <string>
#include <vector>

using namespace std;

void copyResult(vector<vector<int>>& resultMap, int win, int loss){
    if(resultMap[win][loss]){
        return;
    }
    resultMap[win][loss] = 1;
    resultMap[loss][win] = -1;
    for(int i=1; i<resultMap.size(); i++){
        if(resultMap[win][i] == -1){
            copyResult(resultMap, i, loss);
        }
        if(resultMap[loss][i] == 1){
            copyResult(resultMap, win, i);
        }
    }
}

int solution(int n, vector<vector<int>> results) {
    
    if(n == 1) return 1;
    
    int answer = 0;
    
    vector<vector<int>> resultMap(n+1, vector<int>(n+1, 0));
    
    for(int i=0; i<results.size(); i++){
        int win = results[i][0];
        int loss = results[i][1];
        
        copyResult(resultMap, win, loss);
    }
    
    
    
    for(int i=1; i<=n; i++){
        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(resultMap[i][j]){
                cnt++;
            }
        }
        if(cnt == n-1){
            answer++;
        }
    }
    
    
    return answer;
}