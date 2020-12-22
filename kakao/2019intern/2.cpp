/*
https://programmers.co.kr/learn/courses/30/lessons/64065
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> vMap(501, vector<int>(0));
    
    
    int i=1;
    while(i < s.size()-1){
        if(s[i] != '{'){
            throw "Invalid Data Set";
        }
        vector<int> temp(0);

        i++;            // to start
        int j = i+1;      // point
        int cnt = 0;
        while(j < s.size()-1 && s[j] != '}'){
            if(s[j] == ','){
                int num = stoi(s.substr(i, j-i));
                temp.push_back(num);
                i = j+1;
            }
            j++;
        }
        int num = stoi(s.substr(i, j-i));
        temp.push_back(num);
        vMap[temp.size()] = temp;

        i=j+2;
    }
    
    i = 1;
    vector<bool> numMap(100001, false);
    
    while(i<500 && vMap[i].size()){
        for(int j=0; j<vMap[i].size(); j++){
            int temp = vMap[i][j];
            if(!numMap[temp]){
                numMap[temp] = true;
                answer.push_back(temp);
                break; 
            }
        }
        i++;
    }
    
    return answer;
}