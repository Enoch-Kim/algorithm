/*
https://programmers.co.kr/learn/courses/30/lessons/42746
*/

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string& a, string& b){
    string ab = a + b;
    string ba = b + a;
    
    return ab >= ba;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> numStrs(numbers.size(), "");
    
    for(int i=0; i<numbers.size(); i++){
        numStrs[i] = to_string(numbers[i]);
    }
    
    sort(numStrs.begin(), numStrs.end(), compare);
    
    for(int i=0; i<numStrs.size(); i++){
        answer += numStrs[i];
    }
    
    if(answer[0] == '0') return "0";
    
    return answer;
}