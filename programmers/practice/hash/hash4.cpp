/*
https://programmers.co.kr/learn/courses/30/lessons/42579
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

bool compareFunc(pair<string, int>& a, pair<string, int>& b){
    return a.second > b.second;
}

bool compareFunc2(pair<int, int>& a, pair<int, int>& b){
    if(a.second == b.second){
        return a.first < b.first;
    } else {
        return a.second > b.second;    
    }
    
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> playMap;                      // genre : total play
    unordered_map<string, vector<pair<int,int>>> musicMap;   // genre : music<idx, play>
    
    for(int i=0; i<genres.size(); i++){
        string genre = genres[i];
        int play = plays[i];
        playMap[genre] += play;
        musicMap[genre].push_back({i,play});
    }
    
    vector<pair<string,int>> playArr;
    
    for(auto genre : playMap){
        playArr.push_back(genre);
    }
    
    sort(playArr.begin(), playArr.end(), compareFunc);
    
    for(int i=0; i<playArr.size(); i++){
        string genre = playArr[i].first;
        
        sort(musicMap[genre].begin(), musicMap[genre].end(), compareFunc2);
        
        for(int j=0; j<musicMap[genre].size() && j<2; j++){
            answer.push_back(musicMap[genre][j].first);
        }
    }
    
    return answer;
}