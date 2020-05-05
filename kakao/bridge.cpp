#include <string>
#include <vector>

using namespace std;

int solution(vector<int> stones, int k) {
    int low = 1;
    int high = 200000000;
    while(high>low){
        int mid = (low+high)/2;
        int count = 0;
        for(int i=0; i<stones.size();++i){
            if(stones[i] <= mid){
                count++;
                if(count == k) break;
            }else{
                count = 0;
            }
        }
        if(count == k){
            high = mid;
        }else{
            low = mid+1;
        }
    }
    return high;
}