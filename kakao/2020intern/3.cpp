/*
https://programmers.co.kr/learn/courses/30/lessons/67258
*/

#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <map>
#include <utility>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer{0, 0};
    int length = 100001;
    
    unordered_map<string, deque<int>> gemMap;
    
    for(int i=0; i<gems.size(); i++){
        gemMap[gems[i]].push_back(i);
    }

    if(gemMap.size() == 1){
        answer[0] = 1;
        answer[1] = 1;
        return answer;
    }
    
    map<int, string> gemTree;
    
    for(auto gem : gemMap){
        gemTree[gem.second.front()] = gem.first;
    }
    
    
    while(true){
        string startGem = gemTree.begin() -> second;
        int start = gemTree.begin() -> first;
        int end = gemTree.rbegin() -> first;
        
        if(length > (end - start)){
            length = end - start;
            answer[0] = start+1;
            answer[1] = end+1;
        }
        
        if(gemMap[startGem].size() == 1){
            break;
        }
        gemTree.erase(start);
        gemMap[startGem].pop_front();
        gemTree[gemMap[startGem].front()] = startGem;
    }
    
    return answer;
}