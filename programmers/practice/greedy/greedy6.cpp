/*
https://programmers.co.kr/learn/courses/30/lessons/42884
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    if(a[0] == b[0]){
        return a[1] < b[1];
    } else {
        return a[0] < b[0];
    }
}

bool isInclude(vector<int> route, int pos){
    if(route[0] <= pos && route[1] >= pos){
        return true;
    }
    return false;
}

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(), routes.end(), compare);
    
    
    int idx = routes.size()-1;
    while(idx >= 0){
        int pos = routes[idx][0];
        idx--;
        
        while(idx >= 0 && isInclude(routes[idx], pos))
            idx--;
        answer++;
    }
    
    return answer;
}