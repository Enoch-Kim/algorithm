#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <utility>

using namespace std;

inline bool compare(string& s1, string& s2){
    return s1.size() < s2.size();
}

inline bool isEqual(string& s1, string& s2, int first, int last){
    if(first!=last){
        bool left = isEqual(s1,s2, first, (first+last)/2);
        bool right = isEqual(s1,s2, (first+last)/2, last);
        if(!left || !right) return false;
    }else{
        return s1[first] == s2[first];
    }
}

pair<int,int> findRange(string& q, int len){
    if(q.front() == '?' && q.back()=='?') return make_pair(0,len-1);
    else if(q.front() == '?'){
        int start = 0;
        int end = len-1;
        int mid;
        while(start < end){
            mid = (start+end)/2;
            if(q[mid] == '?'){
                start = mid+1;
            }else{
                end = mid;
            }
        }
        return make_pair(0,end-1);
    }else{
        int start = 0;
        int end = len-1;
        int mid;
        while(start < end){
            mid = (start+end)/2;
            if(q[mid] == '?'){
                end = mid;
            }else{
                start = mid+1;
            }
        }
        return make_pair(end,len-1);
    }
    return make_pair(-1,-1);
}

int findLowerbound(vector<string>& words, int len){
    int start = 0;
    int end = words.size();
    int mid;
    while(start<end){
        mid = (start+end)/2;
        if(words[mid].length() >= len){
            end = mid;
        }else{
            start = mid+1;
        }
    }
    return end;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size());
    int size = words.size();
    unordered_map<int, vector<string>> wordMap;
    for(int i=0; i<size; ++i){
        wordMap[words[i].length()].push_back(words[i]);
    }

    unordered_map<string, int> countMap;
    
    for(int i=0; i<queries.size(); i++){
        string& temp = queries[i];
        if(countMap.find(temp) != countMap.end()){
            answer[i] = countMap[temp];
            continue;
        }
        int len = temp.size();
        pair<int,int> range = findRange(temp, len);
        int count = 0;
        if(range.first == 0 && range.second == len-1){
            countMap[temp] = wordMap[len].size();
            answer[i] = wordMap[len].size();
            continue;
        }else if(range.first == 0){
            for(int j=0; j<wordMap[len].size(); j++){
                if(isEqual(wordMap[len][j], temp, range.second+1, len)) count++;
            }
        }else{
            for(int j=0; j<wordMap[len].size(); j++){
                if(isEqual(wordMap[len][j], temp, 0, range.first)) count++;
            }
        }
        countMap[temp] = count;
        answer[i] = count;
    }
    
    return answer;
}