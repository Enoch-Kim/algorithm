/*
https://programmers.co.kr/learn/courses/30/lessons/42579
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;


vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int size = genres.size();
    unordered_map<string, int> sumMap;
    unordered_map<string, vector<pair<int,int>>> genreMap;
    vector<pair<int,string>> veri;
    
    string curG;
    int curP;
    for(int i=0; i<size; ++i){
        curG = genres[i];
        curP = plays[i];
        sumMap[curG]+=curP;
        genreMap[curG].push_back({curP,size-i});
    }
    for(auto x : sumMap){
        veri.push_back({x.second,x.first});
    }
    sort(veri.rbegin(), veri.rend());
    for(int i=0; i<veri.size(); i++){
        string g = veri[i].second;
        if(genreMap[g].size() == 1){
            answer.push_back(size-genreMap[g][0].second);
            continue;
        }
        sort(genreMap[g].rbegin(), genreMap[g].rend());
        answer.push_back(size-genreMap[g][0].second);
        answer.push_back(size-genreMap[g][1].second);
    }
    return answer;
}