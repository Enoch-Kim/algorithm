#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(string& s1, string& s2){
    return s1.size() < s2.size();
}

bool isEqual(string& s1, string& s2, int first, int last){
    for(int i=0; i<first; i++){
        if(s1[i] != s2[i]) return false;
    }
    for(int i=last+1; i<s1.size(); i++){
        if(s1[i] != s2[i]) return false;
    }
    return true;
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer(queries.size());
    sort(words.begin(), words.end(), compare);
    int size = words.size();
    int maxLen = words[size-1].size();
    int minLen = words[0].size();
    unordered_map<int, int> lenMap;
    for(int i=0; i<size; i++){
        int len = words[i].size();
        if(lenMap.find(len) != lenMap.end()) continue;
        lenMap[len] = i;
    }
    
    for(int i=0; i<queries.size(); i++){
        string& temp = queries[i];
        int len = temp.size();
        if(lenMap.find(len) == lenMap.end()){
            answer[i] = 0;
            continue;
        }
        int first = temp.find_first_of('?');
        int last = temp.find_last_of('?');
        int count = 0;
        for(int j=lenMap[len]; j<size; j++){
            if(words[j].size() == len){
                if(isEqual(words[j], temp, first, last)){
                    count++;
                }
            }else{
                break;
            }
        }
        answer[i] = count;
    }
    
    return answer;
}