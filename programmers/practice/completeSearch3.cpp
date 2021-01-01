/*
https://programmers.co.kr/learn/courses/30/lessons/42842
*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2, 0);
    
    int total = brown + yellow;
    int half_y = yellow/2;

    for(int i=yellow; i>=yellow/i; i--){
        if(yellow % i == 0){
            int j = yellow / i;
            if((i+2) * (j+2) == total){
                answer[0] = i+2;
                answer[1] = j+2;
                break;
            }
        }
    }
    
    return answer;
}