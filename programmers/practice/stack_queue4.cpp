/*
https://programmers.co.kr/learn/courses/30/lessons/42587
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    
    int size = priorities.size();
    int target = priorities[location];
    
    for(int i=0; i<size; i++){
        if(priorities[i] > target){
            answer++;
        }
    }
    
    int startIdx = 0;
    int above = 9;
    while(above > target){
        int i = startIdx == 0 ? size-1 : startIdx-1;
        
        while((i+size)%size != startIdx){
            if(priorities[i%size] == above){
                startIdx = (i+size)%size;
                break;
            }
            i--;
        }
        above--;
    }
    
    int i = startIdx;
    

    while(i%size != location){
        if(priorities[i%size] == target){
            answer++;
        }
        i++;
    }
    
    
    return answer;
}