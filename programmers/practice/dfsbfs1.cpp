/*
https://programmers.co.kr/learn/courses/30/lessons/43165
*/

#include <string>
#include <vector>

using namespace std;

// 배열 생성이 없어 더 빠른듯
void searchMatched(vector<int>& numbers, int target, int& answer, int result, int idx){
    if(idx == numbers.size()){
        if(result == target){
            answer++;
        }
    } else {
        searchMatched(numbers, target, answer, result+numbers[idx], idx+1);
        searchMatched(numbers, target, answer, result-numbers[idx], idx+1);
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    searchMatched(numbers, target, answer, 0, 0);

    // vector<vector<int>> st(0);  // {sum, idx, plus(1) or minus(0)} array
    // st.push_back({0,0,1});
    // st.push_back({0,0,0});
    // while(st.size()){
    //     vector<int> temp = st.back();
    //     st.pop_back();

    //     printf("%d, %d, %d\n", temp[0], temp[1], temp[2]);

    //     if(temp[2]){
    //         temp[0] += numbers[temp[1]];
    //     } else {
    //         temp[0] -= numbers[temp[1]];
    //     }

    //     if(temp[1] == numbers.size()-1){
    //         if(temp[0] == target){
    //             answer++;
    //         }
    //         continue;
    //     }
        
    //     temp[1]++;
    //     temp[2] = 0;
    //     st.push_back(temp);
    //     temp[2] = 1;
    //     st.push_back(temp);   
    // }
    
    return answer;
}