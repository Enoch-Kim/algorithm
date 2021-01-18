/*
https://programmers.co.kr/learn/courses/30/lessons/43164
parameter가 너무 많은 것 같다.. 추후 stack으로 리팩토링..
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

string findRoute(unordered_map<string, vector<pair<string,int> > >& pathMap, vector<bool>& usedMap, int size, string route, int cnt){
    if(size == cnt){
        return route;
    } else {
        string temp = route.substr(route.size()-3, 3);
        for(int i=0; i<pathMap[temp].size(); i++){
            pair<string,int> next = pathMap[temp][i];
            if(usedMap[next.second]){
                continue;
            }
            usedMap[next.second] = true;
            string result = findRoute(pathMap, usedMap, size, route+next.first, cnt+1);
            if(result != ""){
                return result;
            }
            usedMap[next.second] = false;
        }
    }
    return "";
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    unordered_map<string, vector<pair<string,int> > > pathMap;
    vector<bool> usedMap(tickets.size());
    
    for(int i=0; i<tickets.size(); i++){
        pathMap[tickets[i][0]].push_back({tickets[i][1], i});
    }

    for(auto& arr : pathMap){
        sort(arr.second.begin(), arr.second.end());
    }

    string route = findRoute(pathMap, usedMap, tickets.size(), "ICN", 0);
    
    for(int i=0; i<route.size(); i+=3){
        answer.push_back(route.substr(i, 3));
    }
    
    
    return answer;
}