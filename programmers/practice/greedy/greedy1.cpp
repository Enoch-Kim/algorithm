/*
https://programmers.co.kr/learn/courses/30/lessons/42862
*/

#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    vector<int> students(n, 0);
    for(int i=0; i<lost.size(); i++){
        students[lost[i]-1] -= 1;
    }
    for(int i=0; i<reserve.size(); i++){
        students[reserve[i]-1] += 1;
    }
    for(int i=0; i<n; i++){
        if(students[i] == -1){
            if(i!=0 && students[i-1] == 1){
                students[i-1] -= 1;
                students[i] += 1;
                continue;
            }
            
            if(i!=n-1 && students[i+1] == 1){
                students[i+1] -= 1;
                students[i] += 1;
                continue;
            }
            
            answer--;
        }
        
    }
    
    return answer;
}