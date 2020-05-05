#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int solution(vector<string> strs, string t)
{
    int len = t.length(), size = strs.size();
    vector<int> dp(len, len+1);
    for(int i=0; i<len; i++){
        char temp = t[i];
        for(int j=0; j<size; j++){
            if(temp == strs[j].back()){
                int idx = i-strs[j].length() + 1;
                if(idx < 0) continue;
                bool comp = t.compare(idx, strs[j].length(), strs[j]);
                if(!comp) dp[i] = idx > 0 ? min(dp[i], dp[idx-1] + 1) : 1;
            }
        }
    }
    if(dp[len-1] == len+1) return -1;
    return dp[len-1];
}