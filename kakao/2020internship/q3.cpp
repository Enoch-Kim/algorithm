#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <utility>
#include <algorithm>
#include <deque>

using namespace std;

bool compare(pair<string,int> p1, pair<string,int> p2){
    return p1.second < p2.second;
}

vector<int> solution(vector<string> gems) {
    vector<int> answer{0,1000000000};
    int minDistance = 1000000000;
    
    unordered_map<string, deque<int>> gemMap;
    for(int i=0; i<gems.size(); ++i){
        gemMap[gems[i]].push_back(i+1);
    }

    map<int, string> pickedGem;

    for(auto gem : gemMap){
        pickedGem[gem.second.front()] = gem.first;    
    }
    
    
    while(true){
        
        auto minGem = pickedGem.begin();
        auto maxGem = pickedGem.end();
        maxGem--;

        if(minDistance > maxGem->first - minGem->first){
            minDistance = maxGem->first - minGem->first;
            answer[0] = minGem->first;
            answer[1] = maxGem->first;
        }

        gemMap[minGem -> second].pop_front();
        if(gemMap[minGem -> second].empty()) break;
        pickedGem[gemMap[minGem -> second].front()] = minGem -> second;
        pickedGem.erase(minGem);
    }
    return answer;
}