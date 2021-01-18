/*
https://programmers.co.kr/learn/courses/30/lessons/43238
*/

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long high = 1000000000000000000;
    long long low = 0;
    
    while(high > low){
        long long mid = (high + low)/2;
        long long cnt = 0;
        for(auto t : times){
            cnt += mid/t;
        }
        if(cnt >= n ){
            high = mid;
        } else {
            low = mid+1;
        }
    }
    return high;
}