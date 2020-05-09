#include <string>
#include <vector>
#include <utility>
#include <list>
#include <unordered_map>
#include <iostream>

typedef long long ll;

using namespace std;


ll getAbs(ll a){
    if(a >= 0){
        return a;
    }else{
        return -a;
    }
}



void calc(list<ll>& nums, list<char>& opers, char target){
    int idx=0;
    auto oper = opers.begin();
    
    while(oper != opers.end()){
        if(*oper == target){
            auto num1 = nums.begin();
            auto nextOper = oper;
            nextOper++;
            int idx2 = -1;
            while(++idx2 < idx){
                ++num1;
            }
            auto num2 = num1;
            num2++;
            switch (target)
            {
                case '*':
                    (*num1) *= (*num2);
                    nums.erase(num2);
                    oper = opers.erase(oper);
                    break;
                case '-':
                    (*num1) -= (*num2);
                    nums.erase(num2);
                    oper = opers.erase(oper);
                    break;
                case '+':
                    (*num1) += (*num2);
                    nums.erase(num2);
                    oper = opers.erase(oper);
                    break;
                default:
                    break;
            }
            continue;
        }
        idx++;
        oper++;
    }
    
}

long long solution(string expression) {
    long long answer = 0;
    vector<list<ll>> nums(6);
    vector<list<char>> opers(6);
    vector<char> operKey{'*', '+', '-'};
    unordered_map<char, bool> keyMap;
    int size = expression.size();
    int i=0;
    while(i < size){
        if(expression[i] >= '0' && expression[i] <= '9'){
            ll num = expression[i] - '0';
            i++;
            while(i < size && expression[i] >= '0' && expression[i] <= '9'){
                num *= 10;
                num += (expression[i] - '0');
                i++;
            }
            for(int j=0; j<6; j++){
                nums[j].push_back(num);
            }
        }
        if(i == size) break;
        for(int j=0; j<6; j++){
            opers[j].push_back(expression[i]);
        }
        keyMap[expression[i]] = true;
        i++;
    }

    {
        //case 132
        if(keyMap[operKey[0]]) calc(nums[0], opers[0], operKey[0]);
        if(keyMap[operKey[2]]) calc(nums[0], opers[0], operKey[2]);
        if(keyMap[operKey[1]]) calc(nums[0], opers[0], operKey[1]);
        
    }
    {
        // case 123
        if(keyMap[operKey[0]]) calc(nums[1], opers[1], operKey[0]);
        if(keyMap[operKey[1]]) calc(nums[1], opers[1], operKey[1]);
        if(keyMap[operKey[2]]) calc(nums[1], opers[1], operKey[2]);
    }

    {
        //case 213
        if(keyMap[operKey[1]]) calc(nums[2], opers[2], operKey[1]);
        if(keyMap[operKey[0]]) calc(nums[2], opers[2], operKey[0]);
        if(keyMap[operKey[2]]) calc(nums[2], opers[2], operKey[2]);
        
    }
    {
        // case 231
        if(keyMap[operKey[1]]) calc(nums[3], opers[3], operKey[1]);
        if(keyMap[operKey[2]]) calc(nums[3], opers[3], operKey[2]);
        if(keyMap[operKey[0]]) calc(nums[3], opers[3], operKey[0]);
    }

    {
        //case 312
        if(keyMap[operKey[2]]) calc(nums[4], opers[4], operKey[2]);
        if(keyMap[operKey[0]]) calc(nums[4], opers[4], operKey[0]);
        if(keyMap[operKey[1]]) calc(nums[4], opers[4], operKey[1]);
        
    }
    {
        // case 321
        if(keyMap[operKey[2]]) calc(nums[5], opers[5], operKey[2]);
        if(keyMap[operKey[1]]) calc(nums[5], opers[5], operKey[1]);
        if(keyMap[operKey[0]]) calc(nums[5], opers[5], operKey[0]);
    }
    for(int i=0; i<nums.size(); ++i){
        int temp = nums[i].front();
        answer = max(answer, getAbs(temp));
    }
    return answer;
}

int main() {
    string s = "100-200*300-500+20";
    cout << solution(s); 
}


// 001 123 1
// 010 213 2

// 011 213 3

// 100 312 4

// 101 312 5

// 110 321 6
// 111 3
