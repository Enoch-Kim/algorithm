/*
https://programmers.co.kr/learn/courses/30/lessons/64064
*/

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool isBanned(string& b, string& u){
    if(b.size() != u.size()) return false;
    
    for(int i=0; i<b.size(); i++){
        if(b[i] == '*') continue;
        
        if(b[i] != u[i]) return false;
    }
    
    return true;
}

void searchBanned(vector<vector<string>>& banList, unordered_set<string>& banneds, vector<string> bannedUsers){
    if(bannedUsers.size() == banList.size()){
        sort(bannedUsers.begin(), bannedUsers.end());
        string banned = "";
        for(int i=0; i<bannedUsers.size()-1; i++){
            if(bannedUsers[i] == bannedUsers[i+1]) return;
            banned += bannedUsers[i];
            banned += '*';
        }
        banned += bannedUsers[bannedUsers.size()-1];
        banneds.insert(banned);
        
    } else {
        int i = bannedUsers.size();
        for(int j=0; j<banList[i].size(); j++){
            bannedUsers.push_back(banList[i][j]);
            searchBanned(banList, banneds, bannedUsers);
            bannedUsers.pop_back();
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<vector<string>> banList(banned_id.size(), vector<string>(0));
    
    for(int b=0; b<banned_id.size(); b++){
        string ban = banned_id[b];
        
        for(int u=0; u<user_id.size(); u++){
            string user = user_id[u];
            if(isBanned(ban, user)){
                banList[b].push_back(user);
            }
        }
    }
    
    unordered_set<string> banneds;
    searchBanned(banList, banneds, vector<string>(0));
    
    
    return banneds.size();
}