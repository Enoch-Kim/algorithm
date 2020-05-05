#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string,string> idMap;
    const string enter = "Enter", leave = "Leave", change = "Change";
    // id mapping
    for(int i=0; i<record.size(); ++i){
        string temp = record[i];
        int operIdx = 0;
        while(temp[operIdx]!=' '){
            operIdx++;
        }
        string operString = temp.substr(0,operIdx);
        if(operString == enter || operString == change){
            int id = operIdx+1;
            while(temp[id]!=' '){
                id++;
            }
            idMap[temp.substr(operIdx+1, id-operIdx-1)] = temp.substr(id+1, temp.size()-id-1);
        }
    }
    // result
    for(int i=0; i<record.size(); i++){
        string temp = record[i];
        int operIdx = 0;
        while(temp[operIdx]!=' '){
            operIdx++;
        }
        string operString = temp.substr(0,operIdx);
        
        if(operString == enter){
            int id = operIdx+1;
            while(temp[id]!=' '){
                id++;
            }
            string s = idMap[temp.substr(operIdx+1, id-operIdx-1)] + "님이 들어왔습니다.";
            answer.push_back(s);
        }else if(operString == leave){
            string s = idMap[temp.substr(operIdx+1, temp.size()-operIdx-1)] + "님이 나갔습니다.";
            answer.push_back(s);
        }
    }
    return answer;
}
// 3:20