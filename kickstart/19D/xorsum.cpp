#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

bool isXorEven(int n){
    int count = 0;
    for(int i=0; i<11; ++i){
        if(n & (1<<i)) count++;
    }
    return !(count%2);
}

void solution(int T) {
    cout << "#" << T << ": ";
    int N=0, Q=0;
    cin >> N >> Q;
    vector<int> numArr(N);
    vector<int> xorSumArr(N);
    int xorSum = 0;
    for(int i=0; i<N; ++i){
        cin >> numArr[i];
        xorSum ^= numArr[i];
        xorSumArr[i] = xorSum;
    }
    for(int i=0; i<Q; ++i){
        int idx=0, num=0;
        cin >> idx >> num;
        int maxSum = 0;
        for(int j=0; j<idx; ++j){
            if(isXorEven(xorSumArr[j])){
                maxSum = max(maxSum, xorSumArr[j]);
            }
        }
        for(int j=idx; j<N; ++j){
            xorSumArr[j] ^= numArr[idx];
            xorSumArr[j] ^= num;
            if(isXorEven(xorSumArr[j])){
                maxSum = max(maxSum, xorSumArr[j]);
            }
        }
        numArr[idx] = num;
        cout << maxSum << " ";
    }
    cout << '\n';
}


int main() {
    int T;
    cin >> T;
    for(int i=1; i<=T; ++i){
        solution(i);
    }
    return 0;
}

/*
2
4 3
10 21 3 7
1 13
0 32
2 22
5 1
14 1 15 20 26
4 26
*/