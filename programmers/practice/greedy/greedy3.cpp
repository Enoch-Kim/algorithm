/*
https://programmers.co.kr/learn/courses/30/lessons/42883
*/

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    k = number.size() - k;
    
    while(k){
        
        if(k == number.size()){
            answer += number;
            break;
        }
        
        int idx = -1;
        char maxChar = 0;
        for(int i=0; i<number.size()-(k-1); i++){
            char temp = number[i];
            if(temp > maxChar){
                maxChar = temp;
                idx = i;
            }
        }
        answer += number[idx];
        number = number.substr(idx+1);
        k--;
    }
    
    return answer;
}