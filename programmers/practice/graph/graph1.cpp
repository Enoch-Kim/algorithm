/*
https://programmers.co.kr/learn/courses/30/lessons/49189
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <deque>
#include <utility>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    unordered_map<int, vector<int>> graph;
    unordered_map<int,int> cntMap;  // pair <Node, Len>
    deque<pair<int,int>> nodeQue;   // pair <Node, Len>
    
    for(int i=0; i<edge.size(); i++){
        vector<int> temp = edge[i];
        graph[temp[0]].push_back(temp[1]);
        graph[temp[1]].push_back(temp[0]);
    }

    for(int i=0; i<graph[1].size(); i++){
        nodeQue.push_back(make_pair(graph[1][i], 1));
    }

    cntMap[1] = -1;

    while(nodeQue.size()){
        int node = nodeQue.front().first;
        int len = nodeQue.front().second;

        nodeQue.pop_front();

        if(cntMap[node]){
            continue;
        }

        cntMap[node] = len;

        for(int i=0; i<graph[node].size(); i++){
            nodeQue.push_back(make_pair(graph[node][i], len+1));
        }
    }
    
    int maxLen = 0;
    for(auto node : cntMap){
        if(node.second > maxLen){
            maxLen = node.second;
            answer = 1;
        } else if(node.second == maxLen){
            answer++;
        }
    }
    return answer;
}