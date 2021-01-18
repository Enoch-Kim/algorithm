/*
https://programmers.co.kr/learn/courses/30/lessons/42748
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto c : commands){
        vector<int> tempArr(c[1]-c[0]+1);
        
        for(int i=c[0]-1; i<c[1]; i++){
            tempArr[i-c[0]+1] = array[i];
        }
        
        sort(tempArr.begin(), tempArr.end());
        
        answer.push_back(tempArr[c[2]-1]);
    }
    
    return answer;
}