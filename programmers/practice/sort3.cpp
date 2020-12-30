/*
https://programmers.co.kr/learn/courses/30/lessons/42747
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer=0;
    int size = citations.size();
    
    sort(citations.rbegin(), citations.rend());
    
    // int high = size-1;
    // int low = 0;
    // while(high > low){
    //     int mid = (high + low+1)/2;
    //     if(citations[mid] >= mid+1){
    //         low = mid;
    //         answer = mid+1;
    //     } else {
    //         high = mid-1;
    //     }
    // }
    
    // logn -> nlogn
    
    
    
    for(int i=0; i<size; i++){
        if(citations[i] >= i+1){
            answer = i+1;
        } else {
            break;
        }
    }
    
    return answer;
}