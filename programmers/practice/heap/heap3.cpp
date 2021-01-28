/*
https://programmers.co.kr/learn/courses/30/lessons/42628
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    
    // 이중 우선순위 큐
    map<int, int> numQueue; // pair< num, cnt >
    
    for(int i=0; i<operations.size(); i++){
        string temp = operations[i];
        int num = stoi(temp.substr(2,temp.size()-2));
            
        if(temp[0] == 'I'){
            numQueue[num]++;
        } else if(num == 1){    // max
            if(numQueue.size()){
                auto maxIter = numQueue.end();
                maxIter--;
                
                if(maxIter -> second == 1){     // 해당 num이 하나밖에 없다면 삭제
                    numQueue.erase(maxIter);
                } else {
                    maxIter -> second -= 1;
                }
            }
        } else {                // min
            if(numQueue.size()){
                auto minIter = numQueue.begin();

                if(minIter -> second == 1){     // 해당 num이 하나밖에 없다면 삭제
                    numQueue.erase(minIter);
                } else {
                    minIter -> second -= 1;
                }
            }
        }
    }
    
    if(!numQueue.empty()){
        answer[0] = numQueue.rbegin() -> first;
        answer[1] = numQueue.begin() -> first;
    }
    
    return answer;
}