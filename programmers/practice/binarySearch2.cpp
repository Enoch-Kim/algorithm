/*
https://programmers.co.kr/learn/courses/30/lessons/43236
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    
    int answer = 0;
    
    int high = distance;
    int low = 0;
    
    rocks.push_back(distance);
    int size = rocks.size();
    
    sort(rocks.begin(), rocks.end());
    
    while(high >= low){
        int mid = (high + low)/2;
        int cnt = 0;
        
        int idx = 0;
        int pos = 0;
        
        while(idx < size){
            while(idx < size && rocks[idx]-pos < mid){
                cnt++;
                idx++;
            }
            if(idx == size) break;
            pos = rocks[idx];
            idx++;
        }
        
        if(cnt > n){
            high = mid-1;
        } else {
            answer = max(mid, answer);
            low = mid+1;
        }
    }
    
    
    return answer;
}