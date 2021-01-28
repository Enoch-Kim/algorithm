/*
https://programmers.co.kr/learn/courses/30/lessons/42626
*/

#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
typedef long long ll;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    // 조건에 의하면 계산 결과가 int 벗어날 수 있음
    priority_queue<ll, vector<ll>, greater<ll>> scovilHeap;
    
    for(int i=0; i<scoville.size(); i++){
        int temp = scoville[i];
        scovilHeap.push((ll)temp);
    }
    
    while(scovilHeap.top() < K){
        if(scovilHeap.size() == 1){
            return -1;
        }
        answer++;
        
        ll firstScov = scovilHeap.top();
        scovilHeap.pop();
        ll secondScov = scovilHeap.top();
        scovilHeap.pop();
        
        scovilHeap.push(firstScov + 2*secondScov);
    }
    
    return answer;
}