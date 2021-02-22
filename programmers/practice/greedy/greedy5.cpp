/*
https://programmers.co.kr/learn/courses/30/lessons/42861
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b){
    if(a[2] == b[2]){
        if(a[0] == b[0]){
            return a[1] < b[1];
        } else {
            return a[0] < b[0];
        }
    } else {
        return a[2] < b[2];
    }
}

int findRoot(vector<int>& unions, int vertice){
    while(unions[vertice] != -1){
        vertice = unions[vertice];
    }
    return vertice;
}

bool unionFind(vector<int>& unions, vector<int>& edge){
    int v1Root = findRoot(unions, edge[0]);
    int v2Root = findRoot(unions, edge[1]);
    
    if(v1Root == v2Root) return false;
    
    unions[v2Root] = v1Root;
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    sort(costs.begin(), costs.end(), compare);
    
    vector<int> unions(n, -1);
    int edgeCnt = 0;
    int idx = 0;
    
    while(edgeCnt != n-1){
        if(unionFind(unions, costs[idx])){
            answer += costs[idx][2];
            edgeCnt++;
        }
        idx++;
    }
    
    
    return answer;
}