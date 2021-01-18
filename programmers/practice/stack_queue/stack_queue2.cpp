/*
https://programmers.co.kr/learn/courses/30/lessons/42586
*/

#include <string>
#include <vector>

using namespace std;

int calcDay(int p, int s){
    return (100-p + s-1)/s;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer(0);
    int size = progresses.size();
    int i=0;
    while(i<size){
        int temp = calcDay(progresses[i], speeds[i]);
        
        int cnt = 1;
        int j=i+1;
        
        while(j<size && calcDay(progresses[j], speeds[j]) <= temp){
            cnt++;
            j++;
        }
        answer.push_back(cnt);
        i = j;
    }
    
    
    return answer;
}