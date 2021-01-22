/*
https://programmers.co.kr/learn/courses/30/lessons/67257
*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool isNumber(char c){
    return (c >= '0' && c <= '9');
}

string calcOper(string& a, string& b, char oper){
    long long aNum = stoll(a);
    long long bNum = stoll(b);
    
    switch(oper){
        case '*':
            return to_string(aNum * bNum);
        case '+':
            return to_string(aNum + bNum);
        case '-':
            return to_string(aNum - bNum);
    }
    return "";
}

long long calcExpression(vector<string> operStack, vector<char> order){
    vector<string> tempStack;
    for(int i=0; i<order.size(); i++){  
        while(operStack.size()){
            string temp = operStack.back();
            operStack.pop_back();
            if(temp.back() == order[i]){
                tempStack.back() = calcOper(tempStack.back(), operStack.back(), order[i]);
                operStack.pop_back();
            } else {
                tempStack.push_back(temp);
            }
        }
        
        while(tempStack.size()){
            operStack.push_back(tempStack.back());
            tempStack.pop_back();
        }
        // for(auto it : operStack){
        //     cout << it << "\t";
        // }
        // cout << '\n';
    }
    if(operStack.size() != 1) throw "internal error occur";
    
    return abs(stoll(operStack.back()));
}

long long solution(string expression) {
    long long answer = 0;
    
    vector<string> operStack;
    vector<vector<char>> orders{
        { '*', '+', '-'},
        { '*', '-', '+'},
        { '+', '-', '*'},
        { '-', '+', '*'},
        { '+', '*', '-'},
        { '-', '*', '+'},
    };
    
    int idx = expression.size()-1;
    while(idx >= 0){
        int nextIdx = idx-1;
        while(nextIdx >= 0 && isNumber(expression[nextIdx])){
            nextIdx--;
        }
        operStack.push_back(expression.substr(nextIdx+1, idx - nextIdx));
        if(nextIdx != -1){
            operStack.push_back(expression.substr(nextIdx, 1));
        }
        idx = nextIdx-1;
    }
    
    for(int i=0; i<orders.size(); i++){
        // cout << orders[i][0] << " > " << orders[i][1] << " > " << orders[i][2] << '\n';
    
        long long temp = calcExpression(operStack, orders[i]);
        // cout << temp << '\n';
        answer = max(answer, abs(temp));
    }
    return answer;
}