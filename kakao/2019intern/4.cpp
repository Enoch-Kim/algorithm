/*
https://programmers.co.kr/learn/courses/30/lessons/64063
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    unordered_map<long long, long long> rooms;
    
    for(int i=0; i<room_number.size(); i++){
        vector<long long> visit(0);
        long long r = room_number[i];
        
        while(rooms[r]){
            visit.push_back(r);
            r = rooms[r];
        }
        
        visit.push_back(r);
        
        answer.push_back(r);
        
        for(auto v : visit){
            rooms[v] = r+1;
        }
    }
    
    return answer;
}