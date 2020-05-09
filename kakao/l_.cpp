#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

bool compare(vector<int> v1, vector<int> v2){
    if(v1[0] == v2[0])
    {
        return v1[1] < v2[1];
    }
    else
    {
        return v1[0] < v2[0];
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    unordered_map<int, unordered_map<int,bool>> lMap;
    unordered_map<int, unordered_map<int,bool>> _Map;
    vector<vector<int>> answer;
    for(int i=0; i<build_frame.size(); i++){
        
    }
    
    sort(answer.begin(), answer.end(), compare);
    return answer;
}