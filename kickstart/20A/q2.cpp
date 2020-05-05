#include <bits/stdc++.h>
using namespace std;

// namespace solve{
//     int result, size, stackSize;

//     void calcMax(vector<vector<int>>& arr, int curIdx, int target, int sum){

//         if(target == 0){
//             result = max(result, sum);
//             return;
//         }
        
//         if(curIdx+1 == stackSize){
//             if(size >= target)
//                 result = max(result, sum + arr[curIdx][target-1]);
//             return;
//         }

//         calcMax(arr, curIdx+1, target, sum);

//         for(int i=0; i <size && i<target; ++i){
//             calcMax(arr, curIdx + 1, target - (i + 1), sum+arr[curIdx][i]);
//         }
//     }
    
//     int solve(int N, int K, int P){
//         vector<vector<int>> arr(N, vector<int>(K));
//         result=0; stackSize = N; size = K; 
//         for(int i=0, data = 0, sum=0; i<N; ++i){
//             sum = 0;
//             for(int j=0; j<size; ++j){
//                 cin >> data;
//                 sum += data;
//                 arr[i][j] = sum;
//             }
//         }
//         calcMax(arr, 0, P, 0);
//         return result;
//     }
// }

int solve(int N, int K, int P){
    vector<int> dp(P+1,0);
    vector<int> s(K+1,0);
    for(int i=0; i<N; i++){
        for(int j=1; j<=K; ++j){
            cin >> s[j];
            s[j] += s[j-1];
        }
        for(int p=P; p>0; p--)
            for(int j=1; j<=p && j<=K; j++)
                dp[p] = max(dp[p], dp[p-j] + s[j]);
    }
    return dp[P];
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 0,
        N = 0, K = 0, P = 0,
        result = 0;
    cin >> T;
    for(int i=0; i<T; ++i){
        cin >> N >> K >> P;
        result = solve(N, K, P);
        cout << "Case #" << i+1 << ": " << result << '\n';
    }
}
/*
2
2 4 5
10 10 100 30
80 50 10 50
3 2 3
80 80
15 50
20 10
*/