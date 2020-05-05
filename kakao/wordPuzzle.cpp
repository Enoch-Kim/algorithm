#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<int,int> countMap;

void dinamic(vector<unordered_map<int,int>>& sMap, int len, int idx, int count) {
    if(idx > len) return;
    if(idx == len){
        countMap[idx] = count;
        return;
    }
    countMap[idx] = count;
    for(int i=0; i<sMap.size(); ++i){
        if(sMap[i][idx]){
            if(countMap[sMap[i][idx]] || countMap[sMap[i][idx]] > count+1)
                dinamic(sMap, len, sMap[i][idx], count+1);
        }
    }
}

int solution(vector<string> strs, string t)
{
    int answer = 0;
    vector<unordered_map<int,int>> sMap(strs.size());
    for(int i=0; i<strs.size(); i++){
        string s = strs[i];
        int len = s.length();
        std::size_t find=-1; 
        while(true){
            find = t.find(s,find+1);
            if(find!=std::string::npos){
                sMap[i][find] = find+len;
            }else{
                break;
            }
        }
    }
    dinamic(sMap, t.length(), 0, 0);

    return countMap[t.length()] ? countMap[t.length()] : -1;
}

int main(){}