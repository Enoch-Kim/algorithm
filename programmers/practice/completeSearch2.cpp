/*
https://programmers.co.kr/learn/courses/30/lessons/42839
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<bool> *numMapPtr = nullptr;
unordered_set<int> *primeSetPtr = nullptr;


// Programmers에서 Prime 을 찾기위한 메모리 수용 공간이 부족한가보다..
void checkPrime(vector<bool>& numMap){
    int size = numMap.size();
    for(int i=2; i<size; i++){
        if(numMap[i]){
            continue;
        }
        
        for(int j=i; j*i<size; j++){
            numMap[i*j] = true;
        }
    }
}

bool isPrime(int num){
    for(int i=2; i*i<=num; i++){
        if(num%i == 0){
            return false;
        }
    }
    return true;
}

void searchPrime(string& numbers, string number, vector<bool> isUsed, int cnt){
    if(cnt == numbers.size()){
        if(number.size() == 0 || number[0] == '0') return;
        
        int num = stoi(number);
        if(num < 2) return;
        if(numMapPtr -> at(num) == false){
            primeSetPtr -> insert(num);
        }
        // if(isPrime(num)){
        //     primeSetPtr -> insert(num);
        // }
    } else {
        for(int i=0; i<numbers.size(); i++){
            if(isUsed[i]) continue;
            number += numbers[i];
            isUsed[i] = true;
            searchPrime(numbers, number, isUsed, cnt+1);
            
            number.pop_back();
            
            searchPrime(numbers, number, isUsed, cnt+1);
            
            isUsed[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    sort(numbers.rbegin(), numbers.rend());
    
    int maxValue = stoi(numbers);
    
    unordered_set<int> primeSet;
    vector<bool> numMap(maxValue+1, false);
    numMap[0] = true;
    numMap[1] = true;
    
    numMapPtr = &numMap;
    primeSetPtr = &primeSet;
    
    checkPrime(numMap);
    
    vector<bool> isUsed(numbers.size(), false);
    
    searchPrime(numbers, "", isUsed, 0);
    
    numMapPtr = nullptr;
    primeSetPtr = nullptr;
    
    answer = primeSet.size();
    
    return answer;
}